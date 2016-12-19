/////////////////////////////////////////////////////////////////////////////
// Name:        life.cpp
// Purpose:     The game of Life, created by J. H. Conway
// Author:      Guillermo Rodriguez Garcia, <guille@iies.es>
// Modified by:
// Created:     Jan/2000
// Copyright:   (c) 2000, Guillermo Rodriguez Garcia
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

// ==========================================================================
// headers, declarations, constants
// ==========================================================================

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

// #include "wx/statline.h"
// #include "wx/wfstream.h"
// #include "wx/filedlg.h"
// #include "wx/stockitem.h"
// #include "wx/dcbuffer.h"

#include "life.h"
// #include "game.h"
#include "dialogs.h"
// #include "reader.h"

// --------------------------------------------------------------------------
// resources
// --------------------------------------------------------------------------

#if defined(__WXGTK__) || defined(__WXMOTIF__) || defined(__WXMAC__) || defined(__WXMGL__) || defined(__WXX11__)
    // application icon
    #include "mondrian.xpm"

    // bitmap buttons for the toolbar
    #include "bitmaps/reset.xpm"
    #include "bitmaps/open.xpm"
    #include "bitmaps/play.xpm"
    #include "bitmaps/stop.xpm"
    #include "bitmaps/info.xpm"

#endif

// --------------------------------------------------------------------------
// constants
// --------------------------------------------------------------------------

// IDs for the controls and the menu commands. Exluding those already defined
// by wxWidgets, such as wxID_NEW.
enum
{
    // timer
    ID_TIMER = wxID_HIGHEST,

    // file menu
    ID_NEW,

    // view menu
    ID_INFO,

    // game menu
    ID_START,
    ID_STEP,
    ID_TOPSPEED,

    // speed selection slider
    ID_SLIDER
};

// --------------------------------------------------------------------------
// event tables and other macros for wxWidgets
// --------------------------------------------------------------------------

// Event tables
wxBEGIN_EVENT_TABLE(LifeFrame, wxFrame)
    EVT_MENU            (ID_NEW,     LifeFrame::OnNewGame)
    EVT_MENU            (wxID_ABOUT,   LifeFrame::OnMenu)
    EVT_MENU            (wxID_EXIT,    LifeFrame::OnMenu)
    EVT_MENU            (ID_INFO,      LifeFrame::OnMenu)
    EVT_MENU            (ID_START,     LifeFrame::OnMenu)
    EVT_MENU            (ID_STEP,      LifeFrame::OnMenu)
    EVT_MENU            (wxID_STOP,    LifeFrame::OnMenu)
    EVT_MENU            (ID_TOPSPEED,  LifeFrame::OnMenu)
    EVT_COMMAND_SCROLL  (ID_SLIDER,    LifeFrame::OnSlider)
    EVT_TIMER           (ID_TIMER,     LifeFrame::OnTimer)
    EVT_CLOSE           (              LifeFrame::OnClose)
wxEND_EVENT_TABLE()



BEGIN_EVENT_TABLE(BasicDrawPane, wxPanel)
// some useful events
/*
 EVT_MOTION(BasicDrawPane::mouseMoved)
 EVT_LEFT_DOWN(BasicDrawPane::mouseDown)
 EVT_LEFT_UP(BasicDrawPane::mouseReleased)
 EVT_RIGHT_DOWN(BasicDrawPane::rightClick)
 EVT_LEAVE_WINDOW(BasicDrawPane::mouseLeftWindow)
 EVT_KEY_DOWN(BasicDrawPane::keyPressed)
 EVT_KEY_UP(BasicDrawPane::keyReleased)
 EVT_MOUSEWHEEL(BasicDrawPane::mouseWheelMoved)
 */
 
// catch paint events
EVT_PAINT(BasicDrawPane::paintEvent)
 
END_EVENT_TABLE()


// Create a new application object
wxIMPLEMENT_APP(LifeApp);


// ==========================================================================
// implementation
// ==========================================================================

// some shortcuts
#define ADD_TOOL(id, bmp, tooltip, help) \
    toolBar->AddTool(id, wxEmptyString, bmp, wxNullBitmap, wxITEM_NORMAL, tooltip, help)


// --------------------------------------------------------------------------
// LifeApp
// --------------------------------------------------------------------------

// 'Main program' equivalent: the program execution "starts" here
bool LifeApp::OnInit()
{
        // create the main application window
    LifeFrame *frame = new LifeFrame();
   
    // show it
    frame->Show(true);

    // just for Motif
#ifdef __WXMOTIF__
    frame->UpdateInfoText();
#endif

    // enter the main message loop and run the app
    return true;
}

// --------------------------------------------------------------------------
// LifeFrame
// --------------------------------------------------------------------------

// frame constructor
LifeFrame::LifeFrame() :
  wxFrame( (wxFrame *) NULL, wxID_ANY, _("Life!"), wxPoint(50,50), wxSize(800, 600) )/*,
  m_navigator(NULL)*/
{
    // frame icon
    SetIcon(wxICON(mondrian));

    // menu bar
    wxMenu *menuFile = new wxMenu(wxMENU_TEAROFF);
    wxMenu *menuGame = new wxMenu(wxMENU_TEAROFF);
    wxMenu *menuHelp = new wxMenu(wxMENU_TEAROFF);

    menuFile->Append(ID_NEW, _("&New Game\tCtrl-N"), _("Start a new game"));
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);


    menuGame->Append(ID_START, _("&Start\tAlt-S"), _("Start"));
    menuGame->Append(ID_STEP, _("&Next\tAlt-N"), _("Single step"));
    menuGame->Append(wxID_STOP, wxEmptyString, _("Stop"));
    menuGame->Enable(wxID_STOP, false);
    menuGame->AppendSeparator();
    menuGame->Append(ID_TOPSPEED, _("T&op speed!"), _("Go as fast as possible"));

    menuHelp->Append(wxID_ABOUT, _("&About\tCtrl-A"), _("Show about dialog"));

    wxMenuBar *menuBar = new wxMenuBar();
    menuBar->Append(menuFile, _("&File"));
    menuBar->Append(menuGame, _("&Game"));
    menuBar->Append(menuHelp, _("&Help"));
    SetMenuBar(menuBar);

    // tool bar
    wxBitmap tbBitmaps[6];

    tbBitmaps[0] = wxBITMAP(reset);
    tbBitmaps[1] = wxBITMAP(info);
    tbBitmaps[2] = wxBITMAP(play);
    tbBitmaps[3] = wxBITMAP(stop);

    wxToolBar *toolBar = CreateToolBar();
    toolBar->SetMargins(5, 5);
    toolBar->SetToolBitmapSize(wxSize(16, 16));

    ADD_TOOL(ID_NEW, tbBitmaps[0], _("New Game"), _("Start a new game"));

    toolBar->AddSeparator();
    ADD_TOOL(wxID_ABOUT, tbBitmaps[1], _("Description"), _("Show description"));
    toolBar->AddSeparator();
    ADD_TOOL(ID_START, tbBitmaps[2], _("Start"), _("Start"));
    ADD_TOOL(wxID_STOP, tbBitmaps[3], _("Stop"), _("Stop"));

    toolBar->Realize();
    toolBar->EnableTool(wxID_STOP, false);    // must be after Realize() !

#if wxUSE_STATUSBAR
    // status bar
    CreateStatusBar(2);
    SetStatusText(_("Bienvenue dans le jeu de la vie!"));
#endif // wxUSE_STATUSBAR

    // game and timer
 
    m_timer    = new wxTimer(this, ID_TIMER);
    m_running  = false;
    m_topspeed = false;
    m_interval = 500;
    m_tics     = 0;

    // We use two different panels to reduce flicker in wxGTK, because
    // some widgets (like wxStaticText) don't have their own X11 window,
    // and thus updating the text would result in a refresh of the canvas
    // if they belong to the same parent.

   




    wxPanel *panel1 = new wxPanel(this, wxID_ANY, wxPoint(1, 1), wxSize(800, 600));
    wxPanel *panel2 = new wxPanel(this, wxID_ANY);

    drawPane = new BasicDrawPane( panel1);
    drawPane->pluginManager = new PluginManager();
    drawPane->grid = new Grid(20,20,5);
    drawPane->cellsize = 6; 
    drawPane->m_tailleX = 100;
    drawPane->m_tailleY = 100;



 // info panel
    m_text = new wxStaticText(panel2, wxID_ANY,
        wxEmptyString,
        wxDefaultPosition,
        wxDefaultSize,
        wxALIGN_CENTER | wxST_NO_AUTORESIZE);

    wxSlider *slider = new wxSlider(panel2, ID_SLIDER,
        5, 1, 10,
        wxDefaultPosition,
        wxSize(200, wxDefaultCoord),
        wxSL_HORIZONTAL | wxSL_AUTOTICKS);

    UpdateInfoText();

    // component layout
    wxBoxSizer *sizer1 = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer *sizer2 = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer *sizer3 = new wxBoxSizer(wxVERTICAL);

    sizer1->Add( drawPane, 1, wxGROW | wxALL, 2 );

    panel1->SetSizer( sizer1 );
    sizer1->Fit( panel1 );

    sizer2->Add( m_text, 0, wxGROW | wxTOP, 4 );
    sizer2->Add( slider, 0, wxCENTRE | wxALL, 4 );

    panel2->SetSizer( sizer2 );
    sizer2->Fit( panel2 );

    sizer3->Add( panel1, 1, wxGROW );
    sizer3->Add( panel2, 0, wxGROW );
    SetSizer( sizer3 );

    sizer3->Fit( this );

    // set minimum frame size
    sizer3->SetSizeHints( this );

}

LifeFrame::~LifeFrame()
{
   // delete m_timer;
}

void LifeFrame::UpdateInfoText()
{
    wxString msg;

    msg.Printf(_(" Generation: %lu (T: %lu ms)"),
               m_tics,
               m_topspeed? 0 : m_interval);
    m_text->SetLabel(msg);
}




// Enable or disable tools and menu entries according to the current
// state. See also wxEVT_UPDATE_UI events for a slightly different
// way to do this.
void LifeFrame::UpdateUI()
{
    // start / stop
    GetToolBar()->EnableTool(ID_START, !m_running);
    GetToolBar()->EnableTool(wxID_STOP,  m_running);
    GetMenuBar()->Enable(ID_START, !m_running);
    GetMenuBar()->Enable(ID_STEP,  !m_running);
    GetMenuBar()->Enable(wxID_STOP,  m_running);
    GetMenuBar()->Enable(ID_TOPSPEED, !m_topspeed);

    // zooming
   // int cellsize = m_canvas->GetCellSize();
    // GetToolBar()->EnableTool(wxID_ZOOM_IN,  cellsize < 32);
    // GetToolBar()->EnableTool(wxID_ZOOM_OUT, cellsize > 1);
    // GetMenuBar()->Enable(wxID_ZOOM_IN,  cellsize < 32);
    // GetMenuBar()->Enable(wxID_ZOOM_OUT, cellsize > 1);
}

// Event handlers -----------------------------------------------------------

// OnMenu handles all events which don't have their own event handler
void LifeFrame::OnMenu(wxCommandEvent& event)
{
    switch (event.GetId())
    {
        case wxID_ABOUT:
        {
            LifeAboutDialog dialog(this);
            dialog.ShowModal();
            break;
        }
        case wxID_EXIT:
        {
            // true is to force the frame to close
            Close(true);
            break;
        }
        case ID_START   : /*OnStart();*/ break;
        case ID_STEP    : OnStep(); break;
        case wxID_STOP  : /*OnStop();*/ break;
        case ID_TOPSPEED:
        {
            // m_running = true;
            // m_topspeed = true;
            // UpdateUI();
            
            // const long YIELD_INTERVAL = 1000 / 30;
            // wxMilliClock_t lastyield = 0, now;
            
            // while (m_running && m_topspeed)
            // {
            //     OnStep();
            //     if ( (now=wxGetLocalTimeMillis()) - lastyield > YIELD_INTERVAL)
            //     {
            //         wxYield();
            //         lastyield = now;
            //     }
            // }
 
            break;
        }
    }
}

void LifeFrame::OnNewGame(wxCommandEvent& WXUNUSED(event)){

        // stop if it was running
    //OnStop();

    // dialog box
    NewGameDialog dialog(this);

    if (dialog.ShowModal() == wxID_OK)
    {
        
        drawPane->m_tailleX = dialog.GetTailleX();
        drawPane->m_tailleY = dialog.GetTailleY();

       	delete(drawPane->grid); 
        drawPane->grid = new Grid(drawPane->m_tailleX,drawPane->m_tailleY,30);

        drawPane->paintNow();
        m_tics = 0;
        UpdateInfoText();

    }
}


void LifeFrame::OnSlider(wxScrollEvent& event)
{
    m_interval = event.GetPosition() * 100;

    // if (m_running)
    // {
    //     OnStop();
    //     OnStart();
    // }

    UpdateInfoText();
}

void LifeFrame::OnTimer(wxTimerEvent& WXUNUSED(event))
{
  //  OnStep();
}

void LifeFrame::OnClose(wxCloseEvent& WXUNUSED(event))
{
    // Stop if it was running; this is absolutely needed because
    // the frame won't be actually destroyed until there are no
    // more pending events, and this in turn won't ever happen
    // if the timer is running faster than the window can redraw.
   // OnStop();
    Destroy();
}

// void LifeFrame::OnStart()
// {
//     if (!m_running)
//     {
//         m_timer->Start(m_interval);
//         m_running = true;
//         UpdateUI();
//     }
// }

// void LifeFrame::OnStop()
// {
//     // if (m_running)
//     // {
//     //     m_timer->Stop();
//     //     m_running = false;
//     //     m_topspeed = false;
//     //     UpdateUI();
//     // }
// }

void LifeFrame::OnStep()
{
	drawPane->pluginManager->getNextGen(drawPane->grid);

	m_tics++;

	drawPane->paintNow();
	UpdateInfoText();



    // if (m_life->NextTic())
    // {
    //     m_tics++;
    //     m_canvas->Refresh();
    //     UpdateInfoText();
    // }
    // else
    //     OnStop();
}

 Grid* BasicDrawPane::getGrid(){

 	return grid;
 }


PluginManager* BasicDrawPane::getPluginManager(){

	return pluginManager;
}

BasicDrawPane::BasicDrawPane(wxWindow* parent) :
wxPanel(parent)
{
}



/*
 * Called by the system of by wxWidgets when the panel needs
 * to be redrawn. You can also trigger this call by
 * calling Refresh()/Update().
 */
 
void BasicDrawPane::paintEvent(wxPaintEvent & evt)
{
    wxPaintDC dc(this);
    render(dc);
}
 
/*
 * Alternatively, you can use a clientDC to paint on the panel
 * at any time. Using this generally does not free you from
 * catching paint events, since it is possible that e.g. the window
 * manager throws away your drawing when the window comes to the
 * background, and expects you will redraw it when the window comes
 * back (by sending a paint event).
 *
 * In most cases, this will not be needed at all; simply handling
 * paint events and calling Refresh() when a refresh is needed
 * will do the job.
 */
void BasicDrawPane::paintNow()
{
    wxClientDC dc(this);
    render(dc);
}
 
/*
 * Here we do the actual rendering. I put it in a separate
 * method so that it can work no matter what type of DC
 * (e.g. wxPaintDC or wxClientDC) is used.
 */
void BasicDrawPane::render(wxDC&  dc)
{

     dc.SetBrush(*wxWHITE_BRUSH); // blue filling
     dc.SetPen(*wxBLACK_PEN);

     m_tailleX = grid->sizeRows();
     m_tailleY = grid->sizeColumns();

     int pion;

     if (m_tailleX <= 20 && m_tailleY <= 20){

        cellsize = 18;

     } else {

         if (m_tailleX <= 40 && m_tailleY <= 40){

            cellsize = 14;

         } else {

                if(m_tailleX <= 60 && m_tailleY <= 60){

                    cellsize = 10;

                } else {

                        if (m_tailleX <= 80 && m_tailleY <= 80){

                            cellsize = 7;
                        } else {

                            cellsize = 6;
                        }
                }
         }
    }





    int scale = cellsize;
    for (int k = 0; k < m_tailleX; k++){
        for (int j= 0; j < m_tailleY; j++){

            // if (j%2 == 1){
            //     dc.SetBrush(*wxBLACK_BRUSH);

            // } else {

            //     dc.SetBrush(*wxWHITE_BRUSH);
            // }

        	pion = grid->getCellAtIndex(k,j)->getPion();

        	switch(pion){

        		case 0: 
        				 dc.SetBrush(*wxWHITE_BRUSH);
        		break;

        		case 1:
        				 dc.SetBrush(*wxBLACK_BRUSH);
        		break;

        		case 2:
        				 dc.SetBrush(*wxBLUE_BRUSH);
        		break;


        		case 3:
        				 dc.SetBrush(*wxRED_BRUSH);
        		break;


        		case 4:
        				 dc.SetBrush(*wxGREEN_BRUSH);
        		break;



        		case 5:
        				 dc.SetBrush(*wxYELLOW_BRUSH);
        		break; 
        				 
        		default:
        				dc.SetBrush(*wxBLACK_BRUSH);

        	}


            dc.DrawRectangle(k*scale, j*scale, cellsize, cellsize);
        }
       
    }
}
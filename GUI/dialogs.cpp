/////////////////////////////////////////////////////////////////////////////
// Name:        life/dialogs.cpp
// Purpose:     Life! dialogs
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

#include "wx/statline.h"
#include "wx/minifram.h"
#include "wx/settings.h"

// #include "dialogs.h"
//#include "life.h"
//#include "game.h"


// --------------------------------------------------------------------------
// resources
// --------------------------------------------------------------------------

#include "bitmaps/life.xpm"

// sample configurations
// #include "samples.inc"

// --------------------------------------------------------------------------
// constants
// --------------------------------------------------------------------------

// IDs for the controls and the menu commands
enum
{
    // listbox in samples dialog
    ID_LISTBOX,
    ID_CLOSE,
    ID_CHOIX1,
    ID_CHOIX2,
    ID_CHOIX3,
    ID_SLIDERDIALOG1,
    ID_SLIDERDIALOG2


};


// --------------------------------------------------------------------------
// event tables and other macros for wxWidgets
// --------------------------------------------------------------------------

// Event tables
wxBEGIN_EVENT_TABLE(NewGameDialog, wxDialog)
    EVT_LISTBOX (ID_LISTBOX, NewGameDialog::OnListBox)
    EVT_RADIOBUTTON (ID_CHOIX1, NewGameDialog::OnChoix1)
    EVT_RADIOBUTTON (ID_CHOIX2, NewGameDialog::OnChoix2)
    EVT_RADIOBUTTON (ID_CHOIX3, NewGameDialog::OnChoix3)
    EVT_COMMAND_SCROLL  (ID_SLIDERDIALOG1,    NewGameDialog::OnSliderDialog1)
    EVT_COMMAND_SCROLL  (ID_SLIDERDIALOG2,    NewGameDialog::OnSliderDialog2)
wxEND_EVENT_TABLE()



// ==========================================================================
// implementation
// ==========================================================================

// --------------------------------------------------------------------------
// NewGameDialog
// --------------------------------------------------------------------------

NewGameDialog::NewGameDialog(wxWindow *parent)
                 : wxDialog(parent, wxID_ANY, _("New Game"),
                            wxDefaultPosition, wxDefaultSize)
{

    wxPanel *panel = new wxPanel(this, -1);

  wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);

  wxStaticBox *st = new wxStaticBox(panel, -1, wxT("Plugins"), 
      wxPoint(5, 5), wxSize(240, 150));

    wxRadioButton *rb0 = new wxRadioButton(panel, -1, 
      wxT("Ne rien faire"), wxPoint(15, 30), wxDefaultSize, wxRB_GROUP);
  wxRadioButton *rb1 = new wxRadioButton(panel, ID_CHOIX1, 
      wxT("Plugin 1"), wxPoint(15, 55));

  wxRadioButton *rb2 = new wxRadioButton(panel, ID_CHOIX2, 
      wxT("Plugin 2"), wxPoint(15, 80));
  wxRadioButton *rb3 = new wxRadioButton(panel, ID_CHOIX3, 
      wxT("Plugin 3"), wxPoint(15, 105));
 /* wxRadioButton *rb3 = new wxRadioButton(panel, -1, 
      wxT("Custom"), wxPoint(15, 105));
  wxTextCtrl *tc = new wxTextCtrl(panel, -1, wxT(""), 
      wxPoint(95, 105));*/

  // wxButton *okButton = new wxButton(this, -1, wxT("Ok"), 
  //     wxDefaultPosition, wxSize(70, 30));
  // wxButton *closeButton = new wxButton(this, wxCANCEL, wxT("cHANGER"), 
  //     wxDefaultPosition, wxSize(70, 30));

  wxSizer *sizerBtns = CreateButtonSizer(wxOK|wxCANCEL);
    if ( sizerBtns )
    {
        hbox->Add(sizerBtns, wxSizerFlags().Expand().Border());
   }

 //wxPanel *panel2 = new wxPanel(this, -1);


   wxStaticBox *st1 = new wxStaticBox(panel, -1, wxT("Taille"), 
      wxPoint(5, 160), wxSize(240, 75));

   tailleX = 50;
   tailleY = 50;


    text_taille = new wxStaticText(panel, wxID_ANY,
        wxEmptyString,
        wxPoint(125,185),
        wxSize(100,100),
        wxALIGN_CENTER | wxST_NO_AUTORESIZE);
   // wxALIGN_CENTER | wxST_NO_AUTORESIZE);

    UpdateInfoTextDialog();


    slider1 = new wxSlider(panel, ID_SLIDERDIALOG1,
        50, 20, 100,
        wxPoint(15,185),
        wxSize(100, wxDefaultCoord),
        wxSL_HORIZONTAL | wxSL_AUTOTICKS);

    slider2 = new wxSlider(panel, ID_SLIDERDIALOG2,
        50, 20, 100,
        wxPoint(15,205),
        wxSize(100, wxDefaultCoord),
        wxSL_HORIZONTAL | wxSL_AUTOTICKS);



   // slider = new wxSlider(this, ID_SLIDERDIALOG, 50, 0, 100, wxPoint(15, 185), 
   //      wxSize(1, 100), wxSL_HORIZONTAL);
 /* wxTextCtrl *tc = new wxTextCtrl(panel2, -1, wxT(""), 
      wxPoint(95, 105));
   wxTextCtrl *tc = new wxTextCtrl(panel2, -1, wxT(""), 
      wxPoint(140, 135));*/



  // hbox->Add(okButton, 1);
  // hbox->Add(closeButton, 1, wxLEFT, 5);

  vbox->Add(panel, 1);
  //vbox->Add(panel2, 1);
  vbox->Add(hbox, 0, wxALIGN_CENTER | wxTOP | wxBOTTOM, 10);



  SetSizer(vbox);

  Centre();
  ShowModal();

  Destroy(); 











//     m_value = 0;

//     wxSize listSize = wxDefaultSize;
//     bool isPDA = wxSystemSettings::GetScreenType() <= wxSYS_SCREEN_PDA;

//     // Screens are generally horizontal in orientation,
//     // but PDAs are generally vertical.
//     bool screenIsHorizontal = true;
//     if (isPDA &&
//         wxSystemSettings::GetMetric(wxSYS_SCREEN_X) < wxSystemSettings::GetMetric(wxSYS_SCREEN_Y))
//     {
//         listSize = wxSize(wxDefaultCoord, 50);
//         screenIsHorizontal = false;
//     }

//     // create and populate the list of available samples
//     m_list = new wxListBox( this, ID_LISTBOX,
//         wxDefaultPosition,
//         listSize,
//         0, NULL,
//         wxLB_SINGLE | wxLB_NEEDED_SB | wxLB_HSCROLL );

//     for (unsigned i = 0; i < (sizeof(g_patterns) / sizeof(LifePattern)); i++)
//         m_list->Append(g_patterns[i].m_name);

//     // descriptions
//     wxStaticBox *statbox = new wxStaticBox( this, wxID_ANY, _("Description"));
//     m_life   = new Life();
//     m_life->SetPattern(g_patterns[0]);
//     m_canvas = new LifeCanvas( this, m_life, false );
//     m_text   = new wxTextCtrl( this, wxID_ANY,
//         g_patterns[0].m_description,
//         wxDefaultPosition,
//         wxSize(300, 60),
//         wxTE_MULTILINE | wxTE_READONLY);

//     // layout components

//     wxStaticBoxSizer *sizer1 = new wxStaticBoxSizer( statbox, wxVERTICAL );
//     sizer1->Add( m_canvas, 2, wxGROW | wxALL, 5);
//     sizer1->Add( m_text, 1, wxGROW | wxALL, 5 );

//     wxBoxSizer *sizer2 = new wxBoxSizer( screenIsHorizontal ? wxHORIZONTAL : wxVERTICAL );
//     sizer2->Add( m_list, 0, wxGROW | wxALL, 5 );
//     sizer2->Add( sizer1, 1, wxGROW | wxALL, 5 );

//     wxBoxSizer *sizer3 = new wxBoxSizer( wxVERTICAL );
//     sizer3->Add( CreateTextSizer(_("Select a configuration")), 0, wxALL|wxCENTRE, isPDA ? 2 : 10 );
// #if wxUSE_STATLINE
//     if (!isPDA)
//         sizer3->Add( new wxStaticLine(this, wxID_ANY), 0, wxGROW | wxLEFT | wxRIGHT, 10 );
// #endif // wxUSE_STATLINE
//     sizer3->Add( sizer2, 1, wxGROW | wxALL, 5 );

//     wxSizer *sizerBtns = CreateButtonSizer(wxOK|wxCANCEL);
//     if ( sizerBtns )
//     {
//         sizer3->Add(sizerBtns, wxSizerFlags().Expand().Border());
//     }

//     // activate
//     SetSizer(sizer3);
//     sizer3->SetSizeHints(this);
//     sizer3->Fit(this);
//     Centre(wxBOTH | wxCENTRE_ON_SCREEN);

}

NewGameDialog::~NewGameDialog()
{
    //m_canvas->Destroy();
}

// const LifePattern& NewGameDialog::GetPattern()
// {
//     return g_patterns[m_value];
// }


void NewGameDialog::UpdateInfoTextDialog()
{
    wxString msg;

    msg.Printf(_(" TailleX: %lu  TailleY: %lu "),
            tailleX,
            tailleY);
    text_taille->SetLabel(msg);

    /*    msg.Printf(_(" Generation: %lu (T: %lu ms)"),
               m_tics,
               m_topspeed? 0 : m_interval);
    m_text->SetLabel(msg);*/
}

void NewGameDialog::OnSliderDialog1(wxScrollEvent& event)
{
    tailleX = event.GetPosition();

    // if (m_running)
    // {
    //     OnStop();
    //     OnStart();
    // }

   UpdateInfoTextDialog();
}

void NewGameDialog::OnSliderDialog2(wxScrollEvent& event)
{
    tailleY = event.GetPosition();

    // if (m_running)
    // {
    //     OnStop();
    //     OnStart();
    // }

    UpdateInfoTextDialog();
}

void NewGameDialog::OnListBox(wxCommandEvent& event)
{
    // int sel = event.GetSelection();

    // if (sel != -1)
    // {
    //     m_value = m_list->GetSelection();
    //     m_text->SetValue(g_patterns[ sel ].m_description);
    //     m_life->SetPattern(g_patterns[ sel ]);

    //     // these values shouldn't be hardcoded...
    //     if ((size_t)sel < (sizeof(g_patterns) / sizeof(LifePattern)) - 3)
    //         m_canvas->SetCellSize(8);
    //     else
    //         m_canvas->SetCellSize(2);
    // }
}

void NewGameDialog::OnExit( wxCommandEvent& event )
{
    wxLogMessage("Les chevaux c'est super!");
    /*Close(TRUE);
    std::cout << "youhou" ; // Tells the OS to quit running this process*/
}


void NewGameDialog::OnChoix1( wxCommandEvent& event )
{
    wxLogMessage("Le choix1");
}

void NewGameDialog::OnChoix2( wxCommandEvent& event )
{
    wxLogMessage("Le choix2");
}

void NewGameDialog::OnChoix3( wxCommandEvent& event )
{
    wxLogMessage("Le choix3");
}
// --------------------------------------------------------------------------
// LifeAboutDialog
// --------------------------------------------------------------------------

LifeAboutDialog::LifeAboutDialog(wxWindow *parent)
               : wxDialog(parent, wxID_ANY, _("About Life!"),
                          wxDefaultPosition, wxDefaultSize)
{
    // logo
    wxStaticBitmap *sbmp = new wxStaticBitmap(this, wxID_ANY, wxBitmap(life_xpm));

    // layout components
    wxBoxSizer *sizer = new wxBoxSizer( wxVERTICAL );
    sizer->Add( sbmp, 0, wxCENTRE | wxALL, 10 );
#if wxUSE_STATLINE
    sizer->Add( new wxStaticLine(this, wxID_ANY), 0, wxGROW | wxLEFT | wxRIGHT, 5 );
#endif // wxUSE_STATLINE
    sizer->Add( CreateTextSizer(_("Game of Life version 1.0 for Concept et Outils de developpements\n\n\
Laurent - Killian - Aurelien - Theo - Gilles - Vincent - Andrei\n\n\
Portions of the code are based in demos of life in wxWidgets.")),
                                  0, wxCENTRE | wxRIGHT|wxLEFT|wxTOP, 20 );

//     sizer->Add( CreateTextSizer(_("Game of Life version 1.0 for Concept et Outils de developpement\n\n\
// Laurent  Killian  Aurélien  Théo  Gilles  Vincent  Andrei\n\n\
// <guille@iies.es>\n\n\
// Portions of the code are based in demos of life in wxWidgets;\n\
// XLife is (c) 1989 by Jon Bennett et al.")),
//                                   0, wxCENTRE | wxRIGHT|wxLEFT|wxTOP, 20 );
    // buttons if any
    wxSizer *sizerBtns = CreateButtonSizer(wxOK);
    if ( sizerBtns )
    {
        sizer->Add(sizerBtns, wxSizerFlags().Expand().Border());
    }

    // activate
    SetSizer(sizer);
    sizer->SetSizeHints(this);
    sizer->Fit(this);
    Centre(wxBOTH | wxCENTRE_ON_SCREEN);
}



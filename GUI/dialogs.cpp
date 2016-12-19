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

#include "dialogs.h"

#include "wx/statline.h"
#include "wx/minifram.h"
#include "wx/settings.h"

// --------------------------------------------------------------------------
// resources
// --------------------------------------------------------------------------

#include "bitmaps/life.xpm"

// --------------------------------------------------------------------------
// constants
// --------------------------------------------------------------------------

// IDs for the controls and the menu commands
enum
{
    // listbox in samples dialog
    ID_CHOIX1,
    ID_CHOIX2,
    ID_SLIDERDIALOG1,
    ID_SLIDERDIALOG2,
    ID_SLIDERDIALOG3


};


// --------------------------------------------------------------------------
// event tables and other macros for wxWidgets
// --------------------------------------------------------------------------

// Event tables
wxBEGIN_EVENT_TABLE(NewGameDialog, wxDialog)
    EVT_RADIOBUTTON (ID_CHOIX1, NewGameDialog::OnChoix1)
    EVT_RADIOBUTTON (ID_CHOIX2, NewGameDialog::OnChoix2)
    EVT_COMMAND_SCROLL  (ID_SLIDERDIALOG1,    NewGameDialog::OnSliderDialog1)
    EVT_COMMAND_SCROLL  (ID_SLIDERDIALOG2,    NewGameDialog::OnSliderDialog2)
    EVT_COMMAND_SCROLL  (ID_SLIDERDIALOG3,    NewGameDialog::OnSliderDialog3)
wxEND_EVENT_TABLE()



// ==========================================================================
// implementation
// ==========================================================================

// --------------------------------------------------------------------------
// NewGameDialog
// --------------------------------------------------------------------------

NewGameDialog::NewGameDialog(wxWindow *parent)
                 : wxDialog(parent, wxID_ANY, _("New Game"),
                            wxDefaultPosition, wxSize(270,330))
{

    wxPanel *panel = new wxPanel(this, -1);
    pluginPath = "./plugins/PluginBase.so";

  wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);

  wxStaticBox *st = new wxStaticBox(panel, -1, wxT("Plugins"), 
      wxPoint(5, 5), wxSize(260, 150));

    wxRadioButton *rb0 = new wxRadioButton(panel, -1, 
      wxT("Jeu de base"), wxPoint(15, 30), wxDefaultSize, wxRB_GROUP);
  wxRadioButton *rb1 = new wxRadioButton(panel, ID_CHOIX1, 
      wxT("Inondation"), wxPoint(15, 55));

  wxRadioButton *rb2 = new wxRadioButton(panel, ID_CHOIX2, 
      wxT("PluginLife"), wxPoint(15, 80));


  wxSizer *sizerBtns = CreateButtonSizer(wxOK|wxCANCEL);
    if ( sizerBtns )
    {
        hbox->Add(sizerBtns, wxSizerFlags().Expand().Border());
   }


   wxStaticBox *st1 = new wxStaticBox(panel, -1, wxT("Taille"), 
      wxPoint(5, 160), wxSize(260, 95));

   tailleX = 50;
   tailleY = 50;
   pourcentage = 50;


    text_taille = new wxStaticText(panel, wxID_ANY,
        wxEmptyString,
        wxPoint(125,185),
        wxSize(125,200),
        wxALIGN_CENTER | wxST_NO_AUTORESIZE);

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

    slider3 = new wxSlider(panel, ID_SLIDERDIALOG3,
        50, 1, 100,
        wxPoint(15,225),
        wxSize(100, wxDefaultCoord),
        wxSL_HORIZONTAL | wxSL_AUTOTICKS);


  vbox->Add(panel, 1);
  vbox->Add(hbox, 0, wxALIGN_CENTER | wxTOP | wxBOTTOM, 10);



  SetSizer(vbox);

  Centre();

}

NewGameDialog::~NewGameDialog()
{
    
}


void NewGameDialog::UpdateInfoTextDialog()
{
    wxString msg;
    /// TO DO
    msg.Printf(_(" TailleX: %lu  TailleY: %lu Pourcentage de vivants: %lu"),
            tailleX,
            tailleY,
            pourcentage);
    text_taille->SetLabel(msg);
}

void NewGameDialog::OnSliderDialog1(wxScrollEvent& event)
{
    tailleX = event.GetPosition();

   UpdateInfoTextDialog();
}

void NewGameDialog::OnSliderDialog2(wxScrollEvent& event)
{
    tailleY = event.GetPosition();

    UpdateInfoTextDialog();
}

void NewGameDialog::OnSliderDialog3(wxScrollEvent& event)
{
    pourcentage = event.GetPosition();

    UpdateInfoTextDialog();
}

void NewGameDialog::OnChoix1( wxCommandEvent& event )
{
	pluginPath = "./plugins/PluginWar.so";
    wxLogMessage("Des geysers sont apparus ! Fuyez !!");
}

void NewGameDialog::OnChoix2( wxCommandEvent& event )
{
    pluginPath = "./plugins/PluginLife.so";
    wxLogMessage("Il est joli");
}

long NewGameDialog::GetTailleX()
{
    return tailleX;
}

long NewGameDialog::GetTailleY()
{
    return tailleY;
}

long NewGameDialog::GetPourcentage()
{
    return pourcentage;
}

std::string NewGameDialog::getPluginPath()
{
	return pluginPath;
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
Laurent - Killian - Aurelien - Theo - Gilles - Vincent - Andrei - Saad \n\n\
Portions of the code are based in demos of life in wxWidgets.")),
                                  0, wxCENTRE | wxRIGHT|wxLEFT|wxTOP, 20 );


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



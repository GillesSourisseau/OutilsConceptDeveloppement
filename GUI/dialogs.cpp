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
                            wxDefaultPosition, wxSize(250,300))
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

  wxSizer *sizerBtns = CreateButtonSizer(wxOK|wxCANCEL);
    if ( sizerBtns )
    {
        hbox->Add(sizerBtns, wxSizerFlags().Expand().Border());
   }


   wxStaticBox *st1 = new wxStaticBox(panel, -1, wxT("Taille"), 
      wxPoint(5, 160), wxSize(240, 75));

   tailleX = 50;
   tailleY = 50;


    text_taille = new wxStaticText(panel, wxID_ANY,
        wxEmptyString,
        wxPoint(125,185),
        wxSize(100,100),
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





  // hbox->Add(okButton, 1);
  // hbox->Add(closeButton, 1, wxLEFT, 5);

  vbox->Add(panel, 1);
  vbox->Add(hbox, 0, wxALIGN_CENTER | wxTOP | wxBOTTOM, 10);



  SetSizer(vbox);

  Centre();
  ShowModal();

  Destroy(); 







}

NewGameDialog::~NewGameDialog()
{
    
}



void NewGameDialog::UpdateInfoTextDialog()
{
    wxString msg;

    msg.Printf(_(" TailleX: %lu  TailleY: %lu "),
            tailleX,
            tailleY);
    text_taille->SetLabel(msg);

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



/////////////////////////////////////////////////////////////////////////////
// Name:        dialogs.h
// Purpose:     Life! dialogs
// Author:      Guillermo Rodriguez Garcia, <guille@iies.es>
// Modified by:
// Created:     Jan/2000
// Copyright:   (c) 2000, Guillermo Rodriguez Garcia
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#ifndef _LIFE_DIALOGS_H_
#define _LIFE_DIALOGS_H_

// #include "life.h"
//#include "game.h"


// --------------------------------------------------------------------------
// NewGameDialog
// --------------------------------------------------------------------------

class NewGameDialog : public wxDialog
{
public:
    // ctor and dtor
    NewGameDialog(wxWindow *parent);
    virtual ~NewGameDialog();

    // event handlers
    void OnChoix1(wxCommandEvent &event);
    void OnChoix2(wxCommandEvent &event);
    void OnChoix3(wxCommandEvent &event);
    void UpdateInfoTextDialog();
    void OnSliderDialog1(wxScrollEvent&  event);
    void OnSliderDialog2(wxScrollEvent&  event);
    void OnSliderDialog3(wxScrollEvent&  event);
    long GetTailleX();
    long GetTailleY();
    long GetPourcentage();



private:
    // any class wishing to process wxWidgets events must use this macro
    wxDECLARE_EVENT_TABLE();

    wxSlider    *slider1;
    wxSlider    *slider2;
    wxSlider    *slider3;
    wxStaticText *text_taille;
    long        tailleX;
    long         tailleY;
    long		pourcentage;
    int         m_value;
    wxListBox  *m_list;
    wxTextCtrl *m_text;
    // LifeCanvas *m_canvas;
    // Life       *m_life;
};

// --------------------------------------------------------------------------
// LifeAboutDialog
// --------------------------------------------------------------------------

class LifeAboutDialog : public wxDialog
{
public:
    // ctor
    LifeAboutDialog(wxWindow *parent);
};


#endif  // _LIFE_DIALOGS_H_

#include "dialogs.cpp"
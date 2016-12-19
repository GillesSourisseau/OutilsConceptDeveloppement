#ifndef DIALOGS_H_
#define DIALOGS_H_

// --------------------------------------------------------------------------
// NewGameDialog
// --------------------------------------------------------------------------
/*!
 *\class NewGameDialog
 *\brief The dialog box used for the New Game Menu
 */
class NewGameDialog : public wxDialog
{
public:
    // ctor and dtor
    /*!
    * \name NewGameDialog
    * \brief The constructor of NewGameDialog.
    * \param wxWindow* : parent, The parent windows for the NewGameDialog
    */
    NewGameDialog(wxWindow *parent);
     /*!
    * \name ~NewGameDialog
    * \brief The destructor of NewGameDialog.
    */
    virtual ~NewGameDialog();

    // event handlers
    /*!
    * \name OnChoix1
    * \brief What to do when the first plugin is choosen.
    * \param wxCommandEvent : event, the event for the first plugin button.
    */
    void OnChoix1(wxCommandEvent &event);
    /*!
    * \name OnChoix2
    * \brief What to do when the second plugin is choosen.
    * \param wxCommandEvent : event, the event for the second plugin button.
    */
    void OnChoix2(wxCommandEvent &event);

    void UpdateInfoTextDialog();
    /*!
    * \name OnSliderDialog1
    * \brief What's going on when the slider for tailleX is used.
    * \param wxScrollEvent : event, the event for slider.
    */
    void OnSliderDialog1(wxScrollEvent&  event);
     /*!
    * \name OnSliderDialog2
    * \brief What's going on when the slider for tailleY is used.
    * \param wxScrollEvent : event, the event for slider.
    */
    void OnSliderDialog2(wxScrollEvent&  event);
     /*!
    * \name OnSliderDialog3
    * \brief What's going on when the slider for the pourcentage of population is used.
    * \param wxScrollEvent : event, the event for slider.
    */
    void OnSliderDialog3(wxScrollEvent&  event);
    /*!
    * \name GetTailleX
    * \brief Getter for tailleX.
    * \return long : tailleX.
    */
    long GetTailleX();
    /*!
    * \name GetTailleY
    * \brief Getter for tailleY.
    * \return long : tailleY.
    */
    long GetTailleY();
    /*!
    * \name GetPourcentage
    * \brief Getter for pourcentage.
    * \return long : pourcentage.
    */
    long GetPourcentage();
    /*!
    * \name getPluginPath
    * \brief Getter for pluginPath.
    * \return string : pluginpath.
    */
    std::string getPluginPath();




private:
    // any class wishing to process wxWidgets events must use this macro
    wxDECLARE_EVENT_TABLE();

    wxSlider    *slider1;
    wxSlider    *slider2;
    wxSlider    *slider3;
    wxStaticText *text_taille;
    long        tailleX;
    long         tailleY;
    long        pourcentage;
    int         m_value;
    std::string pluginPath;
    wxListBox  *m_list;
    wxTextCtrl *m_text;

};

// --------------------------------------------------------------------------
// LifeAboutDialog
// --------------------------------------------------------------------------
/*!
 *\class LifeAboutDialog
 *\brief The dialog box used for the About Menu
 */
class LifeAboutDialog : public wxDialog
{
public:
     /*!
    * \name LifeAbouDialog
    * \brief The constructor of LifeAboutDialog.
    * \param wxWindow* : parent, The parent windows for the LifeAboutDialog
    */
    LifeAboutDialog(wxWindow *parent);
};

#endif  // DIALOGS_H_

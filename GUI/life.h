#ifndef _LIFE_APP_H_
#define _LIFE_APP_H_

#include "wx/wx.h"
#include "wx/sizer.h"

#include "../src/PluginManager.hpp"
#include "../src/PluginService.hpp"
#include "../src/Sprite.hpp"


// --------------------------------------------------------------------------
// BasicDrawPane
// --------------------------------------------------------------------------
/*!
 *\class BasicDrawPane
 *\brief The panel used for rendering the grid.
 */
class BasicDrawPane : public wxPanel
{
 
public:
    /*!
    * \name BasicDrawPane
    * \brief The constructor of BasicDrawPane.
    * \param wxWindow* : parent, The parent windows for the BasicDrawPane
    */
    BasicDrawPane(wxWindow* parent);
    
    /*!
    * \name paintEvent
    * \brief Called by the system of by wxWidgets when the panel needs to be redrawn.
    * \param wxPaintEvent, evt : event for the painter.
    */
    void paintEvent(wxPaintEvent & evt);

    /*!
    * \name paintNow
    * \brief intialize the DCpainter.
    */
    void paintNow();
    
    /*!
    * \name render
    * \brief The constructor of BasicDrawPane.
    * \param wxDC& : dc, it's the object in wxWidgets for painting methods.
    */
    void render(wxDC& dc);

    /*!
    * \name getGrid
    * \brief Getter for the grid.
    * \return Grid*, the grid of the BasicDrawPane.
    */
    Grid* getGrid();
    /*!
    * \name getPluginManager
    * \brief Getter for the pluginManager.
    * \return PluginManager*, the pluginManager of the BasicDrawPane.
    */
    PluginManager* getPluginManager();

    int cellsize;
    long m_tailleX;
    long m_tailleY;
    long pourcentage;
    long nbPop;

    PluginManager *pluginManager;
    Grid            *grid;
    Sprite          *sprite;


 
    DECLARE_EVENT_TABLE()
};


// --------------------------------------------------------------------------
// LifeFrame
// --------------------------------------------------------------------------
/*!
 *\class LifeFrame
 *\brief The principal window for the program.
 */
class LifeFrame : public wxFrame
{
public:
    // ctor and dtor
    /*!
    * \name LifeFrame
    * \brief The constructor of LifeFrame.
    */
    LifeFrame();
    /*!
    * \name ~LifeFrame
    * \brief The destructor of LifeFrame.
    */
    virtual ~LifeFrame();

    // member functions
    /*!
    * \name UpdateInfoText
    * \brief Update the info text in the bottom of the screen with the nomber of generations, time for tics and the population.
    */
    void UpdateInfoText();
    /*!
    * \name UpdateUI
    * \brief Update the menu and the toolbar, making icons unclicakble.
    */
    void UpdateUI();
    

    BasicDrawPane *drawPane;

private:
    // any class wishing to process wxWidgets events must use this macro
    wxDECLARE_EVENT_TABLE();

    // event handlers
    /*!
    * \name OnMenu
    * \brief This method handle the events when menu buttons are clicked.
    * \param event : wxCommandEvent&, the event for the buttons in the Menu.
    */
    void OnMenu(wxCommandEvent& event);
    /*!
    * \name OnSlider
    * \brief This method handle the events when the slider is used.
    * \param event : wxScrollEvent&, the event controlled by the slider.
    */
    void OnSlider(wxScrollEvent& event);
    /*!
    * \name OnTimer
    * \brief This method is used at each tic of the Timer.
    * \param event : wxTimerEvent&, a timer event.
    */
    void OnTimer(wxTimerEvent& event);
    /*!
    * \name OnClose
    * \brief Stop if it was running; this is absolutely needed because the frame won't be actually destroyed until there are no more pending events, and this in turn won't ever happen if the timer is running faster than the window can redraw.
    * \param event : wxCloseEvent&, the event closing the game.
    */
    void OnClose(wxCloseEvent& event);
    /*!
    * \name OnStep
    * \brief Do the next Generation of population.
    */
    void OnStep();
    /*!
    * \name OnSteps
    * \brief Do multiple Generation of population.
    */
    void OnSteps();
    /*!
    * \name OnStart
    * \brief Start the game of life with the Timer.
    */
    void OnStart();
    /*!
    * \name OnStop
    * \brief Stop the game of life.
    */
    void OnStop();
    /*!
    * \name OnNewGame
    * \brief Methods used for launching a new game (reinitialisation of paramaters)
    * \param event : wxCommandEvent&, the event for the new game Menu.
    */
    void OnNewGame(wxCommandEvent& WXUNUSED(event));


    wxStaticText   *m_text;
    wxTimer        *m_timer;
    bool            m_running;
    bool            m_topspeed;
    long            m_interval;
    long            m_tics;
    long            nbPop;

};



// --------------------------------------------------------------------------
// LifeApp
// --------------------------------------------------------------------------
/*!
 *\class LifeApp
 *\brief The 'Main' program.
 */
class LifeApp : public wxApp
{
public:
    /*!
    * \name OnInit()
    * \brief  'Main program' equivalent: the program execution "starts" here
    *
    */
    virtual bool OnInit();
    wxFrame *frame;
    BasicDrawPane *drawPane;
};

#endif  // _LIFE_APP_H_





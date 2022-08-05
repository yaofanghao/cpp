/***************************************************************
 * Name:      ModelPoserMain.h
 * Purpose:   Defines Application Frame
 * Author:    Ammar Qammaz ()
 * Created:   2018-10-20
 * Copyright: Ammar Qammaz (http://ammar.gr)
 * License:
 **************************************************************/

#ifndef MODELPOSERMAIN_H
#define MODELPOSERMAIN_H

//(*Headers(ModelPoserFrame)
#include <wx/spinctrl.h>
#include <wx/button.h>
#include <wx/menu.h>
#include <wx/hyperlink.h>
#include <wx/slider.h>
#include <wx/statusbr.h>
#include <wx/statbox.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/choice.h>
#include <wx/timer.h>
//*)

#include <wx/dc.h>
#include <wx/dcclient.h>
class ModelPoserFrame: public wxFrame
{
    public:

        ModelPoserFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~ModelPoserFrame();

    private:

        //(*Handlers(ModelPoserFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnTimer1Trigger(wxTimerEvent& event);
        //*)

        //(*Identifiers(ModelPoserFrame)
        static const long ID_STATICBOX1;
        static const long ID_STATICBOX2;
        static const long ID_SLIDER1;
        static const long ID_SPINCTRL1;
        static const long ID_STATICTEXT1;
        static const long ID_CHOICE1;
        static const long ID_STATICTEXT2;
        static const long ID_SPINCTRL2;
        static const long ID_STATICTEXT3;
        static const long ID_SPINCTRL3;
        static const long ID_HYPERLINKCTRL1;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        static const long ID_TIMER1;
        //*)

        //(*Declarations(ModelPoserFrame)
        wxSpinCtrl* SpinCtrlMin;
        wxSlider* SliderPlayWithJoint;
        wxSpinCtrl* SpinCtrlInit;
        wxStatusBar* StatusBar1;
        wxStaticText* StaticText1;
        wxHyperlinkCtrl* HyperlinkCtrl1;
        wxTimer Timer1;
        wxStaticBox* StaticBox2;
        wxStaticText* StaticText3;
        wxChoice* Choice1;
        wxButton* ButtonPrev;
        wxStaticBox* StaticBox1;
        wxSpinCtrl* SpinCtrlMax;
        wxStaticText* StaticText2;
        wxButton* ButtonNext;
        //*)

        void render(wxDC& dc);
        void onIdle(wxIdleEvent& evt);
        void onPaint(wxPaintEvent& evt);
        void paintNow();

        DECLARE_EVENT_TABLE()
};

#endif // MODELPOSERMAIN_H

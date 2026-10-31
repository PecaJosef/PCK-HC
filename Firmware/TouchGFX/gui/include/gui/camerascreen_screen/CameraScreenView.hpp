#ifndef CAMERASCREENVIEW_HPP
#define CAMERASCREENVIEW_HPP

#include <gui_generated/camerascreen_screen/CameraScreenViewBase.hpp>
#include <gui/camerascreen_screen/CameraScreenPresenter.hpp>

class CameraScreenView : public CameraScreenViewBase
{
public:
    CameraScreenView();
    virtual ~CameraScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // CAMERASCREENVIEW_HPP

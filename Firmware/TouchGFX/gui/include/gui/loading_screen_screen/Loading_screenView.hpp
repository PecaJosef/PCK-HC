#ifndef LOADING_SCREENVIEW_HPP
#define LOADING_SCREENVIEW_HPP

#include <gui_generated/loading_screen_screen/Loading_screenViewBase.hpp>
#include <gui/loading_screen_screen/Loading_screenPresenter.hpp>

class Loading_screenView : public Loading_screenViewBase
{
public:
    Loading_screenView();
    virtual ~Loading_screenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // LOADING_SCREENVIEW_HPP

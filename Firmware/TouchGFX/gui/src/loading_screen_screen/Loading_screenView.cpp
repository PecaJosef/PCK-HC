#include <gui/loading_screen_screen/Loading_screenView.hpp>

Loading_screenView::Loading_screenView()
{

}

void Loading_screenView::setupScreen()
{
    Loading_screenViewBase::setupScreen();

    boxProgress1.updateValue(100, 60);
}

void Loading_screenView::tearDownScreen()
{
    Loading_screenViewBase::tearDownScreen();
}

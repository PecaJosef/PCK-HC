#ifndef LOADING_SCREENPRESENTER_HPP
#define LOADING_SCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Loading_screenView;

class Loading_screenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Loading_screenPresenter(Loading_screenView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~Loading_screenPresenter() {}

private:
    Loading_screenPresenter();

    Loading_screenView& view;
};

#endif // LOADING_SCREENPRESENTER_HPP

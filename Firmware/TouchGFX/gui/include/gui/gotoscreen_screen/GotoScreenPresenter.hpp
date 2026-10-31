#ifndef GOTOSCREENPRESENTER_HPP
#define GOTOSCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class GotoScreenView;

class GotoScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    GotoScreenPresenter(GotoScreenView& v);

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

    virtual ~GotoScreenPresenter() {}

private:
    GotoScreenPresenter();

    GotoScreenView& view;
};

#endif // GOTOSCREENPRESENTER_HPP

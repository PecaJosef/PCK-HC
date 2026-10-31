#ifndef GOTOSCREENVIEW_HPP
#define GOTOSCREENVIEW_HPP

#include <gui_generated/gotoscreen_screen/GotoScreenViewBase.hpp>
#include <gui/gotoscreen_screen/GotoScreenPresenter.hpp>

class GotoScreenView : public GotoScreenViewBase
{
public:
    GotoScreenView();
    virtual ~GotoScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void scrollWheelRA_HUpdateItem(Wheel_RADEC& item, int16_t itemIndex) override;
    virtual void scrollWheelRA_MUpdateItem(Wheel_RADEC& item, int16_t itemIndex) override;
    virtual void scrollWheelRA_SUpdateItem(Wheel_RADEC& item, int16_t itemIndex) override;
    virtual void scrollWheelDEC_DUpdateItem(Wheel_RADEC& item, int16_t itemIndex) override;
    virtual void scrollWheelDEC_MUpdateItem(Wheel_RADEC& item, int16_t itemIndex) override;
    virtual void scrollWheelDEC_SUpdateItem(Wheel_RADEC& item, int16_t itemIndex) override;
protected:

//RADEC wheel inputs
    int activeInput; // 0=RA_H, 1=RA_M, 2=RA_S, 3 = SIGN, 4=DEC_D, 5=DEC_M, 6=DEC_S
    
    bool isDecPositive;
    virtual void toggleDecSign();

    virtual bool isAtPole();

    virtual void incrementValue();
    virtual void decrementValue();
    virtual void setActiveInput(int inputIndex);
    virtual void setNextActiveInput();

    virtual void wheelSelectedRA_H()  { setActiveInput(0); }
    virtual void wheelSelectedRA_M()  { setActiveInput(1); }
    virtual void wheelSelectedRA_S()  { setActiveInput(2); }
    virtual void signSelected()       { setActiveInput(3); }
    virtual void wheelSelectedDEC_D() { setActiveInput(4); }
    virtual void wheelSelectedDEC_M() { setActiveInput(5); }
    virtual void wheelSelectedDEC_S() { setActiveInput(6); }

    touchgfx::Callback<GotoScreenView, int16_t> cbRA_H;
    touchgfx::Callback<GotoScreenView, int16_t> cbRA_M;
    touchgfx::Callback<GotoScreenView, int16_t> cbRA_S;
    touchgfx::Callback<GotoScreenView, int16_t> cbDEC_D;
    touchgfx::Callback<GotoScreenView, int16_t> cbDEC_M;
    touchgfx::Callback<GotoScreenView, int16_t> cbDEC_S;
    
    void handlerRA_H(int16_t itemSelected);
    void handlerRA_M(int16_t itemSelected);
    void handlerRA_S(int16_t itemSelected);
    void handlerDEC_D(int16_t itemSelected);
    void handlerDEC_M(int16_t itemSelected);
    void handlerDEC_S(int16_t itemSelected);
};

#endif // GOTOSCREENVIEW_HPP

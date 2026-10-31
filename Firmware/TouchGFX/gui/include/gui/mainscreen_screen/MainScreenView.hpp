#ifndef MAINSCREENVIEW_HPP
#define MAINSCREENVIEW_HPP

#include <gui_generated/mainscreen_screen/MainScreenViewBase.hpp>
#include <gui/mainscreen_screen/MainScreenPresenter.hpp>

class MainScreenView : public MainScreenViewBase
{
public:
    MainScreenView();
    virtual ~MainScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void scrollWheelRA_HUpdateItem(Wheel_RADEC& item, int16_t itemIndex) override;
    virtual void scrollWheelRA_MUpdateItem(Wheel_RADEC& item, int16_t itemIndex) override;
    virtual void scrollWheelRA_SUpdateItem(Wheel_RADEC& item, int16_t itemIndex) override;
    virtual void scrollWheelDEC_DUpdateItem(Wheel_RADEC& item, int16_t itemIndex) override;
    virtual void scrollWheelDEC_MUpdateItem(Wheel_RADEC& item, int16_t itemIndex) override;
    virtual void scrollWheelDEC_SUpdateItem(Wheel_RADEC& item, int16_t itemIndex) override;

protected:
    int currentPage;
    virtual void slideDown();
    virtual void slideUp();

    //RADEC wheel inputs
    int activeInput; // 0=RA_H, 1=RA_M, 2=RA_S, 3=DEC_D, 4=DEC_M, 5=DEC_S
    
    virtual void incrementValue();
    virtual void decrementValue();
    virtual void setActiveInput(int inputIndex);
    virtual void setNextActiveInput();

    virtual void wheelSelectedRA_H()  { setActiveInput(0); }
    virtual void wheelSelectedRA_M()  { setActiveInput(1); }
    virtual void wheelSelectedRA_S()  { setActiveInput(2); }
    virtual void wheelSelectedDEC_D() { setActiveInput(3); }
    virtual void wheelSelectedDEC_M() { setActiveInput(4); }
    virtual void wheelSelectedDEC_S() { setActiveInput(5); }

    touchgfx::Callback<MainScreenView, int16_t> cbRA_H;
    touchgfx::Callback<MainScreenView, int16_t> cbRA_M;
    touchgfx::Callback<MainScreenView, int16_t> cbRA_S;
    touchgfx::Callback<MainScreenView, int16_t> cbDEC_D;
    touchgfx::Callback<MainScreenView, int16_t> cbDEC_M;
    touchgfx::Callback<MainScreenView, int16_t> cbDEC_S;
    
    void handlerRA_H(int16_t itemSelected);
    void handlerRA_M(int16_t itemSelected);
    void handlerRA_S(int16_t itemSelected);
    void handlerDEC_D(int16_t itemSelected);
    void handlerDEC_M(int16_t itemSelected);
    void handlerDEC_S(int16_t itemSelected);
};

#endif // MAINSCREENVIEW_HPP

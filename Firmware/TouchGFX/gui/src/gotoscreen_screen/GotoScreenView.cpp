#include <gui/gotoscreen_screen/GotoScreenView.hpp>
#include <touchgfx/EasingEquations.hpp>

GotoScreenView::GotoScreenView():
    cbRA_H(this, &GotoScreenView::handlerRA_H),
    cbRA_M(this, &GotoScreenView::handlerRA_M),
    cbRA_S(this, &GotoScreenView::handlerRA_S),
    cbDEC_D(this, &GotoScreenView::handlerDEC_D),
    cbDEC_M(this, &GotoScreenView::handlerDEC_M),
    cbDEC_S(this, &GotoScreenView::handlerDEC_S)
{

}

void GotoScreenView::setupScreen()
{
    GotoScreenViewBase::setupScreen();
    isDecPositive = true;

    scrollWheelRA_H.setItemSelectedCallback(cbRA_H);
    scrollWheelRA_M.setItemSelectedCallback(cbRA_M);
    scrollWheelRA_S.setItemSelectedCallback(cbRA_S);
    scrollWheelDEC_D.setItemSelectedCallback(cbDEC_D);
    scrollWheelDEC_M.setItemSelectedCallback(cbDEC_M);
    scrollWheelDEC_S.setItemSelectedCallback(cbDEC_S);
}

void GotoScreenView::tearDownScreen()
{
    GotoScreenViewBase::tearDownScreen();
}


void GotoScreenView::toggleDecSign()
{
    isDecPositive = !isDecPositive;

    setActiveInput(3);
    
    if (isDecPositive)
    {
        Unicode::snprintf(decDegSignBuffer, DECDEGSIGN_SIZE, "+");
    }
    else
    {
        Unicode::snprintf(decDegSignBuffer, DECDEGSIGN_SIZE, "-");
    }
    
    decDegSign.invalidate();
}

bool GotoScreenView::isAtPole()
{
    if (scrollWheelDEC_D.getSelectedItem() == 90) 
    {
        return true;
    }
    return false;
}


void GotoScreenView::incrementValue()
{
    int currentItem = 0;
    switch (activeInput)
    {
        case 0:
            currentItem = scrollWheelRA_H.getSelectedItem();
            scrollWheelRA_H.animateToItem(currentItem, 0);
            scrollWheelRA_H.animateToItem(currentItem + 1);
            break;
        case 1:
            currentItem = scrollWheelRA_M.getSelectedItem();
            scrollWheelRA_M.animateToItem(currentItem, 0);
            scrollWheelRA_M.animateToItem(currentItem + 1);
            break;
        case 2:
            currentItem = scrollWheelRA_S.getSelectedItem();
            scrollWheelRA_S.animateToItem(currentItem, 0);
            scrollWheelRA_S.animateToItem(currentItem + 1);
            break;
        case 3:
            toggleDecSign();
            break;
        case 4:
            currentItem = scrollWheelDEC_D.getSelectedItem();
            scrollWheelDEC_D.animateToItem(currentItem, 0);
            scrollWheelDEC_D.animateToItem(currentItem + 1);
            break;
        case 5:
            if (isAtPole()) break;
            currentItem = scrollWheelDEC_M.getSelectedItem();
            scrollWheelDEC_M.animateToItem(currentItem, 0);
            scrollWheelDEC_M.animateToItem(currentItem + 1);
            break;
        case 6:
            if (isAtPole()) break;
            currentItem = scrollWheelDEC_S.getSelectedItem();
            scrollWheelDEC_S.animateToItem(currentItem, 0);
            scrollWheelDEC_S.animateToItem(currentItem + 1);
            break;
    }
}

void GotoScreenView::decrementValue()
{
    int currentItem = 0;
    switch (activeInput)
    {
        case 0:
            currentItem = scrollWheelRA_H.getSelectedItem();
            scrollWheelRA_H.animateToItem(currentItem, 0); 
            scrollWheelRA_H.animateToItem(currentItem - 1);
            break;
        case 1:
            currentItem = scrollWheelRA_M.getSelectedItem();
            scrollWheelRA_M.animateToItem(currentItem, 0);
            scrollWheelRA_M.animateToItem(currentItem - 1);
            break;
        case 2:
            currentItem = scrollWheelRA_S.getSelectedItem();
            scrollWheelRA_S.animateToItem(currentItem, 0);
            scrollWheelRA_S.animateToItem(currentItem - 1);
            break;
        case 3:
            toggleDecSign();
            break;
        case 4:
            currentItem = scrollWheelDEC_D.getSelectedItem();
            scrollWheelDEC_D.animateToItem(currentItem, 0);
            scrollWheelDEC_D.animateToItem(currentItem - 1);
            break;
        case 5:
            if (isAtPole()) break;
            currentItem = scrollWheelDEC_M.getSelectedItem();
            scrollWheelDEC_M.animateToItem(currentItem, 0);
            scrollWheelDEC_M.animateToItem(currentItem - 1);
            break;
        case 6:
            if (isAtPole()) break;
            currentItem = scrollWheelDEC_S.getSelectedItem();
            scrollWheelDEC_S.animateToItem(currentItem, 0);
            scrollWheelDEC_S.animateToItem(currentItem - 1);
            break;
    }
}

void GotoScreenView::setActiveInput(int inputIndex)
{
    activeInput = inputIndex;
    
    if (activeInput == 3)
    {
        wheelSelected.setVisible(false);
        wheelSelected.invalidate(); 
        
        decSignSelected.setVisible(true);
        decSignSelected.invalidate();
    }
    else
    {
        
        decSignSelected.setVisible(false);
        decSignSelected.invalidate();
        
        wheelSelected.setVisible(true);
        
        switch (activeInput)
        {
        case 0: wheelSelected.moveTo(scrollWheelRA_H.getX(), scrollWheelRA_H.getY()); break;
        case 1: wheelSelected.moveTo(scrollWheelRA_M.getX(), scrollWheelRA_M.getY()); break;
        case 2: wheelSelected.moveTo(scrollWheelRA_S.getX(), scrollWheelRA_S.getY()); break;
        case 4: wheelSelected.moveTo(scrollWheelDEC_D.getX(), scrollWheelDEC_D.getY()); break;
        case 5: wheelSelected.moveTo(scrollWheelDEC_M.getX(), scrollWheelDEC_M.getY()); break;
        case 6: wheelSelected.moveTo(scrollWheelDEC_S.getX(), scrollWheelDEC_S.getY()); break;
        }
        wheelSelected.invalidate();
    }

}


void GotoScreenView::setNextActiveInput()
{
    // Add 1 to the current index. The "% 6" forces it to wrap back to 0 
    // after it reaches 5, creating a continuous loop.
    int nextIndex = (activeInput + 1) % 7; 
    setActiveInput(nextIndex);
}

void GotoScreenView::handlerRA_H(int16_t itemSelected) { setActiveInput(0); }
void GotoScreenView::handlerRA_M(int16_t itemSelected) { setActiveInput(1); }
void GotoScreenView::handlerRA_S(int16_t itemSelected) { setActiveInput(2); }
void GotoScreenView::handlerDEC_D(int16_t itemSelected) { setActiveInput(4); }
void GotoScreenView::handlerDEC_M(int16_t itemSelected) { setActiveInput(5); }
void GotoScreenView::handlerDEC_S(int16_t itemSelected) { setActiveInput(6); }

void GotoScreenView::scrollWheelRA_HUpdateItem(Wheel_RADEC& item, int16_t itemIndex)
{
    item.setValue(itemIndex);
}
void GotoScreenView::scrollWheelRA_MUpdateItem(Wheel_RADEC& item, int16_t itemIndex)
{
    item.setValue(itemIndex);
}
void GotoScreenView::scrollWheelRA_SUpdateItem(Wheel_RADEC& item, int16_t itemIndex)
{
    item.setValue(itemIndex);
}
void GotoScreenView::scrollWheelDEC_DUpdateItem(Wheel_RADEC& item, int16_t itemIndex)
{
    item.setValue(itemIndex);

    if (isAtPole())
    {
        scrollWheelDEC_M.animateToItem(0, 15);
        scrollWheelDEC_S.animateToItem(0, 15);
        scrollWheelDEC_M.setTouchable(false);
        scrollWheelDEC_S.setTouchable(false);
    }
    else
    {
        scrollWheelDEC_M.setTouchable(true);
        scrollWheelDEC_S.setTouchable(true);
    }
}
void GotoScreenView::scrollWheelDEC_MUpdateItem(Wheel_RADEC& item, int16_t itemIndex)
{
    item.setValue(itemIndex);
}
void GotoScreenView::scrollWheelDEC_SUpdateItem(Wheel_RADEC& item, int16_t itemIndex)
{
    item.setValue(itemIndex);
}
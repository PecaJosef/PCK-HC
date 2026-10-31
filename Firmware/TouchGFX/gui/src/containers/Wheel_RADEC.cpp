#include <gui/containers/Wheel_RADEC.hpp>

Wheel_RADEC::Wheel_RADEC()
{

}

void Wheel_RADEC::initialize()
{
    Wheel_RADECBase::initialize();
}

void Wheel_RADEC::setValue(int value)
{
    Unicode::snprintf(wheelNumberBuffer, WHEELNUMBER_SIZE, "%02d", value);
    wheelNumber.invalidate(); 
}
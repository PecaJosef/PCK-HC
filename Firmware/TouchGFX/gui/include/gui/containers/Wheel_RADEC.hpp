#ifndef WHEEL_RADEC_HPP
#define WHEEL_RADEC_HPP

#include <gui_generated/containers/Wheel_RADECBase.hpp>

class Wheel_RADEC : public Wheel_RADECBase
{
public:
    Wheel_RADEC();
    virtual ~Wheel_RADEC() {}

    virtual void initialize();

    void setValue(int value);
protected:
};

#endif // WHEEL_RADEC_HPP

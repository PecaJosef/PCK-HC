#ifndef WHEEL_CAM_HPP
#define WHEEL_CAM_HPP

#include <gui_generated/containers/Wheel_CAMBase.hpp>

class Wheel_CAM : public Wheel_CAMBase
{
public:
    Wheel_CAM();
    virtual ~Wheel_CAM() {}

    virtual void initialize();
protected:
};

#endif // WHEEL_CAM_HPP

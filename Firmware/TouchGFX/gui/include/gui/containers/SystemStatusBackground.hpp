#ifndef SYSTEMSTATUSBACKGROUND_HPP
#define SYSTEMSTATUSBACKGROUND_HPP

#include <gui_generated/containers/SystemStatusBackgroundBase.hpp>

class SystemStatusBackground : public SystemStatusBackgroundBase
{
public:
    SystemStatusBackground();
    virtual ~SystemStatusBackground() {}

    virtual void initialize();
protected:
};

#endif // SYSTEMSTATUSBACKGROUND_HPP

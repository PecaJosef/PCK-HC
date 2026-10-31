#ifndef BACKGROUNDMASK_HPP
#define BACKGROUNDMASK_HPP

#include <gui_generated/containers/BackgroundMaskBase.hpp>

class BackgroundMask : public BackgroundMaskBase
{
public:
    BackgroundMask();
    virtual ~BackgroundMask() {}

    virtual void initialize();
protected:
};

#endif // BACKGROUNDMASK_HPP

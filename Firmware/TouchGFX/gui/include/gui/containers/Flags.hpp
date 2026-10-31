#ifndef FLAGS_HPP
#define FLAGS_HPP

#include <gui_generated/containers/FlagsBase.hpp>

class Flags : public FlagsBase
{
public:
    Flags();
    virtual ~Flags() {}

    virtual void initialize();
protected:
};

#endif // FLAGS_HPP

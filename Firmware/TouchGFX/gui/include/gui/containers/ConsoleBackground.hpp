#ifndef CONSOLEBACKGROUND_HPP
#define CONSOLEBACKGROUND_HPP

#include <gui_generated/containers/ConsoleBackgroundBase.hpp>

class ConsoleBackground : public ConsoleBackgroundBase
{
public:
    ConsoleBackground();
    virtual ~ConsoleBackground() {}

    virtual void initialize();
protected:
};

#endif // CONSOLEBACKGROUND_HPP

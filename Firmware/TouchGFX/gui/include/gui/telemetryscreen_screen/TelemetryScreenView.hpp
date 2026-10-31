#ifndef TELEMETRYSCREENVIEW_HPP
#define TELEMETRYSCREENVIEW_HPP

#include <gui_generated/telemetryscreen_screen/TelemetryScreenViewBase.hpp>
#include <gui/telemetryscreen_screen/TelemetryScreenPresenter.hpp>

class TelemetryScreenView : public TelemetryScreenViewBase
{
public:
    TelemetryScreenView();
    virtual ~TelemetryScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // TELEMETRYSCREENVIEW_HPP

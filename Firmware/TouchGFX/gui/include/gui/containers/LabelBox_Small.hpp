#ifndef LABELBOX_SMALL_HPP
#define LABELBOX_SMALL_HPP

#include <gui_generated/containers/LabelBox_SmallBase.hpp>

class LabelBox_Small : public LabelBox_SmallBase
{
public:
    LabelBox_Small();
    virtual ~LabelBox_Small() {}

    virtual void initialize();
protected:
};

#endif // LABELBOX_SMALL_HPP

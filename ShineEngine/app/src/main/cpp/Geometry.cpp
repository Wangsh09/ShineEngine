//
// Created by Administrator on 2017/7/5.
//

#include "Geometry.h"
#include <math.h>
#include <cmath>

// implementation of Size

Size::Size(void) : width(0), height(0)
{
}

Size::Size(float w, float h) : width(w), height(h)
{
}

Size::Size(const Size& other) : width(other.width), height(other.height)
{
}

bool Size::equals(const Size& target) const
{
    return (std::abs(this->width  - target.width)  < FLT_EPSILON)
           && (std::abs(this->height - target.height) < FLT_EPSILON);
}
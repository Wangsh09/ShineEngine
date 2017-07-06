//
// Created by Administrator on 2017/7/4.
//

#include "Image.h"

static bool _PVRHaveAlphaPremultiplied = false;

void Image::setPVRImagesHavePremultipliedAlpha(bool haveAlphaPremultiplied)
{
    _PVRHaveAlphaPremultiplied = haveAlphaPremultiplied;
}

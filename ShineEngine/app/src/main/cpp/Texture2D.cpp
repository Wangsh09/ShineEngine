//
// Created by Administrator on 2017/7/4.
//

#include "Texture2D.h"

// If the image has alpha, you can create RGBA8 (32-bit) or RGBA4 (16-bit) or RGB5A1 (16-bit)
// Default is: RGBA8888 (32-bit textures)
static Texture2D::PixelFormat g_defaultAlphaPixelFormat = Texture2D::PixelFormat::DEFAULT;

//
// Texture options for images that contains alpha
//
// implementation Texture2D (PixelFormat)
void Texture2D::setDefaultAlphaPixelFormat(Texture2D::PixelFormat format)
{
    g_defaultAlphaPixelFormat = format;
}

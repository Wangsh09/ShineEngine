//
// Created by Administrator on 2017/7/4.
//

#ifndef SHINEENGINE_IMAGE_H
#define SHINEENGINE_IMAGE_H


class Image {
public:
    /** treats (or not) PVR files as if they have alpha premultiplied.
     Since it is impossible to know at runtime if the PVR images have the alpha channel premultiplied, it is
     possible load them as if they have (or not) the alpha channel premultiplied.

     By default it is disabled.
     */
    static void setPVRImagesHavePremultipliedAlpha(bool haveAlphaPremultiplied);

};


#endif //SHINEENGINE_IMAGE_H

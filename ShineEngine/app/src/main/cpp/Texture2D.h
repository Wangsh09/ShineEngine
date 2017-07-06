//
// Created by Administrator on 2017/7/4.
//

#ifndef SHINEENGINE_TEXTURE2D_H
#define SHINEENGINE_TEXTURE2D_H


class Texture2D {

public:
    /** @typedef Texture2D::PixelFormat
     Possible texture pixel formats
     */
    enum class PixelFormat
    {
        //! auto detect the type
                AUTO,
        //! 32-bit texture: BGRA8888
                BGRA8888,
        //! 32-bit texture: RGBA8888
                RGBA8888,
        //! 24-bit texture: RGBA888
                RGB888,
        //! 16-bit texture without Alpha channel
                RGB565,
        //! 8-bit textures used as masks
                A8,
        //! 8-bit intensity texture
                I8,
        //! 16-bit textures used as masks
                AI88,
        //! 16-bit textures: RGBA4444
                RGBA4444,
        //! 16-bit textures: RGB5A1
                RGB5A1,
        //! 4-bit PVRTC-compressed texture: PVRTC4
                PVRTC4,
        //! 4-bit PVRTC-compressed texture: PVRTC4 (has alpha channel)
                PVRTC4A,
        //! 2-bit PVRTC-compressed texture: PVRTC2
                PVRTC2,
        //! 2-bit PVRTC-compressed texture: PVRTC2 (has alpha channel)
                PVRTC2A,
        //! ETC-compressed texture: ETC
                ETC,
        //! S3TC-compressed texture: S3TC_Dxt1
                S3TC_DXT1,
        //! S3TC-compressed texture: S3TC_Dxt3
                S3TC_DXT3,
        //! S3TC-compressed texture: S3TC_Dxt5
                S3TC_DXT5,
        //! ATITC-compressed texture: ATC_RGB
                ATC_RGB,
        //! ATITC-compressed texture: ATC_EXPLICIT_ALPHA
                ATC_EXPLICIT_ALPHA,
        //! ATITC-compressed texture: ATC_INTERPOLATED_ALPHA
                ATC_INTERPOLATED_ALPHA,
        //! Default texture format: AUTO
                DEFAULT = (int) AUTO,

        NONE = -1
    };

    /** sets the default pixel format for UIImagescontains alpha channel.

     @param format
     If the UIImage contains alpha channel, then the options are:
     - generate 32-bit textures: Texture2D::PixelFormat::RGBA8888 (default one)
     - generate 24-bit textures: Texture2D::PixelFormat::RGB888
     - generate 16-bit textures: Texture2D::PixelFormat::RGBA4444
     - generate 16-bit textures: Texture2D::PixelFormat::RGB5A1
     - generate 16-bit textures: Texture2D::PixelFormat::RGB565
     - generate 8-bit textures: Texture2D::PixelFormat::A8 (only use it if you use just 1 color)

     How does it work ?
     - If the image is an RGBA (with Alpha) then the default pixel format will be used (it can be a 8-bit, 16-bit or 32-bit texture)
     - If the image is an RGB (without Alpha) then: If the default pixel format is RGBA8888 then a RGBA8888 (32-bit) will be used. Otherwise a RGB565 (16-bit texture) will be used.

     This parameter is not valid for PVR / PVR.CCZ images.

     @since v0.8
     */
    static void setDefaultAlphaPixelFormat(Texture2D::PixelFormat format);

};


#endif //SHINEENGINE_TEXTURE2D_H

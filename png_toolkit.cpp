#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include "png_toolkit.h"

png_toolkit::png_toolkit()
{
}

png_toolkit::~png_toolkit()
{
    stbi_image_free(imgData.pixels);
}

bool png_toolkit::load( const std::string &pictureName )
{
    imgData.pixels = stbi_load(pictureName.c_str(), &imgData.w, &imgData.h, &imgData.compPerPixel, 0);
    return imgData.pixels != nullptr;
}

bool png_toolkit::save( const std::string &pictureName )
{
    return stbi_write_png(pictureName.c_str(),
                   imgData.w, imgData.h,
                   imgData.compPerPixel,
                   imgData.pixels, 0) != 0;
}

image_data png_toolkit::getPixelData( void ) const
{
    return imgData;
}

void png_toolkit::fillHalfRectRed()
{
    // alias
    auto cpp = imgData.compPerPixel;
    if (imgData.compPerPixel == 4 || imgData.compPerPixel == 3)
        for (int y = imgData.h / 2; y < imgData.h; y++)
            for (int x = 0; x < imgData.w * cpp; x += cpp)
            {
                imgData.pixels[y * imgData.w * cpp + x + 0] = 255;
                imgData.pixels[y * imgData.w * cpp + x + 1] = 0;
                imgData.pixels[y * imgData.w * cpp   + x + 2] = 0;
            }
}

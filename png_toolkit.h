#ifndef PNG_TOOLKIT_H
#define PNG_TOOLKIT_H

#include <string>
//#include <memory>
#include "../stb/stb_image.h"

struct image_data
{
    stbi_uc *pixels;
    int w, h;
    int compPerPixel;
};

class png_toolkit
{
public:
    png_toolkit();
    ~png_toolkit();
    bool load( std::string const &pictureName );
    image_data getPixelData( void ) const;
    void fillHalfRectRed( void );

private:
    image_data imgData;
};

#endif // PNG_TOOLKIT_H

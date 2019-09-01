#ifndef PNG_TOOLKIT_H
#define PNG_TOOLKIT_H

#include <string>
//#include <memory>
#include "stb_image.h"

struct image_data
{
    stbi_uc *pixels;
    int w, h;
    int compPerPixel;
};

class png_toolkit
{
public:
    enum class error {
        WrongSize,
        WrongFormat,
        Ok
    };

    png_toolkit();
    ~png_toolkit();
    bool load( std::string const &pictureName );
    bool save( std::string const &pictureName );
    float R2deviation( png_toolkit const &tool, error &err ) const;
    image_data getPixelData( void ) const;
    void fillHalfRectRed( void );

private:
    image_data imgData;
};

#endif // PNG_TOOLKIT_H

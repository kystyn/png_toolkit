
#include <iostream>
#include "png_drawer.h"

png_drawer::png_drawer( void ) {
}

void png_drawer::load( image_data &imgData )
{
    QImage::Format fmt;
    switch (imgData.compPerPixel)
    {
    case 4:
        fmt = QImage::Format::Format_RGBA8888;
        break;
    case 3:
        fmt = QImage::Format::Format_RGB888;
        break;
    case 2:
        // ????
        fmt = QImage::Format::Format_Grayscale16;
        break;
    case 1:
        fmt = QImage::Format::Format_Grayscale8;
        break;
    default:
        throw "Error format of picture\n";
    }

    image = QImage(imgData.pixels, imgData.w, imgData.h, fmt);
    QWidget::update();
}


void png_drawer::paintEvent( QPaintEvent * )
{
    painter.begin(this);
    painter.drawImage(QPoint(0, 0), image);
    painter.end();
}

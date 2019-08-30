#ifndef PNG_DRAWER_H
#define PNG_DRAWER_H

#include <QPainter>
#include <QWidget>
#include "stb_image.h"
#include "png_toolkit.h"

class png_drawer : public QWidget
{
    Q_OBJECT
public:
    png_drawer( void );
    void paintEvent( QPaintEvent * ) override;
    void load( image_data &imgData );

private:
    QImage image;
    QPainter painter;
};

#endif // PNG_DRAWER_H

#include "mainwindow.h"
//#include <QApplication>

int main( int argc, char *argv[] )
{

    QApplication a(argc, argv);
    main_window w(a);
    w.show();

    /*png_toolkit tool;
    tool.load("ex1.png");
    tool.fillHalfRectRed();
    tool.save("exred.png");*/

    return 0;
}

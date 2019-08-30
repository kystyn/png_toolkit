#include "mainwindow.h"
#include <QApplication>

int main( int argc, char *argv[] )
{
    QApplication a(argc, argv);
    main_window w(a);
    w.show();

    return a.exec();
}

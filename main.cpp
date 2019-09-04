#include <iostream>
#include "mainwindow.h"
#include <QApplication>

int main( int argc, char *argv[] )
{
    if (argc != 4)
    {
        // toolkit filter_name base_pic_name student_pic_name
        std::cout << "Not enough arguments\n";
        return 1;
    }
    QApplication a(argc, argv);
    main_window w(a);
    w.show();

    png_toolkit testTool;
    testTool.load(argv[2]);
    testTool.applyFilter(png_toolkit::filters[argv[1]]);

    png_toolkit studTool;
    studTool.load(argv[3]);
    studTool.applyFilter(png_toolkit::filters[argv[1]]);

    png_toolkit::Error err;
    auto dev = testTool.R2deviation(studTool, err);
    if (err == png_toolkit::Error::Ok) // TODO num of diff pixels
        std::cout << dev << std::endl;

    return 0;
}

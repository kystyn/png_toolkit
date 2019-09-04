#include <iostream>
#include "png_toolkit.h"

int main( int argc, char *argv[] )
{
    if (argc != 4)
    {
        // toolkit filter_name base_pic_name student_pic_name
        std::cout << "Not enough arguments\n";
        return 1;
    }

    png_toolkit testTool;
    testTool.load(argv[2]);
    if (png_toolkit::filters.find(argv[1]) != png_toolkit::filters.end())
        testTool.applyFilter(png_toolkit::filters[argv[1]]);
    else
    {
        std::cout << "Bad filter\n";
        return 1;
    }

    png_toolkit studTool;
    studTool.load(argv[3]);

    png_toolkit::Error err;
    int diffPix;
    auto dev = testTool.R2deviation(studTool, err, diffPix);
    if (err == png_toolkit::Error::Ok) // TODO num of diff pixels
        std::cout << dev << ' ' << diffPix << std::endl;

    return 0;
}

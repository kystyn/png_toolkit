#include <iostream>
#include "png_toolkit.h"

int main( int argc, char *argv[] )
{
    // toolkit filter_name base_pic_name student_pic_name limitPix limitMSE
    try
    {
        if (argc != 6)
            throw "Not enough arguments";

        png_toolkit testTool;
        testTool.load(argv[2]);
        if (png_toolkit::filters.find(argv[1]) != png_toolkit::filters.end())
            testTool.applyFilter(png_toolkit::filters[argv[1]]);
        else
            throw "Bad filter";

        png_toolkit studTool;
        studTool.load(argv[3]);

        png_toolkit::Error err;
        int diffPix;
        auto mse = testTool.mseDeviation(studTool, err, diffPix);
        if (err == png_toolkit::Error::Ok) // TODO num of diff pixels limits
        {
            if (diffPix < std::stoi(argv[4]))
                std::cout << "OK ";
            else
                std::cout << "BAD ";

            if (mse < std::stoi(argv[5]))
                std::cout << "OK";
            else
                std::cout << "BAD";
        }
        else
            throw "Bad picture size/format";
    }
    catch (const char *str)
    {
        std::cout << "Error: " << str << std::endl;
        return 1;
    }

    return 0;
}

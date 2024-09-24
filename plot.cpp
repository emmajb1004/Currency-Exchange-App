#include <string>
#include <iostream>
#include "plot.h"
    //start original code
    //plot data
    void plot::graph(int year, std::string reg, double open, double close, double high, double low)
    {
    //if the close was greater than the open
    //use straight lines for the box of the graph
    if (close > open)
    {
        std::cout << " " << std::endl;
        std::cout << "_" << year << " : " << reg << "_" << std::endl;
        std::cout << "  " << high << "  " <<  std::endl;
        std::cout << "     |     " << std::endl;
        std::cout << " --------" << std::endl;
        std::cout << "  " << open << "  " <<  std::endl;
        std::cout <<"|        |"  << std::endl;
        std::cout << "  " <<  close << "  " <<  std::endl;
        std::cout << " --------" << std::endl;
        std::cout << "     |     " << std::endl;
        std::cout << "  " << low << "  " << std::endl;
        std::cout << " " << std::endl;
    } else
    //if the close was less than the open
    //use curly lines for the box of the graph
    {
        std::cout << " " << std::endl;
        std::cout << "_" << year << " : " << reg << "_" << std::endl;
        std::cout << "  " << high << "  " <<  std::endl;
        std::cout << "     |     " << std::endl;
        std::cout << " ~~~~~~~~" << std::endl;
        std::cout << "  " <<  open << "  " << std::endl;
        std::cout <<"|        |"  << std::endl;
        std::cout << "  " << close << "  " << std::endl;
        std::cout << " ~~~~~~~~" << std::endl;
        std::cout << "     |     " << std::endl;
        std::cout << "  " << low << "  " << std::endl;
        std::cout << " " << std::endl; 
    } 
    }
    //end original code
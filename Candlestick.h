#pragma once
#include "WeatherData.h"


#include <string>
//start original code
//candlestick class with object and function
class Candlestick
{
    public:

        Candlestick(int _timestamp,
                        double _open, 
                        double _close, 
                        double _high,
                        double _low);

        int timestamp;
        double open;
        double close;
        double high;
        double low;
    
        static std::vector<Candlestick> candlesticks(std::vector<std::string> timestamp_vec, std::vector<double> temp_vec);
};
//end original code
 

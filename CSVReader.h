#pragma once

#include "WeatherData.h"
#include <vector>
#include <string>

//adapted from merkelrex
class CSVReader
{
    public:
     CSVReader();

     static std::vector<WeatherData> readCSV(std::string csvFile);

    private:
     static std::vector<std::string> tokenise(std::string csvLine, char separator);
     static WeatherData stringsToOBE(std::vector<std::string> strings);
     
}; 

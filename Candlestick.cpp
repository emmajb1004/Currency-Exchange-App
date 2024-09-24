#include "Candlestick.h"
#include <iostream>
#include <string>
#include <vector>
#include "CSVReader.h"
#include <algorithm>
using namespace std;

// start original code
Candlestick::Candlestick(int _timestamp, 
                        double _open,
                        double _close, 
                        double _high, 
                        double _low)
: timestamp(_timestamp), 
  open(_open), 
  close(_close),
  high(_high), 
  low(_low)
{

}
//turn data into vector of Candlestick objects
std::vector<Candlestick> Candlestick::candlesticks(std::vector<std::string> timestamp_vec, std::vector<double> temp_vec)
{
    std::vector<Candlestick>candlestick_vec;
    int current_year = 1980;
    int count = 0;
    double sum = 0;
    double previous_avg = 0;
    double min = 100;
    double max = -100;
    try 
    {
        for (int i = 0; i <= timestamp_vec.size(); ++i)
        {
            //if the current timestamp has the current year
            //reference used for find https://cplusplus.com/reference/string/string/find/
            if (timestamp_vec[i].find(std::to_string(current_year)) != string::npos)
            {
                //add the temperature with that same index
                //to the running sum of all entries of the searched year
                sum = sum + temp_vec[i];
                //keep running total of amount of values added to sum
                count++;
                //if the current indexed temp is greater
                //than current max then make new max value 
                if (temp_vec[i] > max)
                {
                    max = temp_vec[i];
                }
                //if the current indexed temp is less
                //than current min then make new min value 
                if (temp_vec[i] < min)
                {
                    min = temp_vec[i];
                }
            } else 
            {
                //calculate yearly average (close)
                double avg = sum/count;
                //create candlestick object of current year
                //with abov values
                Candlestick current {
                    current_year,
                    previous_avg,
                    avg,
                    max,
                    min
                };
                //push newly created candlestick to vector of candlesticks
                candlestick_vec.push_back(current);
                //reset all values to be first of new year
                //and make current year next year in csvfile
                sum = temp_vec[i];
                count = 1;
                current_year++;
                min = temp_vec[i];
                max = temp_vec[i];
                previous_avg = avg;
            }
        }
    } catch(const std::exception& e)
    {
        std::cout << "Candlestick::candlesticks error." <<std::endl; 
    }
      return candlestick_vec;
      
}
//end original code
#pragma once

#include <vector>
#include "Candlestick.h"
#include "WeatherData.h"

class WeatherMain
{
    public:
        // start original with help from merkelrex functions
        WeatherMain();
        /** Call this to start the sim */
        void init();
    private: 
        void loadWeatherData();
        void printMenu();
        void printHelp();
        //end
        // start original functions
        void print_candlesticks();
        void printPrediction();
        void plotting();
        //end
        // start original with help from merkelrex functions
        int getUserOption();
        void processUserOption(int userOption);
        //end

    //start original code
    std::vector<WeatherData> data;
    //vector of the timestamps from WeatherData saved as data in loadWeatherData function 
    std::vector<std::string> timestamps;
    //vector of temps from all countries from WeatherData
    std::vector<double> AT_temps, BE_temps, BG_temps, CH_temps, CZ_temps,
                        DE_temps, DK_temps, EE_temps, ES_temps, FI_temps,
                        FR_temps, GB_temps, GR_temps, HR_temps, HU_temps,
                        IE_temps, IT_temps, LT_temps, LU_temps, LV_temps,
                        NL_temps, NO_temps, PL_temps, PT_temps, RO_temps,
                        SE_temps, SI_temps, SK_temps;
    //Candlestick vectors to push computed candlestick weather to
    std::vector<Candlestick> AT_temps_candlesticks, BE_temps_candlesticks, BG_temps_candlesticks, CH_temps_candlesticks,
                            CZ_temps_candlesticks, DE_temps_candlesticks, DK_temps_candlesticks, EE_temps_candlesticks,
                            ES_temps_candlesticks, FI_temps_candlesticks, FR_temps_candlesticks, GB_temps_candlesticks,
                            GR_temps_candlesticks, HR_temps_candlesticks, HU_temps_candlesticks, IE_temps_candlesticks, IT_temps_candlesticks,
                            LT_temps_candlesticks, LU_temps_candlesticks, LV_temps_candlesticks, NL_temps_candlesticks,
                            NO_temps_candlesticks, PL_temps_candlesticks, PT_temps_candlesticks, RO_temps_candlesticks,
                            SE_temps_candlesticks, SI_temps_candlesticks, SK_temps_candlesticks;
    //vector of vectors or WeatherData country temp
    std::vector<std::vector <double>> country_temps;
    //vector of country code names
    std::vector<std::string> country_codes;
    //end original
}; 

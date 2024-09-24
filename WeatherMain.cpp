#include "WeatherMain.h"
#include <iostream>
#include <vector>
#include "Candlestick.h"
#include "CSVReader.h"
#include "Prediction.h"
#include "plot.h"
#include <limits>

WeatherMain::WeatherMain()
{


}

// start init setup taken from Merkelrex main
void WeatherMain::init()
{
    loadWeatherData();
    int input;
    while(true)
    {
        printMenu();
        input = getUserOption();
        processUserOption(input);
    }
}
//same as loadOrderBook from Merkelrex main
void WeatherMain::loadWeatherData()
{
    data = CSVReader::readCSV("weather_data_EU_1980-2019_temp_only.csv");
        //start original code
        //push back data from WeatherData into vectors
    for (auto& t : data)
    {
        timestamps.push_back(t.timestamp);
        AT_temps.push_back(t.AT);
        BE_temps.push_back(t.BE);
        BG_temps.push_back(t.BG);
        CH_temps.push_back(t.CH);
        CZ_temps.push_back(t.CZ);
        DE_temps.push_back(t.DE);
        DK_temps.push_back(t.DK);
        EE_temps.push_back(t.EE);
        ES_temps.push_back(t.ES);
        FI_temps.push_back(t.FI);
        FR_temps.push_back(t.FR);
        GB_temps.push_back(t.GB);
        GR_temps.push_back(t.GR);
        HR_temps.push_back(t.HR);
        HU_temps.push_back(t.HU);
        IE_temps.push_back(t.IE);
        IT_temps.push_back(t.IT);
        LT_temps.push_back(t.LT);
        LU_temps.push_back(t.LU);
        LV_temps.push_back(t.LV);
        NL_temps.push_back(t.NL);
        NO_temps.push_back(t.NO);
        PL_temps.push_back(t.PL);
        PT_temps.push_back(t.PT);
        RO_temps.push_back(t.RO);
        SE_temps.push_back(t.SE);
        SI_temps.push_back(t.SI);
        SK_temps.push_back(t.SK);
    } 
    //vector of vectors or WeatherData country temp
    country_temps = {AT_temps, BE_temps, BG_temps, CH_temps, CZ_temps,
                        DE_temps, DK_temps, EE_temps, ES_temps, FI_temps,
                        FR_temps, GB_temps, GR_temps, HR_temps, HU_temps,
                        IE_temps, IT_temps, LT_temps, LU_temps, LV_temps,
                        NL_temps, NO_temps, PL_temps, PT_temps, RO_temps,
                        SE_temps, SI_temps, SK_temps};
    //vector of country code names
    country_codes = {"AT", "BE", "BG", "CH", "CZ",
                        "DE", "DK", "EE", "ES", "FI",
                        "FR", "GB", "GR", "HR", "HU",
                        "IE", "IT", "LT", "LU", "LV",
                        "NL", "NO", "PL", "PT", "RO",
                        "SE", "SI", "SK"};

    
}
//end original code

//same print menu from merkelrex main with adjusted options
void WeatherMain::printMenu()
{
    // 1 print help
    std::cout << "1: Print help " << std::endl;
    // 2 print Candlestick data
    std::cout << "2: Print Candlestick data" << std::endl;
    // 3 plot Candlestick data
    std::cout << "3: Plot Candlestick data " << std::endl;
    // 4 print predictive data 
    std::cout << "4: Print predictive data for AT : 2020 " << std::endl;

    std::cout << "============== " << std::endl;
}

//same print help as merkelrex main with adjusted message
void WeatherMain::printHelp()
{
    std::cout << "Help - view Candlestick data for 28 counties through 1980-2019" << std::endl;
    std::cout << "Plot Candlestick data for 28 counties through 1980-2019" << std::endl;
    std::cout << "View predictive data for 2020 for the country AT" << std::endl;
}

//start original code 
//print candlesticks based on user input
void WeatherMain::print_candlesticks()
{
    //variables to save user input
    int userOption_region;
    int userOption_year_start;
    int userOption_year_end;

    //have user put in a number that matches
    //the country code of the candlestick data they want to see
    std::cout << "Type in Country code of Candlestick data you want to see" << std::endl;
    std::cout << "(1: AT), (2: BE), (3: BG), (4: CH), (5: CZ), (6: DE)" << std::endl;
    std::cout << "(7: DK), (8:  EE), (9: ES), (10: FI), (11: FR), (12: GB)" << std::endl;
    std::cout << "(13: GR), (14: HR), (15: HU), (16: IE), (17: IT), (18: LT)" << std::endl;
    std::cout << "(19: LU), (20: LV), (21: NL), (22: NO), (23: PL), (24: PT)" << std::endl;
    std::cout << "(25: RO), (26: SE), (27: SI), (28: SK)" << std::endl;

    //have user put in region code and save that to variable
    std::cin >> userOption_region;
    //end original code
    //if input is the wrong type, string, or out of range of numbers then keep repeating
    //to ask user to put in correct input
    //reference https://stackoverflow.com/questions/19696442/how-to-catch-invalid-input-in-c
    while(std::cin.fail() || userOption_region < 1 || userOption_region > 28) 
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "Bad input.  Enter a NUMBER between 1-28: " << std::endl;
        std::cout << "Type in Country code of Candlestick data you want to see" << std::endl;
        std::cout << "(1: AT), (2: BE), (3: BG), (4: CH), (5: CZ), (6: DE)" << std::endl;
        std::cout << "(7: DK), (8:  EE), (9: ES), (10: FI), (11: FR), (12: GB)" << std::endl;
        std::cout << "(13: GR), (14: HR), (15: HU), (16: IE), (17: IT), (18: LT)" << std::endl;
        std::cout << "(19: LU), (20: LV), (21: NL), (22: NO), (23: PL), (24: PT)" << std::endl;
        std::cout << "(25: RO), (26: SE), (27: SI), (28: SK)" << std::endl;
        std::cin >> userOption_region;
    }
    //start original code
    //save input to variable when correct info is typed
    userOption_region = userOption_region;

    //create vector of Candlesticks that will change depending
    //on user option and what country temps are used to make the Candlesticks
    std::vector<Candlestick> candles;

    //user option will change which country temperature vector is
    //used as the argument in the candlesticks making function
    //function will go through and match the correct weatherData
    //to include in argument based on userOption
    try {
        for (int i = 0; i < country_temps.size(); ++i)
        {
            if (userOption_region == i + 1)
            {
                candles = Candlestick::candlesticks(timestamps, country_temps[i]);
            }
        }
    } catch(const std::exception& e)
    {
        std::cout << "WeatherMain::print_candlesticks I'm sorry something went wrong with printing your data. Try again." <<std::endl; 
    }

    //have user put in the start and end of years they want
    //to help get indexes of the candlestick data to print
    std::cout << "Type in Start Year (between 1980-2019)" << std::endl;
    std::cin >> userOption_year_start;
    //end original
    //if input is the wrong type, string, or out of range of numbers then keep repeating
    //to ask user to put in correct input
    //reference https://stackoverflow.com/questions/19696442/how-to-catch-invalid-input-in-c
    while(std::cin.fail() || userOption_year_start < 1980 || userOption_year_start > 2019) 
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "Bad input.  Enter a NUMBER between 1980-2019: " << std::endl;;
        std::cout << "Type in Start Year (between 1980-2019)" << std::endl;
        std::cin >> userOption_year_start;
    }
    //start original code
    //save input to variable when correct info is typed
    userOption_year_start = userOption_year_start;

    std::cout << "Type in End Year (between 1980-2019)" << std::endl;
    std::cin >> userOption_year_end;
    //end original code
    //if input is the wrong type, string, or out of range of numbers
    // then keep repeating to ask user to put in correct input
    //reference https://stackoverflow.com/questions/19696442/how-to-catch-invalid-input-in-c
    while(std::cin.fail() || userOption_year_end < 1980 || userOption_year_end > 2019) 
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "Bad input.  Enter a NUMBER between 1980-2019: " << std::endl;;
        std::cout << "Type in End Year (between 1980-2019)" << std::endl;
        std::cin >> userOption_year_end;
    } 
    //start original code
    //save input to variable when correct info is typed
    userOption_year_end = userOption_year_end;

    //subtract 1980 from the userOption to use
    //that value as the number used in the for loop
    //that will output the user wanted range of
    //Candlestick data based on the indices
    int start = userOption_year_start - 1980;
    int end = userOption_year_end - 1980;
    //print out candlestick data from the desired year range
    try {
        for (int i = start; i <= end; ++i)
        {
            std::cout << "Year : " << candles[i].timestamp << std::endl;
            std::cout << "Region : " << country_codes[userOption_region - 1] << std::endl;
            std::cout << "Open : " << candles[i].open << std::endl;
            std::cout << "Close : " << candles[i].close << std::endl;
            std::cout << "High : " << candles[i].high << std::endl;
            std::cout << "Low : " << candles[i].low << std::endl;
            std::cout << " "<< std::endl;         
        }
    } catch(const std::exception& e)
    {
        std::cout << "WeatherMain::print_candlesticks I'm sorry something went wrong with printing your data. Try again." <<std::endl; 
    }
}
//end original code

// start original code to plot the Candlestick data
void WeatherMain::plotting()
{
    //variables to save user input
    int userOption_region;
    int userOption_year_start;
    int userOption_year_end;

    //have user put in a number that matches
    //the country code of the candlestick data they want to see
    std::cout << "Type in Country code of Candlestick data you want to see" << std::endl;
    std::cout << "(1: AT), (2: BE), (3: BG), (4: CH), (5: CZ), (6: DE)" << std::endl;
    std::cout << "(7: DK), (8:  EE), (9: ES), (10: FI), (11: FR), (12: GB)" << std::endl;
    std::cout << "(13: GR), (14: HR), (15: HU), (16: IE), (17: IT), (18: LT)" << std::endl;
    std::cout << "(19: LU), (20: LV), (21: NL), (22: NO), (23: PL), (24: PT)" << std::endl;
    std::cout << "(25: RO), (26: SE), (27: SI), (28: SK)" << std::endl;
    
    //have user put in region code and save that to variable
    std::cin >> userOption_region;

    //end original code
    //if input is the wrong type, string, or out of range of numbers then keep repeating
    //to ask user to put in correct input
    //reference https://stackoverflow.com/questions/19696442/how-to-catch-invalid-input-in-c
    while(std::cin.fail() || userOption_region < 1 || userOption_region > 28) 
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "Bad input.  Enter a NUMBER between 1-28: " << std::endl;
        std::cout << "Type in Country code of Candlestick data you want to see" << std::endl;
        std::cout << "(1: AT), (2: BE), (3: BG), (4: CH), (5: CZ), (6: DE)" << std::endl;
        std::cout << "(7: DK), (8:  EE), (9: ES), (10: FI), (11: FR), (12: GB)" << std::endl;
        std::cout << "(13: GR), (14: HR), (15: HU), (16: IE), (17: IT), (18: LT)" << std::endl;
        std::cout << "(19: LU), (20: LV), (21: NL), (22: NO), (23: PL), (24: PT)" << std::endl;
        std::cout << "(25: RO), (26: SE), (27: SI), (28: SK)" << std::endl;
        std::cin >> userOption_region;
    }
    //start original code
    //save input to variable when correct info is typed
    userOption_region = userOption_region;

    //variable to save region name to include in plots
    //will change based on region number user picked
    std::string region;

    //create vector of Candlesticks that will change depending
    //on user option and what country temps are used to make the Candlesticks
    std::vector<Candlestick> candles;

    //user option will change which country temperature vector is
    //used as the argument in the candlesticks making function
    //and what region code will be printed with plot
    //function will go through and match the correct weatherData
    //to include in argument based on userOption and correct region code 
    try {
        for (int i = 0; i < country_temps.size(); ++i)
        {
            if (userOption_region == i + 1)
            {
                candles = Candlestick::candlesticks(timestamps, country_temps[i]);
                region = country_codes[i];
            }
        }
    } catch(const std::exception& e)
    {
        std::cout << "WeatherMain::plotting I'm sorry something went wrong with plotting your data. Try again." <<std::endl; 
    }
    //have user put in the start and end of years they want
    //to help get indexes of the candlestick data to plot
    std::cout << "Type in Start Year (between 1980-2019)" << std::endl;
    std::cin >> userOption_year_start;
    //end original code
    //if input is the wrong type, string, or out of range of numbers then keep repeating
    //to ask user to put in correct input
    //reference https://stackoverflow.com/questions/19696442/how-to-catch-invalid-input-in-c
    while(std::cin.fail() || userOption_year_start < 1980 || userOption_year_start > 2019) 
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "Bad input.  Enter a NUMBER betwwen 1980-2019: " << std::endl;;
        std::cout << "Type in Start Year (between 1980-2019)" << std::endl;
        std::cin >> userOption_year_start;
    }
    //start original code
    //if input is out of number range then keep repeating
    //to ask user to put in correct input
    //save input to variable when correct info is typed
    userOption_year_start = userOption_year_start;

    std::cout << "Type in End Year (between 1980-2019)" << std::endl;
    std::cin >> userOption_year_end;
    //end original code
    //if input is the wrong type, string, or out of range of numbers then keep repeating
    //to ask user to put in correct input
    //reference https://stackoverflow.com/questions/19696442/how-to-catch-invalid-input-in-c
    while(std::cin.fail() || userOption_year_end < 1980 || userOption_year_end > 2019) 
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "Bad input.  Enter a NUMBER between 1980-2019: " << std::endl;;
        std::cout << "Type in End Year (between 1980-2019)" << std::endl;
        std::cin >> userOption_year_end;
    }
    //start original code
    //if input is out of number range then keep repeating
    //to ask user to put in correct input    
    //save input to variable when correct info is typed
    userOption_year_end = userOption_year_end;
    
    //subtract 1980 from the userOption to use
    //that value as the number used in the for loop
    //that will output the user wanted range of
    //Candlestick data based on the indices
    int start = userOption_year_start - 1980;
    int end = userOption_year_end - 1980;
    //plot candlestick data from the desired year range
    std::cout << "***Years with the close higher than the open will have straight (--) lines***" << std::endl;
    std::cout << "***Years with the close lower than the open will have wavy (~~) lines***" << std::endl;
    try {
        for (int i = start; i <= end; ++i)
        {
            plot::graph(candles[i].timestamp, region, candles[i].open,
                        candles[i].close, candles[i].high, candles[i].low);         
        } 
    } catch(const std::exception& e)
    {
        std::cout << "WeatherMain::plotting I'm sorry something went wrong with plotting your data. Try again." <<std::endl; 
    }
}
//end original code

// start original code
//print prediction of 2020 for country AT
void WeatherMain::printPrediction()
{
    //run predic_year function to calculate 2020 for AT
    Prediction _2020 = Prediction::predict_year(data);

    //set up data for plot
    //vector of candlesticks for country AT 
    std::vector<Candlestick> AT_2019 = Candlestick::candlesticks(timestamps, AT_temps);
    //save the closing value of 2019 as this will be the open of 2020
    double AT_2019_close = AT_2019[39].close;

    //vector of predictive month values
    std::vector<double> months = {_2020.jan, _2020.feb, _2020.mar, _2020.apr,
                                    _2020.may, _2020.jun, _2020.jul, _2020.aug,
                                    _2020.sep, _2020.oct, _2020.nov, _2020.dec};

    //go through predictive month values to find
    //sum of all months of 2020 and the high and low temperature
    double sum = 0; 
    double max = _2020.jan;
    double min = _2020.jan;
    for (int i = 0; i <= months.size(); ++i)
    {
        sum = sum + months[i];

        if (months[i] > max)
        {
            max = months[i];
        }
        //if the current indexed temp is less
        //than current min then make new min value 
        if (months[i] < min)
        {
            min = months[i];
        }
    }
    //closing values of 2020/average of all 2020 temps
    double _2020_close = sum/12;

    //print out title and monthy temperature predictions
    std::cout << _2020.title << std::endl;
    std::cout << "January : " << _2020.jan << std::endl;
    std::cout << "February : " << _2020.feb << std::endl;
    std::cout << "March : " << _2020.mar << std::endl;
    std::cout << "April : " << _2020.apr << std::endl;
    std::cout << "May : " << _2020.may << std::endl;
    std::cout << "June : " << _2020.jun << std::endl;
    std::cout << "July : " << _2020.jul << std::endl;
    std::cout << "August : " << _2020.aug << std::endl;
    std::cout << "September : " << _2020.sep << std::endl;
    std::cout << "October : " << _2020.oct << std::endl;
    std::cout << "November : " << _2020.nov << std::endl;
    std::cout << "December : " << _2020.dec << std::endl;

    //plot of 2020 using values calculated above
    plot::graph(2020, "AT", AT_2019_close,
            _2020_close, max, min);
}
//end original code

//inspired by merkelrex getUserOption to ask user for choice
//if input is the wrong type, string, or out of range of numbers then keep repeating
//to ask user to put in correct input
//reference https://stackoverflow.com/questions/19696442/how-to-catch-invalid-input-in-c
int WeatherMain::getUserOption()
{
    int userOption;

    std::cout << "Type in 1-4" << std::endl;
    std::cin >> userOption;
    while(std::cin.fail() || userOption < 1 || userOption > 4) 
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "Bad input.  Enter a NUMBER betwwen 1-4: " << std::endl;;
        // 1 print help
        std::cout << "1: Print help " << std::endl;
        // 2 print Candlestick data
        std::cout << "2: Print Candlestick data" << std::endl;
        // 3 plot Candlestick data
        std::cout << "3: Plot Candlestick data " << std::endl;
        // 4 print predictive data 
        std::cout << "4: Print predictive data for AT : 2020 " << std::endl;
        std::cout << "============== " << std::endl;
        std::cin >> userOption;
    }
    userOption = userOption;
    std::cout << "You chose: " << userOption << std::endl;
    return userOption;
}
//adapted from merkelrex processUseroption function
//call a function based on user choice
void WeatherMain::processUserOption(int userOption)
{
    if (userOption == 0) // bad input
    {
        std::cout << "Invalid choice. Choose 1-4" << std::endl;
    }
    if (userOption == 1) 
    {
        printHelp();
    }
    if (userOption == 2) 
    {
        print_candlesticks();
    }
    if (userOption == 3) 
    {
        plotting();
    }
    if (userOption == 4) 
    {
        printPrediction();
    }     
}
 

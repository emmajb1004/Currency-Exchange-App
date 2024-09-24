#include "CSVReader.h"
#include <iostream>
#include <fstream>

CSVReader::CSVReader()
{

}
//mix of original code and readcsv function from Merkelrex
std::vector<WeatherData> CSVReader::readCSV(std::string csvFilename)
{
    //vector to store WeatherData object returned from tokenise
    std::vector<WeatherData> entries;
    //read in csvfile
    std::ifstream csvFile{csvFilename};
    std::string line;
    //read in first csvfile that is just the header of the file
    std::getline(csvFile, line);
    //go through whole csv file line by line after the header line
    if (csvFile.is_open())
    {
        while(std::getline(csvFile, line))
        {
            try {
                //run tokenise and strings to OBE on all lines
                WeatherData data = stringsToOBE(tokenise(line, ','));
                //push back to vector of weatherData to access outside try block
                entries.push_back(data);
            }catch(const std::exception& e)
            {
                std::cout << "CSVReader::readCSV bad data"  << std::endl;
            }
        }// end of while
    }    
    return entries; 
}

//tokensise function from merkelrex program
std::vector<std::string> CSVReader::tokenise(std::string csvLine, char separator)
{
   std::vector<std::string> tokens;
   signed int start, end;
   std::string token;
    start = csvLine.find_first_not_of(separator, 0);
    do{
        end = csvLine.find_first_of(separator, start);
        if (start == csvLine.length() || start == end) break;
        if (end >= 0) token = csvLine.substr(start, end - start);
        else token = csvLine.substr(start, csvLine.length() - start);
        tokens.push_back(token);
    start = end + 1;
    }while(end > 0);

   return tokens; 
}

//adapted version of stringstoOBE function, mix of original and merkelrex code
WeatherData CSVReader::stringsToOBE(std::vector<std::string> tokens)
{
    double AT, BE, BG, CH, CZ, DE, DK, EE, ES, FI, FR, GB, GR, HR, HU, IE, IT, LT, LU, LV, NL, NO, PL, PT, RO, SE, SI, SK;

    //ignore lines that don't have all fields
    if (tokens.size() != 29) // bad
    {
        std::cout << "Bad line " << std::endl;
        throw std::exception{};
    }
    //start original code
    // we have 29 tokens
    //separate csvfile into columns/each country
    //change data from string to double to run calcs
    try {
            AT = std::stod(tokens[1]);
            BE = std::stod(tokens[2]);
            BG = std::stod(tokens[3]);
            CH = std::stod(tokens[4]);
            CZ = std::stod(tokens[5]);
            DE = std::stod(tokens[6]);
            DK = std::stod(tokens[7]);
            EE = std::stod(tokens[8]);
            ES = std::stod(tokens[9]); 
            FI = std::stod(tokens[10]); 
            FR = std::stod(tokens[11]); 
            GB = std::stod(tokens[12]); 
            GR = std::stod(tokens[13]); 
            HR = std::stod(tokens[14]); 
            HU = std::stod(tokens[15]); 
            IE = std::stod(tokens[16]); 
            IT = std::stod(tokens[17]); 
            LT = std::stod(tokens[18]); 
            LU = std::stod(tokens[19]);
            LV = std::stod(tokens[20]);
            NL = std::stod(tokens[21]); 
            NO = std::stod(tokens[22]); 
            PL = std::stod(tokens[23]); 
            PT = std::stod(tokens[24]); 
            RO = std::stod(tokens[25]); 
            SE = std::stod(tokens[26]); 
            SI = std::stod(tokens[27]); 
            SK = std::stod(tokens[28]);
    }catch(const std::exception& e){
        std::cout << "Bad float! " << std::endl;
        throw;        
    }
    //store double values into the WeatherData object
    WeatherData data{tokens[0], 
                         AT,
                         BE,
                         BG,
                         CH,
                         CZ,
                         DE,
                         DK,
                         EE,
                         ES,
                         FI,
                         FR,
                         GB,
                         GR,
                         HR,
                         HU,
                         IE,
                         IT,
                         LT,
                         LU,
                         LV,
                         NL,
                         NO,
                         PL,
                         PT,
                         RO,
                         SE,
                         SI,
                         SK};
    

    return data; 
}
//end original code
      

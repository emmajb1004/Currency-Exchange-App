#pragma once
#include "WeatherData.h"
#include "CSVReader.h"

//start original code
//make Prediction class
class Prediction
{
    public:
        Prediction(std::string _title,
                    double _jan,
                    double _feb,
                    double _mar,
                    double _apr,
                    double _may,
                    double _jun,
                    double _jul,
                    double _aug,
                    double _sep,
                    double _oct,
                    double _nov,
                    double _dec);

        std::string title;
        double jan;
        double feb;
        double mar;
        double apr;
        double may;
        double jun;
        double jul;
        double aug;
        double sep;
        double oct;
        double nov;
        double dec;
    
        static double find_months(double _1980, double _1981,
                                double _1982, double _1983,
                                double _1984, double _1985,
                                double _1986, double _1987,
                                double _1988, double _1989,
                                double _1990, double _1991,
                                double _1992, double _1993,
                                double _1994, double _1995,
                                double _1996, double _1997,
                                double _1998, double _1999,
                                double _2000, double _2001,
                                double _2002, double _2003,
                                double _2004, double _2005,
                                double _2006, double _2007,
                                double _2008, double _2009,
                                double _2010, double _2011,
                                double _2012, double _2013,
                                double _2014, double _2015,
                                double _2016, double _2017,
                                double _2018, double _2019
                                );
    static Prediction predict_year(std::vector<WeatherData> data);
};
//end original code
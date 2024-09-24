#include "WeatherData.h"
#include "CSVReader.h"
#include "Prediction.h"

//start original code 
Prediction::Prediction(std::string _title,
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
                        double _dec)
:
title(_title),
jan(_jan),
feb(_feb),
mar(_mar),
apr(_apr),
may(_may),
jun(_jun),
jul(_jul),
aug(_aug),
sep(_sep),
oct(_oct),
nov(_nov),
dec(_dec)
{

}

//find average monthly difference in temperature
//based on every change per every year in the data we have
double Prediction::find_months(double _1980, double _1981,
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
                                )
{   
    //variables to store the differences between each year's temperature
    //for the start of each month
    double one, two, three, four, five, six, seven, eight, nine, ten, eleven,
            twelve, thirteen, fourteen, fifteen, sixteen, seventeen, eighteen, nineteen,
            twenty, twenty1, twenty2, twenty3, twenty4, twenty5, twenty6, twenty7, twenty8,
            twenty9, thirty, thirty1, thirty2, thirty3, thirty4, thirty5, thirty6, thirty7, thirty8,
            thirty9;
    
    //calculate every difference per yer
        one = _1981 - _1980;
        two = _1982 - _1981;
        three = _1983 - _1982;
        five = _1985 - _1984;       
        six = _1986 - _1985;
        seven = _1987 - _1986;
        eight = _1988 - _1987;
        nine = _1989 - _1988;
        ten = _1990 - _1989;
        eleven = _1991 - _1990;
        twelve = _1992 - _1991;
        thirteen = _1993 - _1992;
        fourteen = _1994 - _1993;
        fifteen = _1995 - _1994;
        sixteen = _1996 - _1995;       
        seventeen = _1997 - _1996;
        eighteen = _1998 - _1997;
        nineteen = _1999 - _1998;
        twenty = _2000 - _1999;
        twenty1 = _2001 - _2000;
        twenty2 = _2002 - _2001;
        twenty3 = _2003 - _2002;
        twenty4 = _2004 - _2003;
        twenty5 = _2005 - _2004;
        twenty6 = _2006 - _2005;
        twenty7 = _2007 - _2006;       
        twenty8 = _2008 - _2007;
        twenty9 = _2009 - _2008;
        thirty = _2010 - _2009;
        thirty1 = _2011 - _2010;
        thirty2 = _2012 - _2011;
        thirty3 = _2013 - _2012;
        thirty4 = _2014 - _2013;
        thirty5 = _2015 - _2014;
        thirty6 = _2016 - _2015;
        thirty7 = _2017 - _2016;
        thirty8 = _2018 - _2017;
        thirty9 = _2019 - _2018;

    //sum up all of the differences
    double all = one + two + three + four + five + six + seven + eight + nine + ten + eleven
                + twelve + thirteen + fourteen + fifteen + sixteen + seventeen + eighteen + nineteen +
                twenty + twenty1 + twenty2 + twenty3 + twenty4 + twenty5 + twenty6 + twenty7 + twenty8
                + twenty9;
    //get the average temperature change per a month over the 
    //39 year range of data we have
    double difference = all/39;
    return difference;

}
//end original code

//start original code
//find and print out the predicted
//temperature of 2020 for the country AT for
//the beginning of every month of that year
Prediction Prediction::predict_year(std::vector<WeatherData>data)
{
    //create a vector of all temps for the country AT
    //from 1980 - 2019
    std::vector<double> temps_AT;
    for (auto& t : data)
    {
        temps_AT.push_back(t.AT);
    }
    //takes every value of January between 1980-2019 and runs
    //the find_months function on it to find the average rate of change
    double Jan = Prediction::find_months(temps_AT[0],temps_AT[8784],temps_AT[17544],temps_AT[26304],
                            temps_AT[35064],temps_AT[43848],temps_AT[52608],temps_AT[61368],
                            temps_AT[70128],temps_AT[78912],temps_AT[87672],temps_AT[96432],
                            temps_AT[105192],temps_AT[113976],temps_AT[122736],temps_AT[131496],
                            temps_AT[140256],temps_AT[149040],temps_AT[157802],temps_AT[166562],temps_AT[175320],
                            temps_AT[184104],temps_AT[192864],temps_AT[201624],temps_AT[210384],temps_AT[219168],
                            temps_AT[227928],temps_AT[236688],temps_AT[245448],temps_AT[254232],temps_AT[262992],temps_AT[271752],
                            temps_AT[280512],temps_AT[289296],temps_AT[298056],temps_AT[306816],temps_AT[315576],temps_AT[324360],
                            temps_AT[333120],temps_AT[341880]);
    //takes every value of February between 1980-2019 and runs
    //the find_months function on it to find the average rate of change
    double Feb = Prediction::find_months(temps_AT[744],temps_AT[9528],temps_AT[18288],temps_AT[27050],
                            temps_AT[35808],temps_AT[44592],temps_AT[53352],temps_AT[62112],
                            temps_AT[70872],temps_AT[79656],temps_AT[88416],temps_AT[97176],
                            temps_AT[105936],temps_AT[114720],temps_AT[123480],temps_AT[132240],
                            temps_AT[141000],temps_AT[149784],temps_AT[158544],temps_AT[167304],temps_AT[176064],
                            temps_AT[184848],temps_AT[193608],temps_AT[202368],temps_AT[211128],
                            temps_AT[219912],temps_AT[228672],temps_AT[237432],temps_AT[246192],temps_AT[254976],temps_AT[263736],
                            temps_AT[272496],temps_AT[281258],temps_AT[290042],temps_AT[298800],temps_AT[307560],temps_AT[316320],
                            temps_AT[325104],temps_AT[333864],temps_AT[342624]);
    //takes every value of March between 1980-2019 and runs
    //the find_months function on it to find the average rate of change
    double Mar = Prediction::find_months(temps_AT[1440],temps_AT[10200],temps_AT[18960],temps_AT[27720],
                            temps_AT[36504],temps_AT[45264],temps_AT[54024],temps_AT[62784],
                            temps_AT[71568],temps_AT[80328],temps_AT[89088],temps_AT[97848],
                            temps_AT[106632],temps_AT[115392],temps_AT[124152],temps_AT[132912],
                            temps_AT[141696],temps_AT[150456],temps_AT[159216],temps_AT[167976],temps_AT[176760],
                            temps_AT[185520],temps_AT[194280],temps_AT[203040],temps_AT[211824],temps_AT[220584],
                            temps_AT[229344],temps_AT[238104],temps_AT[246888],temps_AT[255648],temps_AT[264408],temps_AT[273168],
                            temps_AT[281952],temps_AT[290712],temps_AT[299472],temps_AT[308232],temps_AT[317016],temps_AT[325776],
                            temps_AT[334536],temps_AT[343296]);
    //takes every value of April between 1980-2019 and runs
    //the find_months function on it to find the average rate of change
    double Apr = Prediction::find_months(temps_AT[2186],temps_AT[10946],temps_AT[19704],temps_AT[28464],
                            temps_AT[37250],temps_AT[46008],temps_AT[54768],temps_AT[63528],
                            temps_AT[72312],temps_AT[81072],temps_AT[89932],temps_AT[98592],
                            temps_AT[107376],temps_AT[116136],temps_AT[124896],temps_AT[133656],
                            temps_AT[142440],temps_AT[151200],temps_AT[159960],temps_AT[168720],temps_AT[177504],
                            temps_AT[186264],temps_AT[195024],temps_AT[203784],temps_AT[212568],temps_AT[221328],
                            temps_AT[230088],temps_AT[238848],temps_AT[247632],temps_AT[256392],temps_AT[265152],temps_AT[273912],
                            temps_AT[282696],temps_AT[291456],temps_AT[300216],temps_AT[308976],temps_AT[317760],temps_AT[326520],
                            temps_AT[335280],temps_AT[344040]);
    //takes every value of May between 1980-2019 and runs
    //the find_months function on it to find the average rate of change
    double May = Prediction::find_months(temps_AT[2904],temps_AT[11664],temps_AT[20424],temps_AT[29184],
                            temps_AT[37968],temps_AT[46728],temps_AT[55488],temps_AT[64248],
                            temps_AT[73032],temps_AT[81792],temps_AT[90552],temps_AT[99312],
                            temps_AT[108096],temps_AT[116856],temps_AT[125616],temps_AT[134376],
                            temps_AT[143160],temps_AT[151920],temps_AT[160680],temps_AT[169440],temps_AT[178226],
                            temps_AT[186986],temps_AT[195744],temps_AT[204504],temps_AT[213288],temps_AT[222048],
                            temps_AT[230808],temps_AT[239568],temps_AT[248352],temps_AT[257112],temps_AT[205872],temps_AT[274632],
                            temps_AT[283416],temps_AT[292176],temps_AT[300936],temps_AT[309696],temps_AT[318480],temps_AT[327240],
                            temps_AT[336000],temps_AT[344760]);
    //takes every value of June between 1980-2019 and runs
    //the find_months function on it to find the average rate of change
    double Jun = Prediction::find_months(temps_AT[3650],temps_AT[12408],temps_AT[21168],temps_AT[29928],
                            temps_AT[38712],temps_AT[47472],temps_AT[56232],temps_AT[64992],
                            temps_AT[73776],temps_AT[82536],temps_AT[91296],temps_AT[100056],
                            temps_AT[108840],temps_AT[117600],temps_AT[126360],temps_AT[135120],
                            temps_AT[143904],temps_AT[152664],temps_AT[161424],temps_AT[170184],temps_AT[178968],
                            temps_AT[187728],temps_AT[196488],temps_AT[205248],temps_AT[214032],temps_AT[222792],
                            temps_AT[231552],temps_AT[240312],temps_AT[249096],temps_AT[257856],temps_AT[266616],temps_AT[275376],
                            temps_AT[284160],temps_AT[292920],temps_AT[301680],temps_AT[310440],temps_AT[319224],temps_AT[327984],
                            temps_AT[336744],temps_AT[345504]);
    //takes every value of July between 1980-2019 and runs
    //the find_months function on it to find the average rate of change
    double Jul = Prediction::find_months(temps_AT[4368],temps_AT[13128],temps_AT[21888],temps_AT[30648],
                            temps_AT[39432],temps_AT[48192],temps_AT[56952],temps_AT[65712],
                            temps_AT[74496],temps_AT[83256],temps_AT[92016],temps_AT[100776],
                            temps_AT[109560],temps_AT[118320],temps_AT[127080],temps_AT[135840],
                            temps_AT[144624],temps_AT[153384],temps_AT[162144],temps_AT[170904],temps_AT[179688],
                            temps_AT[188448],temps_AT[197208],temps_AT[205968],temps_AT[214752],temps_AT[223512],
                            temps_AT[232272],temps_AT[241032],temps_AT[249816],temps_AT[258576],temps_AT[267336],temps_AT[276096],
                            temps_AT[284880],temps_AT[293640],temps_AT[302400],temps_AT[311160],temps_AT[319944],temps_AT[328704],
                            temps_AT[337464],temps_AT[346224]);
    //takes every value of August between 1980-2019 and runs
    //the find_months function on it to find the average rate of change
    double Aug = Prediction::find_months(temps_AT[5112],temps_AT[13872],temps_AT[22632],temps_AT[31392],
                            temps_AT[40176],temps_AT[48936],temps_AT[57696],temps_AT[66456],
                            temps_AT[75240],temps_AT[84000],temps_AT[92760],temps_AT[101520],
                            temps_AT[110304],temps_AT[119064],temps_AT[127824],temps_AT[136584],
                            temps_AT[145368],temps_AT[154128],temps_AT[162888],temps_AT[171648],temps_AT[180432],
                            temps_AT[189192],temps_AT[197952],temps_AT[206714],temps_AT[215496],temps_AT[224256],
                            temps_AT[233016],temps_AT[241776],temps_AT[250560],temps_AT[259320],temps_AT[268080],temps_AT[276840],
                            temps_AT[285624],temps_AT[294364],temps_AT[303144],temps_AT[311904],temps_AT[320688],temps_AT[329448],
                            temps_AT[338208],temps_AT[346968]);
    //takes every value of September between 1980-2019 and runs
    //the find_months function on it to find the average rate of change
    double Sep = Prediction::find_months(temps_AT[5856],temps_AT[14616],temps_AT[23376],temps_AT[32136],
                            temps_AT[40920],temps_AT[49680],temps_AT[58440],temps_AT[67200],
                            temps_AT[75984],temps_AT[84744],temps_AT[93504],temps_AT[102264],
                            temps_AT[111048],temps_AT[119808],temps_AT[128568],temps_AT[137328],
                            temps_AT[146112],temps_AT[154872],temps_AT[163632],temps_AT[172392],temps_AT[181176],
                            temps_AT[189936],temps_AT[198696],temps_AT[207456],temps_AT[216240],temps_AT[225000],
                            temps_AT[233760],temps_AT[242520],temps_AT[251304],temps_AT[260064],temps_AT[268824],temps_AT[277584],
                            temps_AT[286368],temps_AT[295128],temps_AT[303888],temps_AT[312648],temps_AT[321432],temps_AT[330192],
                            temps_AT[338952],temps_AT[347712]);
    //takes every value of October between 1980-2019 and runs
    //the find_months function on it to find the average rate of change
    double Oct = Prediction::find_months(temps_AT[6576],temps_AT[15336],temps_AT[24096],temps_AT[32856],
                            temps_AT[41640],temps_AT[50400],temps_AT[59162],temps_AT[67922],
                            temps_AT[76704],temps_AT[85464],temps_AT[94224],temps_AT[102984],
                            temps_AT[111768],temps_AT[120530],temps_AT[129288],temps_AT[138048],
                            temps_AT[146832],temps_AT[155592],temps_AT[164352],temps_AT[173112],temps_AT[181896],
                            temps_AT[190656],temps_AT[199416],temps_AT[208176],temps_AT[216960],temps_AT[225720],
                            temps_AT[234480],temps_AT[243240],temps_AT[252024],temps_AT[260784],temps_AT[269544],temps_AT[278304],
                            temps_AT[287088],temps_AT[295848],temps_AT[304608],temps_AT[313368],temps_AT[322152],temps_AT[330912],
                            temps_AT[339672],temps_AT[348432]);
    //takes every value of November between 1980-2019 and runs
    //the find_months function on it to find the average rate of change
    double Nov = Prediction::find_months(temps_AT[7320],temps_AT[16080],temps_AT[24840],temps_AT[33600],
                            temps_AT[42384],temps_AT[51144],temps_AT[59904],temps_AT[68664],
                            temps_AT[77448],temps_AT[86208],temps_AT[94968],temps_AT[103728],
                            temps_AT[112512],temps_AT[121272],temps_AT[130032],temps_AT[138792],
                            temps_AT[147576],temps_AT[156336],temps_AT[165096],temps_AT[173856],temps_AT[182640],
                            temps_AT[191400],temps_AT[200160],temps_AT[208920],temps_AT[217704],temps_AT[226464],
                            temps_AT[235224],temps_AT[243984],temps_AT[252768],temps_AT[261528],temps_AT[270288],temps_AT[279048],
                            temps_AT[287832],temps_AT[296592],temps_AT[305352],temps_AT[314112],temps_AT[322896],temps_AT[331656],
                            temps_AT[340416],temps_AT[349176]);
    //takes every value of December between 1980-2019 and runs
    //the find_months function on it to find the average rate of change
    double Dec = Prediction::find_months(temps_AT[8040],temps_AT[16800],temps_AT[25560],temps_AT[34320],
                            temps_AT[34104],temps_AT[51866],temps_AT[60624],temps_AT[69384],
                            temps_AT[78170],temps_AT[86928],temps_AT[95688],temps_AT[104448],
                            temps_AT[113232],temps_AT[121922],temps_AT[130752],temps_AT[139512],
                            temps_AT[148296],temps_AT[157056],temps_AT[165816],temps_AT[174576],temps_AT[183360],
                            temps_AT[192122],temps_AT[200880],temps_AT[209640],temps_AT[218424],temps_AT[227184],
                            temps_AT[235444],temps_AT[244704],temps_AT[253488],temps_AT[262248],temps_AT[271008],temps_AT[279768],
                            temps_AT[288552],temps_AT[297312],temps_AT[306072],temps_AT[314832],temps_AT[323616],temps_AT[332376],
                            temps_AT[341136],temps_AT[349896]);
    //store the beginning temperature of every month in 2019
    double jan_2019 = temps_AT[341880];
    double feb_2019 = temps_AT[342624];   
    double mar_2019 = temps_AT[343296];   
    double apr_2019 = temps_AT[344040];   
    double may_2019 = temps_AT[344760];   
    double jun_2019 = temps_AT[345504];   
    double jul_2019 = temps_AT[346224];   
    double aug_2019 = temps_AT[346968];   
    double sep_2019 = temps_AT[347712];   
    double oct_2019 = temps_AT[348432];   
    double nov_2019 = temps_AT[349176];   
    double dec_2019 = temps_AT[349896];

    //store the predicted values of 2020
    //by adding the monthly beginning temps of 2019
    //by the average rate of change we previously calculated
    double jan_2020 = jan_2019 + Jan;
    double feb_2020 = feb_2019 + Feb; 
    double mar_2020 = mar_2019 + Mar; 
    double apr_2020 = apr_2019 + Apr;   
    double may_2020 = may_2019 + May;   
    double jun_2020 = jun_2019 + Jun;   
    double jul_2020 = jul_2019 + Jul;   
    double aug_2020 = aug_2019 + Aug;   
    double sep_2020 = sep_2019 + Sep;   
    double oct_2020 = oct_2019 + Oct;   
    double nov_2020 = nov_2019 + Nov;   
    double dec_2020 = dec_2019 + Dec;

    //store our prediction of 2020 in a Prediction object
    Prediction _2020
    {
        "AT : 2020",
        jan_2020,
        feb_2020,
        mar_2020,
        apr_2020,
        may_2020,
        jun_2020,
        jul_2020,
        aug_2020,
        sep_2020,
        oct_2020,
        nov_2020,
        dec_2020
    };
    return _2020;
      
}
//end original code
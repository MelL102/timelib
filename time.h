/**
Day of the Year
Malte Tewes
11.01.2021
**/

#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

struct date{                        //erzeugt den struct date
    int year;
    int month;
    int day;
};


// funktionsheader
int is_leapyear(int year);

int day_of_the_year(struct date);

int get_days_for_month(struct date);

int exists_date(struct date);

struct date input_date();
//

#endif // TIME_H_INCLUDED

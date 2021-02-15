/**
Day of the Year
Malte Tewes
11.01.2021
**/

#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

int is_leapyear(int year);

int day_of_the_year(int day, int month, int year);

int get_days_for_month(int month, int year);

int exists_date(int day, int month , int year);

void input_date(int *pointerYear, int *pointerMonth, int *pointerDay);

#endif // TIME_H_INCLUDED

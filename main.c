/**
Day of the Year
Malte Tewes
11.01.2021
**/

#include <stdio.h>
#include <stdlib.h>
#include "time.h"


int main()
{
   int day;
   int month;
   int year;
   int *pointerYear;
   int *pointerMonth;
   int *pointerDay;
   int output;

    input_date(&year, &month, &day);

    output = day_of_the_year(day, month, year);

    printf("Es ist der %i. Tag des Jahres",output);

    return 0;
}

/**
Day of the Year
Malte Tewes
11.01.2021
**/

// inludes
#include <stdio.h>
#include <stdlib.h>
#include "time.h"
//

int main()
{
   struct date x;                   // deklariert den struct x
   int output;

    x = input_date();               // ruft die funktion input_date auf zum eingeben des Datums

    output = day_of_the_year(x);    //ruft die funktion day_of_the_year, übergibt den struct x und gibt den Tag des Jahres zurück

    printf("Es ist der %i. Tag des Jahres",output);     // ausgabe des Tages im Jahr

    return 0;
}

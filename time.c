/**
Day of the Year
Malte Tewes
15.02.2021
**/

#include <stdio.h>
#include <stdlib.h>

int is_leapyear(int year) {                                                   // funktion zur ermittlung des schaltjahrs

    if(year >= 1582){
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);           // gibt zurück ob das jahr schaltjahr ist
    }else{return -1;}
}


int day_of_the_year(int day, int month, int year){                                      // funktion zur berechnung des tages

    int days[2][14] = {                                                     // array mit tagen im jahr die erste ist 0 damit januar auch 1 ist
    {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365},
    {0, 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366}
    };

    int leap = is_leapyear(year);
    int dfMonth = get_days_for_month(month, year);
    int exists = exists_date(day, month , year);

    if(dfMonth == -1 || exists == -1){return -1;}

    if(days[leap][month] + day > days[leap][month+1] || day > 31 || month > 12){
        return -1;                                                            // wenn die eingabe ungültig wird 0 zurück gegeben
    }else{
        return days[leap][month] + day;                                    // wenn die eingabe gültig ist wird der tag zurück gegeben
    }


}

int get_days_for_month(int month, int year){

    int days[2][14] = {                                                     // array mit tagen im jahr die erste ist 0 damit januar auch 1 ist
    {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365},
    {0, 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366}
    };

    int leap = is_leapyear(year);

    if(month > 12 || month < 1){
        return -1;
    }else{
        return days[leap][month+1] - days[leap][month];
    }

    }

int exists_date(int day, int month , int year){

    if(year < 1582 || year > 2400){return -1;}

    int days[2][14] = {                                                             // array mit tagen im jahr die erste ist 0 damit januar auch 1 ist
    {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365},
    {0, 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366}
    };

    int leap = is_leapyear(year);

    if(days[leap][month] + day > days[leap][month+1] || day > 31 || month > 12){
        return -1;                                                                  // wenn die eingabe ungültig wird -1 zurück gegeben
    }else{
        return 1;                                                                   // wenn die eingabe gültig ist wird 1 zurück gegeben
    }

}

void input_date(int *pointerYear, int *pointerMonth, int *pointerDay){
    do{
        printf("Bitte geben Sie das Jahr an: ");
        scanf("%i", pointerYear);
        fflush(stdin);

        printf("Bitte geben Sie den Monat ein: ");
        scanf("%i", pointerMonth);
        fflush(stdin);

        printf("Bitte geben Sie den Tag ein: ");
        scanf("%i", pointerDay);
        fflush(stdin);
    }
    while(exists_date(*pointerDay, *pointerMonth, *pointerYear) != 1);

}

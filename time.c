/**
Day of the Year
Malte Tewes
15.02.2021
**/

#include <stdio.h>
#include <stdlib.h>
#include "time.h"



int is_leapyear(int year) {                                                   // funktion zur ermittlung des schaltjahrs

    if(year >= 1582){
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);           // gibt zurück ob das jahr schaltjahr ist
    }else{return -1;}
}


int day_of_the_year(struct date x){                                      // funktion zur berechnung des tages

    int days[2][14] = {                                                     // array mit tagen im jahr die erste ist 0 damit januar auch 1 ist
    {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365},
    {0, 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366}
    };

    int leap = is_leapyear(x.year);
    int dfMonth = get_days_for_month(x);
    int exists = exists_date(x);

    if(dfMonth == -1 || exists == -1){return -1;}

    if(days[leap][x.month] + x.day > days[leap][x.month+1] || x.day > 31 || x.month > 12){
        return -1;                                                            // wenn die eingabe ungültig wird 0 zurück gegeben
    }else{
        return days[leap][x.month] + x.day;                                    // wenn die eingabe gültig ist wird der tag zurück gegeben
    }


}

int get_days_for_month(struct date x){

    int days[2][14] = {                                                     // array mit tagen im jahr die erste ist 0 damit januar auch 1 ist
    {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365},
    {0, 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366}
    };

    int leap = is_leapyear(x.year);                                         // ruft die funktion is_leapyear auf um zu überprüfen ob das gegebene jahr ein schaltjahr iost

    if(x.month > 12 || x.month < 1){
        return -1;
    }else{
        return days[leap][x.month+1] - days[leap][x.month];                 // gibt die anzahl der tage für den monat zurück
    }

    }

int exists_date(struct date x){

    if(x.year < 1582 || x.year > 2400){return -1;}

    int days[2][14] = {                                                             // array mit tagen im jahr die erste ist 0 damit januar auch 1 ist
    {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365},
    {0, 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366}
    };

    int leap = is_leapyear(x.year);

    if(days[leap][x.month] + x.day > days[leap][x.month+1] || x.day > 31 || x.month > 12){
        return -1;                                                                  // wenn die eingabe ungültig wird -1 zurück gegeben
    }else{
        return 1;                                                                   // wenn die eingabe gültig ist wird 1 zurück gegeben
    }

}

struct date input_date(){                                                           //funktion zum eingeben eines Datums gibt ein struct zurück
    struct date x;
    do{
        printf("Bitte geben Sie das Jahr an: ");
        scanf("%i", &x.year);                                                       // liest das jahr ein (Usereingabe)
        fflush(stdin);

        printf("Bitte geben Sie den Monat ein: ");
        scanf("%i", &x.month);                                                      // liest den Monat ein (Usereingabe)
        fflush(stdin);

        printf("Bitte geben Sie den Tag ein: ");
        scanf("%i", &x.day);                                                        // liest den Tag ein (Usereingabe)
        fflush(stdin);
    }
    while(exists_date(x) != 1);
    return x;
}

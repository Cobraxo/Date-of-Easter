/*** 
Created on April 02
From Linux
***/

#include <iostream>
#include <string>

/***
Formula of the mathematician Carl-Friedrich Gauss,
To calculate the date of Easter according to the year:

-R is the rest of the Euclidean division of the year by 4,
-S is the rest of the Euclidean division of the year by 7,
-T is the rest of the Euclidean division of the year by 19,

-B = 19 * T + 24

-M is the rest of the Euclidean division of B by 30,

-C = 2 * R + 4 * S + 6 * M + 5

-N is the rest of the Euclidean divison of C by 7,

-P = M + N

-If P is smaller than 10, then Easter day is P + 22 March,
-else if P is greater than 9, then Easter day is P - 9 April,
***/

//Using preprocessor constants, optimizing RAM
#define R year % 4
#define S year % 7
#define T year % 19

int DateOfEaster(int year, std::string &month) {

    short int B = 19 * (T) + 24;
    unsigned char M = B % 30;
    short int C = 2* (R) + 4*(S) + 6 * M + 5;
    unsigned char N = C % 7;
    char P = M + N;
    
    if (P < 10) {       //If P < 10, then Easter day is P + 22 March 
        P += 22;
       	month = "March";
    }

    else if (P > 9) {   //If P > 9, then the day of Easter is P - 9 April
        P -= 9;
	    month = "April";
    }
    
    return P;           //We return on Easter day   
}

int main()
{
    short int Year;
    std::string month;
    std::cout << "[?]Enter a year between 1900 and 2100, to calculate its date of Easter: ";
    std::cin >> Year;
    //We print the day with the month and the year.
    std::cout << "[!]Easter day is the " << DateOfEaster(Year, month) << " " << month << " " << Year << "." << std::endl;   
    std::cin.ignore();
    return 0;
}

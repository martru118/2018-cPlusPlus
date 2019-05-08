#include <iostream>
#include <cstdlib>
#include <iomanip>
 
using namespace std;

int sakamoto(int yyyy, int mm, int dd);
int monthLen(int month, int year);
void formatMonth(int dayNum, int& weekday);
void printMonth(int month, int year);
void printYear(int year);
 
int main() {
    string calendar;
    int calendarMonth;
    int calendarYear;

    //prompt user for month or year
    cout << "Welcome to Calendar App!" << endl;
    cout << "Would you like to view the Calendar by 'MONTH' or by 'YEAR'?: ";
    cin >> calendar;

    //if user wants to view month
    if (calendar == "month" || calendar == "MONTH" || calendar == "Month") {
        cout << "Which month would you like to view? (Enter the month number): ";
        cin >> calendarMonth;
        cout << "Of which year?: ";
        cin >> calendarYear;
        printMonth(calendarMonth, calendarYear);    //print month calendar according to user input

    //if user wants to view year
    } else if (calendar == "year" || calendar == "YEAR" || calendar == "Year") {
        cout << "Which year would you like to view?: ";
        cin >> calendarYear;
        printYear(calendarYear);    //print year calendar according to user input
    }
}

//https://wikicoding.org/wiki/c/Tomohiko_Sakamoto%27s_Algorithm/
int sakamoto(int yyyy, int mm, int dd) {
	int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
	yyyy -= mm < 3;

	return (yyyy + yyyy/4 - yyyy/100 + yyyy/400 + t[mm-1] + dd) % 7;
}

//determine the number of days in each month
int monthLen (int month, int year) {
    switch (month) {
        //April, June, September, November
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
            break;

        //February
        case 2:
            //leap year
            if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
                return 29;
            //normal year
            } else { 
                return 28;
            }
            break;
        
        //other months
        default:
            return 31;
            break;
    }
}

//format how calendar is displayed
void formatMonth(int dayNum, int& weekday) {
    //format spacing
    int nextDay = 3*weekday;
    while (nextDay > 0) {
        cout << " ";
        nextDay -= 1;
    }

    //format each week
    for (int date = 1; date <= dayNum; date++) {
        //set the number of characters for each number
        cout << setw(2) << date << " ";
        //at the end of the week, skip to next line
        if (weekday == 6) {
            cout << endl;
            weekday = 0;    //reset numbering
        } else { 
            weekday += 1;   //keep placing numbers
        }
    }
}

//display monthly calendar
void printMonth(int month, int year) {
    string monthName[] = {"JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE", 
                          "JULY", "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"};
    
    int firstDay = sakamoto(year, month, 1);    //use the value of the weekday

    //print headers
    cout << endl << monthName[month - 1] << " " << year << "\n" << endl;
    cout << " S  M Tu  W Th  F  S" <<endl;

    //format calendar
    formatMonth(monthLen(month, year), firstDay);
    cout << endl << endl;
}

//display yearly calendar
void printYear(int year) {
    //display 12 months
    for (int currentMonth = 1; currentMonth <= 12; currentMonth++) {
        printMonth(currentMonth, year);
    }
}

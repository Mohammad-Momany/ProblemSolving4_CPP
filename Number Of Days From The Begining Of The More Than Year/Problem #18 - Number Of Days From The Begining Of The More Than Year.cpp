#pragma warning(disable : 4996)
#include<iostream>
using namespace std;

struct stDate {
    short day = 0;
    short month;
    short year;
};

int ReadLimitedNumber(string message, int From, int To) {

    int EnteredNumber = 0;

    do {
        cout << message;
        cin >> ws >> EnteredNumber;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid Number" << endl;
        }
        else if (EnteredNumber > To)
            cout << "\nThe number Must be less than " << To << "\n";
        else if (EnteredNumber < From)
            cout << "\nThe number Must be greater than " << From << "\n";

    } while (EnteredNumber > To || EnteredNumber < From || cin.fail());

    return EnteredNumber;

}

void FillDate(stDate& Date)
{
    Date.day = ReadLimitedNumber("\nPlease enter a day to check: ", 1, 31);

    Date.month = ReadLimitedNumber("\nPlease enter a month to check: ", 1, 12);

    Date.year = ReadLimitedNumber("\nPlease enter a year to check: ", 0, 3000);

}

stDate GetSystemDate() {
    stDate Date;
    time_t t = time(0);
    tm* now = localtime(&t);
    Date.year = now->tm_year + 1900;
    Date.month = now->tm_mon + 1;
    Date.day = now->tm_mday;
    return Date;
}

short Thirty_ThirtyOneMonth(short month) {

    int Arr30Days[4] = { 4, 6, 9, 11 };

    for (int i = 0; i < 4; i++)
    {
        if (Arr30Days[i] == month) {
            return 30;
        }
    }

    return 31;
}

bool IsLeapYear(short Year) {

    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInAMonth(short year, short month) {
    if (month == 2)
    {
        return IsLeapYear(year) ? 29 : 28;
    }
    else {
        return Thirty_ThirtyOneMonth(month);
    }
}

short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year) {
    short TotalDays = 0;
    for (int i = 1; i <= Month - 1; i++) {
        TotalDays += NumberOfDaysInAMonth(Year, i);
    }
    TotalDays += Day;
    return TotalDays;
}

int NumberOfDaysFromTheBeginingOfTheYears(stDate &Date) {

    stDate CurrentDate = GetSystemDate();

    short NumberOfDays = NumberOfDaysFromTheBeginingOfTheYear(CurrentDate.day, CurrentDate.month, CurrentDate.year);

    
    NumberOfDays += (IsLeapYear(Date.year) ? 366  : 365 ) - NumberOfDaysFromTheBeginingOfTheYear(Date.day, Date.month, Date.year);

    short YearLength = CurrentDate.year - Date.year;

    for (int i = 1; i < YearLength; i++)
    {
        NumberOfDays += (IsLeapYear(Date.year + i) ? 366 : 365);
    }
    return  NumberOfDays;
}

int main() {

    stDate Date;

    FillDate(Date);
  
    cout << "\nNumber of Days from the beginning of the year to now is "
        << NumberOfDaysFromTheBeginingOfTheYears(Date);

    system("pause>0");
    return 0;
}

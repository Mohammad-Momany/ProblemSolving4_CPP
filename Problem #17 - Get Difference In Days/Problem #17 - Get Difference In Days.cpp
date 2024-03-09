#include<iostream>
using namespace std;

struct stDate {
    short Year;
    short Month;
    short Day;
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

stDate FillDate()
{
    stDate Date;
    Date.Day = ReadLimitedNumber("\nPlease enter a day to check: ", 1, 31);

    Date.Month = ReadLimitedNumber("\nPlease enter a month to check: ", 1, 12);

    Date.Year = ReadLimitedNumber("\nPlease enter a year to check: ", 0, 3000);

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

short GetDifferenceInDays(stDate Date, stDate Date1, bool IncludeEndDay = false) {

    short Difference = NumberOfDaysFromTheBeginingOfTheYear(Date1.Day, Date1.Month, Date1.Year) - NumberOfDaysFromTheBeginingOfTheYear(Date.Day, Date.Month, Date.Year);

    return IncludeEndDay ? Difference + 1 : Difference;
}
int main() {

    stDate Date = FillDate();
    stDate Date1 = FillDate();

    cout << "\nDiffrence is: " << GetDifferenceInDays(Date, Date1) << " Day(s).";

    cout << "\nDiffrence (Including End Day) is: " << GetDifferenceInDays(Date, Date1, true) << " Day(s).";

    system("pause>0");
    return 0;
}

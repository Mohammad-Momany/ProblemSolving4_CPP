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

bool IsLastDayInMonth(stDate Date) {
    return (Date.Day == NumberOfDaysInAMonth(Date.Year, Date.Month));
}

bool IsLastMonthInYear(short Month) {
    return (Month == 12);
}

void AddMonth(stDate& Date)
{
    if (IsLastMonthInYear(Date.Month))
    {
        Date.Year += 1;
        Date.Month = 1;
        Date.Day = 1;
    }
    else
        Date.Month += 1;
}

void AddDay(stDate& Date) {

    if (IsLastDayInMonth(Date))
    {
        Date.Day = 1;
        AddMonth(Date);
        
    }
    else
        Date.Day += 1;
}


int main() {
    stDate Date1 = FillDate();

    cout << " Befor: \n";
    cout << " Year: " << Date1.Year << " Month: " << Date1.Month << " Day: " << Date1.Day << "\n\n";
    AddDay(Date1);
    cout << "\n After: \n";
    cout << " Year: " << Date1.Year << " Month: " << Date1.Month << " Day: " << Date1.Day << "\n\n";

    system("pause>0");
    return 0;
}

#include <iostream>
#include<iomanip>

using namespace std;


struct stDate {
    short day;
    short month;
    short year;
};

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

string MonthShortName(short MonthNumber)
{
    string Months[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
    return (Months[MonthNumber - 1]);
}

short DayOfWeekOrder(stDate Date)
{
    short a = (14 - Date.month) / 12;
    short y = Date.year - a;
    short m = Date.month + (12 * a) - 2;

    short DayOrder = (Date.day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

    return DayOrder;
}

void FillDate(stDate& Date)
{
    Date.year = ReadLimitedNumber("\nPlease enter a year to check: ", 0, 3000);

    Date.month = ReadLimitedNumber("\nPlease enter a month to check: ", 1, 12);

    Date.day = 1;
}

void PrintMonthCalendar(stDate &Date) {

    printf("\n  _______________%s_______________\n\n", MonthShortName(Date.month).c_str());
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    short CurrentDay = DayOfWeekOrder(Date);
    short MonthDays = NumberOfDaysInAMonth(Date.year, Date.month);

    short Lenght = MonthDays + CurrentDay;


    for (short i = 1; i <= Lenght; i++)
    {
        if (CurrentDay > i - 1)
        {
            cout << setw(5) << "  ";
            continue;
        }

        cout << setw(5) << i - CurrentDay ;

        if (i % 7 == 0 || i % 7 == 7)  cout << '\n';
        
    }
    cout << endl;
};

int main()
{
    stDate Date;

    FillDate(Date);

    PrintMonthCalendar(Date);
    system("Pause > 0");

    return 0;
}


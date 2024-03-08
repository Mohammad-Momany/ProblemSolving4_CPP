#include <iostream>
using namespace std;


struct stDate {
    short day;
    short month;
    short year;
};

int ReadLimitedNumber(string message, int From, int To) {

    int EnteredNumber = 0;

    do {
        cout << message;
        cin >> EnteredNumber;

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

string DayOfWeek(short dayNumber)
{
    string daysOfWeek[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
    return daysOfWeek[dayNumber];
}

short DayOfWeekOrder(stDate Date)
{
    short a = (14 - Date.month) / 12;
    short y = Date.year - a;
    short m = Date.month + (12 * a) - 2;

    short DayOrder = (Date.day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
    
    return DayOrder;
}

void FillDate(stDate &Date)
{
    Date.year = ReadLimitedNumber("\nPlease enter a year to check: ", 0, 3000);

    Date.month = ReadLimitedNumber("\nPlease enter a month to check: ", 1, 12);

    Date.day = ReadLimitedNumber("\nPlease enter a day to check: ", 1, 31);
}

int main()
{
    stDate Date;

    FillDate(Date);

    short DayOrder = DayOfWeekOrder(Date);

    cout << "\nDate      :" << Date.day << "/" << Date.month << "/" << Date.year;

    cout << "\nDay Order : " << DayOrder;

    cout << "\nDay Name  : " << DayOfWeek(DayOrder);

    system("Pause > 0");

    return 0;
}


#include <iostream>
using namespace std;


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

bool IsLeapYear(short Year) {

    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

bool IsEven(int Num)
{
    return Num % 2 == 0;
}

short MonthToDays(short year, short month) {

    if (month == 2)
    {
        return IsLeapYear(year) ? 29 : 28;
    }
    else if (IsEven(month))
    {
        return 30;
    }
    else
    {
        return 31;
    }

}

short DaysToHours(short days) {

    return days * 24;
}

int HoursToMinutes(short Hours) {

    return Hours * 60;
}

int MinutesToSeconds(int Minutes) {

    return Minutes * 60;
}

int main() {

    short Year = ReadLimitedNumber("\nPlease enter a year to check: ", 0, 3000);

    short Month = ReadLimitedNumber("\nPlease enter a month to check: ", 1, 12);

    int Result = 0;

    Result = MonthToDays(Year, Month);

    cout << "\nNumber of Days    in Month [" << Month << "] is " << Result;

    Result = DaysToHours(Result);
    cout << "\nNumber of Hours   in Month [" << Month << "] is " << Result;

    Result = HoursToMinutes(Result);
    cout << "\nNumber of Minutes in Month [" << Month << "] is " << Result;

    Result = MinutesToSeconds(Result);
    cout << "\nNumber of Seconds in Month [" << Month << "] is " << Result;

    system("pause>0");
    return 0;
}

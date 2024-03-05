#include <iostream>
using namespace std;

bool IsLeapYear(short Year) {
    
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short YearToDays(short year) {

    return IsLeapYear(year) ? 366 : 365;
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

short ReadYear() {
    short Year;
    cout << "\nPlease enter a year to check: ";
    cin >> Year;
    return Year;
}

int main() {
    short Year = ReadYear();
    int Result = 0;

    Result = YearToDays(Year);
    cout << "\nNumber of Days    in Year [" << Year << "] is " << Result;

    Result = DaysToHours(Result);
    cout << "\nNumber of Hours   in Year [" << Year << "] is " << Result;

    Result = HoursToMinutes(Result);
    cout << "\nNumber of Minutes in Year [" << Year << "] is " << Result;

    Result = MinutesToSeconds(Result);
    cout << "\nNumber of Seconds in Year [" << Year << "] is " << Result;

    system("pause>0");
    return 0;
}

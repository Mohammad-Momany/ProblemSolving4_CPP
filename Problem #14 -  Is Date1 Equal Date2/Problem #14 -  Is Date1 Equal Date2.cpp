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

bool IsDate1EqualDate2(stDate Date1, stDate Date2) {
    return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
}



int main() {
    stDate Date1 = FillDate();
    stDate Date2 = FillDate();

    if (IsDate1EqualDate2(Date1, Date2))
        cout << "\nYes, Date1 is Equal To Date2.";
    else
        cout << "\nNo, Date1 is NOT Equal To Date2.";

    system("pause>0");
    return 0;
}

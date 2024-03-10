#include<iostream>
using namespace std;

struct stDate {
    short Year;
    short Month;
    short Day;
};

struct stPeriod {
    stDate StartDate;
    stDate EndDate;
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

bool IsDate1BeforeDate2(stDate Date1, stDate Date2) {
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

bool IsDate1EqualDate2(stDate Date1, stDate Date2) {
    return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
}

stDate FillDate()
{
    stDate Date;
    Date.Day = ReadLimitedNumber("\nPlease enter a day to check: ", 1, 31);

    Date.Month = ReadLimitedNumber("\nPlease enter a month to check: ", 1, 12);

    Date.Year = ReadLimitedNumber("\nPlease enter a year to check: ", 0, 3000);

    return Date;
}

int main() {
    stPeriod Period1;
    stPeriod Period2;

    cout << "\nEnter Start Date Period one\n";
    Period1.StartDate = FillDate();
    cout << "\nEnter End Date Period one\n";
    Period1.EndDate = FillDate(); 

    cout << "\nEnter Start Date Period Two\n";
    Period2.StartDate = FillDate();
    cout << "\nEnter End Date Period Two\n";
    Period2.EndDate = FillDate();

    if (IsDate1BeforeDate2(Period2.StartDate, Period1.StartDate) &&
        IsDate1BeforeDate2(Period1.EndDate, Period2.EndDate))
        cout << "\nNo, Periods do not Overlap\n";
    else        
        cout << "\nYes, Periods Overlap\n"; 
        

    system("pause>0");
    return 0;
}

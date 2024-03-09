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
    return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}

bool IsLastMonthInYear(short Month) {
    return (Month == 12);
}

stDate IncreaseDateByOneDay(stDate Date) {
    if (IsLastDayInMonth(Date)) {
        if (IsLastMonthInYear(Date.Month)) {
            Date.Month = 1;
            Date.Day = 1;
            Date.Year++;
        }
        else {
            Date.Day = 1;
            Date.Month++;
        }
    }
    else {
        Date.Day++;
    }
    return Date;
}

stDate IncreaseDateByOneWeek(stDate Date) {
    for (int i = 1; i <= 7; i++) {
        Date = IncreaseDateByOneDay(Date);
    }
    return Date;
}

stDate IncreaseDateByXWeeks(short Weeks, stDate Date) {
    for (short i = 1; i <= Weeks; i++) {
        Date = IncreaseDateByOneWeek(Date);
    }
    return Date;
}

stDate IncreaseDateByOneMonth(stDate Date) {
    if (Date.Month == 12) {
        Date.Month = 1;
        Date.Year++;
    }
    else {
        Date.Month++;
    }
    short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
    if (Date.Day > NumberOfDaysInCurrentMonth) {
        Date.Day = NumberOfDaysInCurrentMonth;
    }
    return Date;
}

stDate IncreaseDateByXDays(short Days, stDate Date) {
    for (short i = 1; i <= Days; i++) {
        Date = IncreaseDateByOneDay(Date);
    }
    return Date;
}

stDate IncreaseDateByXMonths(short Months, stDate Date) {
    for (short i = 1; i <= Months; i++) {
        Date = IncreaseDateByOneMonth(Date);
    }
    return Date;
}

stDate IncreaseDateByOneYear(stDate Date) {
    Date.Year++;
    return Date;
}

stDate IncreaseDateByXYears(short Years, stDate Date) {
    for (short i = 1; i <= Years; i++) {
        Date = IncreaseDateByOneYear(Date);
    }
    return Date;
}

stDate IncreaseDateByXYearsFaster(short Years, stDate Date) {
    Date.Year += Years;
    return Date;
}

stDate IncreaseDateByOneDecade(stDate Date) {
    Date.Year += 10;
    return Date;
}

stDate IncreaseDateByXDecades(short Decade, stDate Date) {
    for (short i = 1; i <= Decade * 10; i++) {
        Date = IncreaseDateByOneYear(Date);
    }
    return Date;
}

stDate IncreaseDateByXDecadesFaster(short Decade, stDate Date) {
    Date.Year += Decade * 10;
    return Date;
}

stDate IncreaseDateByOneCentury(stDate Date) {
    Date.Year += 100;
    return Date;
}

stDate IncreaseDateByOneMillennium(stDate Date) {
    Date.Year += 1000;
    return Date;
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
    stDate Date1 = FillDate();

    cout << "\nDate After: \n";
    Date1 = IncreaseDateByOneDay(Date1);
    cout << "\n01-Adding one day is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByXDays(10, Date1);
    cout << "\n02-Adding 10 days is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByOneWeek(Date1);
    cout << "\n03-Adding one week is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByXWeeks(10, Date1);
    cout << "\n04-Adding 10 weeks is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByOneMonth(Date1);
    cout << "\n05-Adding one month is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByXMonths(5, Date1);
    cout << "\n06-Adding 5 months is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByOneYear(Date1);
    cout << "\n07-Adding one year is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByXYears(10, Date1);
    cout << "\n08-Adding 10 Years is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByXYearsFaster(10, Date1);
    cout << "\n09-Adding 10 Years (faster) is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByOneDecade(Date1);
    cout << "\n10-Adding one Decade is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByXDecades(10, Date1);
    cout << "\n11-Adding 10 Decades is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByXDecadesFaster(10, Date1);
    cout << "\n12-Adding 10 Decade (faster) is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByOneCentury(Date1);
    cout << "\n13-Adding One Century is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByOneMillennium(Date1);
    cout << "\n14-Adding One Millennium is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    system("pause>0");
    return 0;
}


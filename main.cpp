#include <iostream>
using namespace std;

bool leap_years(int);
int num_days_years(int, int);
int num_days_month(int, int, int);

int year1, month1, day1, year2, month2, day2, total_num_days;


int main()
{
    cout << "Enter the first date (Year1, month1, day1):" << endl;
    cin >> year1 >> month1 >> day1;
    cout << "Enter the second date (Year2, month2, day2):" << endl;
    cin >> year2 >> month2 >> day2;

    total_num_days = num_days_years(year1, year2) + num_days_month(year2, month2, day2) - num_days_month(year1, month1, day1);

    cout << "Number of days passed: " << total_num_days;
    return 0;
}

 // Boolean function to set the leap year

bool leap_years(int y)
{
     return ((y % 400 == 0) || ((y % 100 != 0) && (y % 4 == 0)));
 }

 // A period from the year of the first date until the second year.
 // Counting all years.

int num_days_years(int y1, int y2)
{
 int days_per_years = 0;
 for (int i = y1; i < y2; i++)
 {
     if (leap_years(i)) days_per_years +=366;
     else days_per_years +=365;
 }
 return days_per_years;
}

// Function to count how many days have passed since the beginning of the year, until a certain day of this year.

int num_days_month (int y, int m, int d)
{
    int num_days = d;
    for (int month = 1; month < m; month++)
    {
        switch(month)
        {
        case 1: num_days +=31; break;
        case 2:
            if (leap_years(y)) num_days +=29;
            else num_days +=28;
            break;
        case 3: num_days +=31; break;
        case 4: num_days +=30; break;
        case 5: num_days +=31; break;
        case 6: num_days +=30; break;
        case 7: num_days +=31; break;
        case 8: num_days +=31; break;
        case 9: num_days +=30; break;
        case 10: num_days +=31; break;
        case 11: num_days +=30; break;
        case 12: num_days +=31; break;
        }
    }
    return num_days;
}

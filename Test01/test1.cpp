#include <iostream>

class DateTime
{
private:
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    int millisecond;
    static const int daysPerMonth[12];

public:
    DateTime(int y = 1970, int m = 1, int d = 1, int h = 0, int mi = 0, int s = 0, int ms = 0)
        : year(y), month(m), day(d), hour(h), minute(mi), second(s), millisecond(ms) {}

    // 修正后的减法运算符重载
    DateTime operator-(const DateTime &other)
    {
        DateTime result;
        int days1 = 0, days2 = 0;

        // 考虑闰年计算天数1
        for (int i = 1970; i < year; ++i)
        {
            days1 += isLeapYear(i) ? 366 : 365;
        }
        for (int i = 0; i < month - 1; ++i)
        {
            days1 += daysPerMonth[i];
        }
        days1 += day;

        // 考虑闰年计算天数2
        for (int i = 1970; i < other.year; ++i)
        {
            days2 += isLeapYear(i) ? 366 : 365;
        }
        for (int i = 0; i < other.month - 1; ++i)
        {
            days2 += daysPerMonth[i];
        }
        days2 += other.day;

        int diff_days = days1 - days2;
        int diff_seconds = (hour - other.hour) * 3600 + (minute - other.minute) * 60 + second - other.second;
        result.year = diff_days / 365;
        diff_days %= 365;
        result.month = diff_days / 30;
        diff_days %= 30;
        result.day = diff_days;
        result.hour = diff_seconds / 3600;
        diff_seconds %= 3600;
        result.minute = diff_seconds / 60;
        result.second = diff_seconds % 60;
        result.millisecond = 0;
        return result;
    }

    // 修正后的加法运算符重载
    DateTime operator+(double seconds)
    {
        DateTime result = *this;
        int total_seconds = second + static_cast<int>(seconds);
        result.second = total_seconds % 60;
        int carry_minutes = total_seconds / 60;
        result.minute += carry_minutes;
        if (result.minute >= 60)
        {
            result.minute %= 60;
            result.hour++;
        }
        result.hour += static_cast<int>(seconds) / 3600;
        if (result.hour >= 24)
        {
            result.hour %= 24;
            result.day++;
            // 修正数组名错误
            if (result.day > daysPerMonth[result.month - 1])
            {
                result.day = 1;
                result.month++;
                if (result.month > 12)
                {
                    result.month = 1;
                    result.year++;
                }
            }
        }
        return result;
    }

    void print()
    {
        std::cout << year << '-' << month << '-' << day << ' ' << hour << ':' << minute << ':' << second << '.'
                  << millisecond << std::endl;
    }

private:
    // 判断是否为闰年的函数
    bool isLeapYear(int year)
    {
        return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    }
};

const int DateTime::daysPerMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
    DateTime dt1(2024, 10, 28, 11, 19, 36, 0);
    DateTime dt2(2024, 11, 27, 10, 18, 30, 0);

    DateTime diff = dt1 - dt2;
    diff.print();

    DateTime sum = dt1 + 3600.5;
    sum.print();

    return 0;
}
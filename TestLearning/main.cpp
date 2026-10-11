#include <iostream>

namespace DZ_1
{
    static bool IsLeapYear(const int year)
    {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    static int DaysInMonth(const int year, const int month)
    {
        const int Days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (month == 2 && IsLeapYear(year)) return 29;
        return Days[month - 1];
    }

    static int DateToDays(const int year, const int month, const int day)
    {
        int Total = 0;
        for (int Y = 1; Y < year; Y++)
            Total += IsLeapYear(Y) ? 366 : 365;
        for (int M = 1; M < month; M++)
            Total += DaysInMonth(year, M);
        Total += day;
        return Total;
    }

    static int DaysBetween(const int y1, const int m1, const int d1, const int y2, const int m2, const int d2)
    {
        return abs(DateToDays(y2, m2, d2) - DateToDays(y1, m1, d1));
    }
}

namespace DZ_2
{
    static float AverageArithmeticArr(const float arr[], const int& size) 
    {
        float Sum = 0;
       
        for (int i = 0; i < size; ++i)
        {
            Sum += arr[i];
        }
        
        return Sum / static_cast<float>(size);
    }
}

namespace DZ_3
{
    struct ElementCounts 
    {
        int Pos = 0;
        int Neg = 0;
        int Zero = 0;
    };
    
    static ElementCounts GetCountElement(const float arr[], const int size)
    {
        ElementCounts Callback;
        
        for (int i = 0; i < size; ++i) 
        {
            if (arr[i] > 0) Callback.Pos++;
            else if (arr[i] < 0) Callback.Neg++;
            else Callback.Zero++;
        }
        
        return Callback; 
    }
}

int main()
{
    std::cout << DZ_1::DaysBetween(2024, 1, 1, 2024, 12, 31) << '\n';
    constexpr float Arr[] = {10.f, 10.f, 10.f, -10.f, 0.f};
    std::cout << DZ_2::AverageArithmeticArr(Arr, std::size(Arr)) << '\n';
    DZ_3::ElementCounts Callback = DZ_3::GetCountElement(Arr, std::size(Arr));
    std::cout << "Zero: " << Callback.Zero << " Pos: " << Callback.Pos << " Neg: " << Callback.Neg <<'\n';
    
    return 0;
}

//
// Created by miaohaochu on 2023/10/25.
//
#include "date.h"
#include "boost/format.hpp"
namespace muduoExp {
    namespace detail {
        int getJulianDayNum(int year, int month, int day) {
            int a = (14 - month) / 12;
            int y = year + 4800 - a;
            int m = month + 12 * a - 3;
            return day + (153*m + 2) / 5 + y*365 + y/4 - y/100 + y/400 - 32045;
        }
    }
    using namespace detail;
    const int Date::kJulianDayOf1970_01_01 = detail::getJulianDayNum(1970,1,1);
    Date::Date(int year, int month, int day)
    :julianDayNumber_(getJulianDayNum(year,month,day)){}
    Date::Date(struct tm& t)
            :julianDayNumber_(getJulianDayNum(
                    t.tm_year + 1900,
                    t.tm_mon+1,
                    t.tm_mday
                    )){}

    string Date::to_string  () const {
        char buff[32];
        YearMonthDay ymd(Date::getYearMonthDay(julianDayNumber_));
        snprintf(buff, sizeof buff, "%4d-%02d-%02d",ymd.year,ymd.month,ymd.day);
        return { buff};
    }
//    const char* Date::to_c_str() const {
//        char buff[32];
//        YearMonthDay ymd(Date::getYearMonthDay(this->julianDayNumber_));
//        snprintf(buff, sizeof buff, "%4d-%02d-%02d",ymd.year,ymd.month,ymd.day);
//        return buff;
//    }
    Date::YearMonthDay Date::getYearMonthDay(int julianDayNum)  {
        int a = julianDayNum + 32044;
        int b = (4 * a + 3) / 146097;
        int c = a - ((b * 146097) / 4);
        int d = (4 * c + 3) / 1461;
        int e = c - ((1461 * d) / 4);
        int m = (5 * e + 2) / 153;
        Date::YearMonthDay ymd{};
        ymd.day = e - ((153 * m + 2) / 5) + 1;
        ymd.month = m + 3 - 12 * (m / 10);
        ymd.year = b * 100 + d - 4800 + (m / 10);
        return ymd;
    }

}


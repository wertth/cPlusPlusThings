//
// Created by miaohaochu on 2023/10/24.
//

#ifndef CPLUSPLUSTHINGS_DATE_H
#define CPLUSPLUSTHINGS_DATE_H
#include "copyable.h"
#include "string"
struct tm;
namespace muduoExp {
    using std::string;

    class Date: muduoExp::copyable {
    public:
        struct YearMonthDay {
            int year;
            int month;
            int day;
        };

        static const int kDaysPerWeek = 7;
        static const int kJulianDayOf1970_01_01;
    public:
        Date() = default;
        Date(int year, int month, int day);
        explicit Date(int julianDay):julianDayNumber_(julianDay){};
        explicit Date(struct tm& t);
    public:
        static YearMonthDay getYearMonthDay(int julianDayNum);
        YearMonthDay getYearMonthDay() const {
            return getYearMonthDay(julianDayNumber_);
        }
        [[nodiscard]] string to_string() const;
        inline int getYear() const {
            return getYearMonthDay().year;
        }
        inline int getMonth() const {
            return getYearMonthDay().month;
        }
        inline int getDay() const {
            return getYearMonthDay().day;
        }
        inline int dayOfWeek() const {
            return julianDayNumber_ % kDaysPerWeek;
        }
        inline int getJulianDayNumber() const {
            return julianDayNumber_;
        }
//        const char* to_c_str() const;
    private:
        int julianDayNumber_ = 0;
    };
}

#endif //CPLUSPLUSTHINGS_DATE_H

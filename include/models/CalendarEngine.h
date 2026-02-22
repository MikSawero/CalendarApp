#pragma once
#include <chrono>
#include <vector>
#include <string>

namespace CalendarApp {

    struct DayInfo {
        int dayNumber;
        bool isCurrentMonth;
        bool hasEvents;
    };

    class CalendarEngine {
    public:
        static std::vector<DayInfo> getMonthGrid(int year, int month);

        static std::chrono::year_month_day getToday();

    };
}
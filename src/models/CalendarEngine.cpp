#include "CalendarEngine.h"

using namespace std::chrono;

namespace CalendarApp {

    std::vector<DayInfo> CalendarEngine::getMonthGrid(int y, int m) {
        std::vector<DayInfo> grid;

        year_month_day firstDay{ year{y}, month{unsigned(m)}, day{1} };

        weekday wd{ sys_days{firstDay} };
		int offset = (wd.iso_encoding() - 1); // ISO: Mon=1, Sun=7 -> changing to 0-based index with Monday=0, Sunday=6

        for (int i = 0; i < offset; ++i) {
            grid.push_back({ 0, false, false });
        }

        auto lastDayNum = unsigned((year_month{ year{y}, month{unsigned(m)} } / last).day());

        for (int d = 1; d <= lastDayNum; ++d) {
            grid.push_back({ d, true, false });
        }

        return grid;
    }

    year_month_day CalendarEngine::getToday() {
        return year_month_day{ floor<days>(system_clock::now()) };
    }
}
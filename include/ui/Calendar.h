#pragma once

#include <QtWidgets/QMainWindow>

#include "ui_Calendar.h"
#include "DatabaseManager.h"

namespace CalendarApp {
    class Calendar : public QMainWindow
    {
        Q_OBJECT

    public:
        Calendar(QWidget* parent = nullptr);
        ~Calendar();

    private:
        Ui::CalendarClass ui;
		DatabaseManager& m_db = DatabaseManager::instance();

        void refreshCalendar(int year, int month);

        int currentYear = 2026;
        int currentMonth = 2;

        void onPrevMonthClicked();
		void onNextMonthClicked();
    };
}


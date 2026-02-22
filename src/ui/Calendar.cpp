#include "Calendar.h"
#include "CalendarEngine.h"
#include "DatabaseManager.h"
#include "DayWindow.h"

#include <QPushButton>
#include <QGridLayout>
#include <QDate>
#include <QInputDialog>
#include "string"

namespace CalendarApp {
    Calendar::Calendar(QWidget* parent)
        : QMainWindow(parent)
    {
        ui.setupUi(this);
        auto today = CalendarApp::CalendarEngine::getToday();

        currentYear = static_cast<int>(today.year());
        currentMonth = static_cast<unsigned>(today.month());

        connect(ui.prevMonthButton, &QPushButton::clicked, this, &Calendar::onPrevMonthClicked);
        connect(ui.nextMonthButton, &QPushButton::clicked, this, &Calendar::onNextMonthClicked);
		this->refreshCalendar(currentYear, currentMonth);
    }

    Calendar::~Calendar()
    {
    }

    void Calendar::onPrevMonthClicked() {
        if (currentMonth == 1) {
            currentMonth = 12;
            currentYear--;
        }
        else {
            currentMonth--;
        }
        refreshCalendar(currentYear, currentMonth);
    }

    void Calendar::onNextMonthClicked() {
        if (currentMonth == 12) {
            currentMonth = 1;
            currentYear++;
        }
        else {
            currentMonth++;
        }
        refreshCalendar(currentYear, currentMonth);
	}

    void Calendar::refreshCalendar(int year, int month) {

        
        auto days = CalendarApp::CalendarEngine::getMonthGrid(year, month);
		ui.monthYearLabel->setText(QString("%1 %2").arg(month).arg(year));

        QLocale eng(QLocale::English);

        QString monthName = eng.standaloneMonthName(month, QLocale::LongFormat);

        ui.monthYearLabel->setText(monthName + " " + QString::number(year));

        std::string dayNames[7] = { "Mon", "Tu", "Wed", "Thu", "Fri", "Sat", "Sun" };
        if (ui.calendarContainer->layout()) {
            QLayoutItem* item;
            while ((item = ui.calendarContainer->layout()->takeAt(0)) != nullptr) {
                delete item->widget();
                delete item;
            }
        }
        else {
            ui.calendarContainer->setLayout(new QGridLayout());
        }

        QGridLayout* layout = qobject_cast<QGridLayout*>(ui.calendarContainer->layout());

		for (const auto& dayName : dayNames) {
            QLabel* lbl = new QLabel(QString::fromStdString(dayName));
            lbl->setAlignment(Qt::AlignCenter);
            layout->addWidget(lbl, 0, &dayName - dayNames);
        }
        int row = 1;
        int col = 0;

        for (const auto& dayInfo : days) {
            if (dayInfo.dayNumber > 0) {
                QPushButton* btn = new QPushButton(QString::number(dayInfo.dayNumber));

                btn->setMinimumSize(40, 40);

                connect(btn, &QPushButton::clicked, [this, dayInfo]() {
                    qDebug() << "Clicked: " << dayInfo.dayNumber;
                    });

                layout->addWidget(btn, row, col);
                connect(btn, &QPushButton::clicked, [this, dayInfo, year, month]() {
                    QDate selectedDate(year, month, dayInfo.dayNumber);
                    QString dateStr = selectedDate.toString("dd.MM.yyyy");

                    DayWindow dialog(this, selectedDate);

                    dialog.setWindowTitle("Events: " + dateStr);
                    
                    if (dialog.exec() == QDialog::Accepted) {
						
                        qDebug() << "Saved data for: " << dateStr;
                    }
                    else {
                        qDebug() << "Canceled.";
                    }
                    });
            }

            col++;
            if (col > 6) {
                col = 0;
                row++;
            }


        }
    }
}


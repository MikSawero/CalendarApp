/********************************************************************************
** Form generated from reading UI file 'Calendar.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALENDAR_H
#define UI_CALENDAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CalendarClass
{
public:
    QWidget *Calendar;
    QVBoxLayout *verticalLayout;
    QWidget *monthControlerWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *monthYearLabel;
    QPushButton *prevMonthButton;
    QPushButton *nextMonthButton;
    QWidget *calendarContainer;
    QGridLayout *gridLayout;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CalendarClass)
    {
        if (CalendarClass->objectName().isEmpty())
            CalendarClass->setObjectName("CalendarClass");
        CalendarClass->resize(602, 300);
        CalendarClass->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        CalendarClass->setDockOptions(QMainWindow::DockOption::AllowTabbedDocks|QMainWindow::DockOption::AnimatedDocks);
        Calendar = new QWidget(CalendarClass);
        Calendar->setObjectName("Calendar");
        verticalLayout = new QVBoxLayout(Calendar);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        monthControlerWidget = new QWidget(Calendar);
        monthControlerWidget->setObjectName("monthControlerWidget");
        monthControlerWidget->setMinimumSize(QSize(571, 56));
        monthControlerWidget->setMaximumSize(QSize(571, 56));
        horizontalLayout = new QHBoxLayout(monthControlerWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        monthYearLabel = new QLabel(monthControlerWidget);
        monthYearLabel->setObjectName("monthYearLabel");
        monthYearLabel->setMaximumSize(QSize(16777215, 90));
        monthYearLabel->setFrameShape(QFrame::Shape::Box);
        monthYearLabel->setIndent(-1);

        horizontalLayout->addWidget(monthYearLabel);

        prevMonthButton = new QPushButton(monthControlerWidget);
        prevMonthButton->setObjectName("prevMonthButton");

        horizontalLayout->addWidget(prevMonthButton);

        nextMonthButton = new QPushButton(monthControlerWidget);
        nextMonthButton->setObjectName("nextMonthButton");

        horizontalLayout->addWidget(nextMonthButton);


        verticalLayout->addWidget(monthControlerWidget);

        calendarContainer = new QWidget(Calendar);
        calendarContainer->setObjectName("calendarContainer");
        gridLayout = new QGridLayout(calendarContainer);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");

        verticalLayout->addWidget(calendarContainer);

        CalendarClass->setCentralWidget(Calendar);
        menuBar = new QMenuBar(CalendarClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 602, 21));
        CalendarClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CalendarClass);
        mainToolBar->setObjectName("mainToolBar");
        CalendarClass->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CalendarClass);
        statusBar->setObjectName("statusBar");
        CalendarClass->setStatusBar(statusBar);

        retranslateUi(CalendarClass);

        QMetaObject::connectSlotsByName(CalendarClass);
    } // setupUi

    void retranslateUi(QMainWindow *CalendarClass)
    {
        CalendarClass->setWindowTitle(QCoreApplication::translate("CalendarClass", "Calendar", nullptr));
        monthYearLabel->setText(QCoreApplication::translate("CalendarClass", "2026 January", nullptr));
        prevMonthButton->setText(QCoreApplication::translate("CalendarClass", "Previous Month", nullptr));
        nextMonthButton->setText(QCoreApplication::translate("CalendarClass", "Next Month", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CalendarClass: public Ui_CalendarClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALENDAR_H

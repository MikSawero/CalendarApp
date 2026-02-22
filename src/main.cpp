#include "Calendar.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    CalendarApp::Calendar window;

    window.setStyleSheet(R"(
        QMainWindow { background-color: #2b2b2b; }
        QLabel { color: #ffffff; font-size: 18px; font-weight: bold; }
        QPushButton { 
            background-color: #3d3d3d; 
            color: white; 
            border-radius: 5px; 
            border: 1px solid #555;
            padding: 5px;
        }
        QPushButton:hover { background-color: #4d4d4d; border: 1px solid #0078d7; }
        QPushButton:pressed { background-color: #0078d7; }
    
        #calendarContainer QPushButton {
            font-size: 14px;
            min-width: 40px;
            min-height: 40px;
        }
    )");

    window.show();
    return app.exec();
}

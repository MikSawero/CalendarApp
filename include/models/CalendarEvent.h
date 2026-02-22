#pragma once
#include <QString>
#include <QDateTime>

struct CalendarEvent {
    int id = -1;
    QString title;
    QString note;
    QDateTime startDate;
    QDateTime endDate;

    QString toString() const {
        return QString("[%1 - %2] %3")
            .arg(startDate.toString("dd.MM HH:mm"))
            .arg(endDate.toString("dd.MM HH:mm"))
            .arg(title);
    }
};
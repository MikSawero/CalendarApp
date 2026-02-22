#pragma once
#include <QtSql>
#include <QString>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>

#include "CalendarEvent.h"

class DatabaseManager : public QObject{
    Q_OBJECT
public:
    static DatabaseManager& instance() {
        static DatabaseManager _instance;
        return _instance;
    }
    DatabaseManager(const DatabaseManager&) = delete;
private:
    DatabaseManager();
    QSqlDatabase db;

public:
    QList<CalendarEvent> getEventsForDate(const QDate& date);
    bool addEvent(const QString& title, const QDate& start, const QDate& end, const QString& text);
    bool updateEvent(int id, const QString& title, const QDate& start, const QDate& end, const QString& text);
    bool deleteEvent(int id);
    QString getNotesForDate(const QDate& date);

signals:
    void dataChanged();
};
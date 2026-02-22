#include "DatabaseManager.h"
#include "CalendarEvent.h"
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

DatabaseManager::DatabaseManager() {
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setDatabaseName("CalendarDB");
    db.setUserName("postgres");
    db.setPassword("123321");
    db.setPort(5432);

    if (!db.open()) {
        qDebug() << "CONNECTION ERROR: " << db.lastError().text();
    }
    else {
        QSqlQuery query;
        query.exec("CREATE TABLE IF NOT EXISTS events ("
            "id SERIAL PRIMARY KEY, "
            "title TEXT, "
            "start_date DATE, "
            "end_date DATE, "
            "content TEXT)");
        qDebug() << "Succesfully connected to DB";
    }
}

QList<CalendarEvent> DatabaseManager::getEventsForDate(const QDate& date) {
    QList<CalendarEvent> list;
    QSqlQuery query;
    query.prepare("SELECT id, title, content, start_date, end_date FROM events "
        "WHERE :date BETWEEN start_date AND end_date");
    query.bindValue(":date", date);

    if (query.exec()) {
        while (query.next()) {
            CalendarEvent ev;
            ev.id = query.value("id").toInt();
            ev.title = query.value("title").toString();
            ev.note = query.value("content").toString();
            ev.startDate = query.value("start_date").toDateTime();
            ev.endDate = query.value("end_date").toDateTime();
            list.append(ev);
        }
    }
    else {
        qDebug() << "Error while collecting events from DB" << query.lastError().text();
    }
    return list;
}

bool DatabaseManager::addEvent(const QString& title, const QDate& start, const QDate& end, const QString& text) {
    QSqlQuery query;
    query.prepare("INSERT INTO events (title, start_date, end_date, content) "
        "VALUES (:title, :start, :end, :content)");
    query.bindValue(":title", title);
    query.bindValue(":start", start);
    query.bindValue(":end", end);
    query.bindValue(":content", text);

    bool ok = query.exec();
    if (ok) emit dataChanged();
    return ok;
}

bool DatabaseManager::updateEvent(int id, const QString& title, const QDate& start, const QDate& end, const QString& text) {
    QSqlQuery query;
    query.prepare("UPDATE events SET title = :title, start_date = :start, "
        "end_date = :end, content = :content WHERE id = :id");
    query.bindValue(":title", title);
    query.bindValue(":start", start);
    query.bindValue(":end", end);
    query.bindValue(":content", text);
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "BŁĄD SQL:" << query.lastError().text();
        return false;
    }

    if (query.numRowsAffected() == 0) {
        qDebug() << "OSTRZEŻENIE: Nie znaleziono wiersza o ID:" << id;
    }

    emit dataChanged();
    return true;
}

bool DatabaseManager::deleteEvent(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM events WHERE id = :id");
    query.bindValue(":id", id);

    bool ok = query.exec();
    if (ok) emit dataChanged();
    return ok;
}

QString DatabaseManager::getNotesForDate(const QDate& date) {
    QSqlQuery query;
    query.prepare("SELECT title FROM events WHERE :date BETWEEN start_date AND end_date");
    query.bindValue(":date", date);
    

    QStringList titles;
    if (query.exec()) {
        while (query.next()) titles << query.value(0).toString();
    }
    return titles.join(", ");
}
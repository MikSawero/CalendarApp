#pragma once
#include <qstringlistmodel.h>

#include <QDialog>
#include <QWidget>
#include "ui_DayWindow.h"
#include "CalendarEvent.h"
#include "DatabaseManager.h"

class DayWindow : public QDialog
{
	Q_OBJECT

public:
	DayWindow(QWidget *parent = nullptr, QDate date=QDate::currentDate());
	~DayWindow();


private:
	Ui::DayWindowClass ui;
	QList<CalendarEvent> events;

	QDate selectedDate;

	DatabaseManager* m_db;

	QStringListModel* model;
	QStringList items;  

	void updateUI();

	void on_exitButton_clicked();

	void on_addNewAttachmentButton_clicked();
	void on_deleteAttachmentButton_clicked();
	void on_editAttachmentButton_clicked();

	void onElementDoubleClicked(const QModelIndex& index);
};


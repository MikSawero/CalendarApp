#pragma once

#include <QDialog>
#include "ui_EventEditorDialog.h"
#include "CalendarEvent.h"

class EventEditorDialog : public QDialog
{
	Q_OBJECT

public:
	EventEditorDialog(QWidget *parent = nullptr, QDate date = QDate::currentDate());
	EventEditorDialog(QWidget* parent, CalendarEvent ev);
	~EventEditorDialog();

	void setEvent(const CalendarEvent& ev);
	CalendarEvent getEvent() const;
private:
	Ui::EventEditorDialogClass ui;
	
	int m_currentID = -1;
};


#include "EventEditorDialog.h"
#include "CalendarEvent.h"
#include <QDateTime>
#include <QTime>

EventEditorDialog::EventEditorDialog(QWidget *parent, QDate date)
	: QDialog(parent)
{
	ui.setupUi(this);
	ui.startDate->setDateTime(QDateTime(date, QTime(0,0)));
	ui.endDate->setDateTime(QDateTime(date.addDays(1), QTime(0,0)));

    connect(ui.okButton, &QPushButton::clicked, this, &QDialog::accept);
    connect(ui.cancelButton, &QPushButton::clicked, this, &QDialog::reject);
}

EventEditorDialog::EventEditorDialog(QWidget* parent, CalendarEvent ev)
    : QDialog(parent)
{
    ui.setupUi(this);
	ui.title->setText(ev.title);
    ui.note->setText(ev.note);
	ui.startDate->setDateTime(ev.startDate);
	ui.endDate->setDateTime(ev.endDate);

    connect(ui.okButton, &QPushButton::clicked, this, &QDialog::accept);
    connect(ui.cancelButton, &QPushButton::clicked, this, &QDialog::reject);
}

EventEditorDialog::~EventEditorDialog()
{}

void EventEditorDialog::setEvent(const CalendarEvent& ev) {
    m_currentID = ev.id;
    ui.title->setText(ev.title);
    ui.note->setText(ev.note);
    ui.startDate->setDateTime(ev.startDate);
    ui.endDate->setDateTime(ev.endDate);
}

CalendarEvent EventEditorDialog::getEvent() const {
    CalendarEvent ev;
    ev.id = m_currentID;
    ev.title = ui.title->text();
    ev.note = ui.note->toPlainText();
    ev.startDate = ui.startDate->dateTime();
    ev.endDate = ui.endDate->dateTime();
    return ev;
}
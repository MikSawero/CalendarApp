#include "DayWindow.h"
#include "EventEditorDialog.h"
#include "DatabaseManager.h"
#include <QMessageBox>
#include <QDebug>
#include <algorithm>

DayWindow::DayWindow(QWidget* parent, QDate date)
    : QDialog(parent), selectedDate(date)
{
    ui.setupUi(this);
    ui.currentDate->setText("Events for: " + date.toString("dd.MM.yyyy"));

    this->setStyleSheet(R"(
        QDialog { background-color: #2b2b2b; }
        QListView { 
            background-color: #3d3d3d; 
            color: white; 
            border: 1px solid #555;
            font-size: 14px;
        }
        QListView::item:selected {
            background-color: #0078d7;
        }
    )");

    model = new QStringListModel(this);
    ui.attachmentsListView->setModel(model);
    ui.attachmentsListView->setSelectionMode(QAbstractItemView::ExtendedSelection);

    m_db = &DatabaseManager::instance();

    events = m_db->getEventsForDate(selectedDate);
    updateUI();

    connect(ui.attachmentsListView, &QListView::doubleClicked,
        this, &DayWindow::onElementDoubleClicked);
    connect(ui.exitButton, &QPushButton::clicked, this, &DayWindow::on_exitButton_clicked);
    connect(ui.addNewAttachment, &QPushButton::clicked, this, &DayWindow::on_addNewAttachmentButton_clicked);
    connect(ui.deleteAttachmentButton, &QPushButton::clicked, this, &DayWindow::on_deleteAttachmentButton_clicked);
    connect(ui.editAttachmentButton, &QPushButton::clicked, this, &DayWindow::on_editAttachmentButton_clicked);
}

DayWindow::~DayWindow() {}

void DayWindow::on_exitButton_clicked() {
    this->accept();
}

void DayWindow::updateUI() {
    QStringList displayNames;
    for (const auto& ev : events) {
        
        displayNames << (ev.title.isEmpty() ? "Null" : ev.title);
    }
    model->setStringList(displayNames);
}

void DayWindow::on_addNewAttachmentButton_clicked() {
    EventEditorDialog dlg(this);
    CalendarEvent temp;
    temp.startDate = QDateTime(selectedDate, QTime(12, 0));
    temp.endDate = QDateTime(selectedDate, QTime(13, 0));
    dlg.setEvent(temp);

    if (dlg.exec() == QDialog::Accepted) {
        CalendarEvent newEv = dlg.getEvent();

        if (m_db->addEvent(newEv.title, newEv.startDate.date(), newEv.endDate.date(), newEv.note)) {

            events.append(newEv);
            updateUI();
        }
        else {
            QMessageBox::critical(this, "Error", "Couldn't save data to database.");
        }
    }
}

void DayWindow::on_deleteAttachmentButton_clicked() {
    QModelIndexList selectedIndexes = ui.attachmentsListView->selectionModel()->selectedIndexes();

    if (selectedIndexes.isEmpty()) {
        QMessageBox::warning(this, "Error", "Select minimum one element to delete");
        return;
    }

    std::sort(selectedIndexes.begin(), selectedIndexes.end(),
        [](const QModelIndex& a, const QModelIndex& b) {
            return a.row() > b.row();
        });

    for (const QModelIndex& index : selectedIndexes) {
        int row = index.row();
        m_db->deleteEvent(events[row].id);
        events.removeAt(row);
    }
    updateUI();
}

void DayWindow::on_editAttachmentButton_clicked() {
    QModelIndex index = ui.attachmentsListView->currentIndex();
    if (!index.isValid()) return;

    int row = index.row();

    if (row >= events.size()) return;

    EventEditorDialog dlg(this);
    dlg.setWindowTitle("Edytuj wydarzenie");
    dlg.setEvent(events[row]);

    if (dlg.exec() == QDialog::Accepted) {
        CalendarEvent updatedEv = dlg.getEvent();

        m_db->updateEvent(updatedEv.id,
            updatedEv.title,
            updatedEv.startDate.date(),
            updatedEv.endDate.date(),
            updatedEv.note);
        events[row] = updatedEv;
        updateUI();
        qDebug() << "Saved Attachment";
    } else {
        qDebug() << "Canceled";
    }
}

void DayWindow::onElementDoubleClicked(const QModelIndex& index) {
    on_editAttachmentButton_clicked();
}
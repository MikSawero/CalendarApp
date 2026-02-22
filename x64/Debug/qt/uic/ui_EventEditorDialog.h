/********************************************************************************
** Form generated from reading UI file 'EventEditorDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVENTEDITORDIALOG_H
#define UI_EVENTEDITORDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_EventEditorDialogClass
{
public:
    QFormLayout *formLayout;
    QLineEdit *title;
    QTextEdit *note;
    QDateTimeEdit *startDate;
    QDateTimeEdit *endDate;
    QHBoxLayout *horizontalLayout;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *EventEditorDialogClass)
    {
        if (EventEditorDialogClass->objectName().isEmpty())
            EventEditorDialogClass->setObjectName("EventEditorDialogClass");
        EventEditorDialogClass->resize(296, 297);
        formLayout = new QFormLayout(EventEditorDialogClass);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName("formLayout");
        title = new QLineEdit(EventEditorDialogClass);
        title->setObjectName("title");

        formLayout->setWidget(0, QFormLayout::ItemRole::SpanningRole, title);

        note = new QTextEdit(EventEditorDialogClass);
        note->setObjectName("note");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, note);

        startDate = new QDateTimeEdit(EventEditorDialogClass);
        startDate->setObjectName("startDate");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, startDate);

        endDate = new QDateTimeEdit(EventEditorDialogClass);
        endDate->setObjectName("endDate");

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, endDate);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, -1, -1);
        okButton = new QPushButton(EventEditorDialogClass);
        okButton->setObjectName("okButton");

        horizontalLayout->addWidget(okButton);

        cancelButton = new QPushButton(EventEditorDialogClass);
        cancelButton->setObjectName("cancelButton");

        horizontalLayout->addWidget(cancelButton);


        formLayout->setLayout(5, QFormLayout::ItemRole::SpanningRole, horizontalLayout);


        retranslateUi(EventEditorDialogClass);

        QMetaObject::connectSlotsByName(EventEditorDialogClass);
    } // setupUi

    void retranslateUi(QDialog *EventEditorDialogClass)
    {
        EventEditorDialogClass->setProperty("Edit Event", QVariant(QCoreApplication::translate("EventEditorDialogClass", "EventEditorDialog", nullptr)));
        okButton->setText(QCoreApplication::translate("EventEditorDialogClass", "Ok", nullptr));
        cancelButton->setText(QCoreApplication::translate("EventEditorDialogClass", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EventEditorDialogClass: public Ui_EventEditorDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVENTEDITORDIALOG_H

/********************************************************************************
** Form generated from reading UI file 'DayWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DAYWINDOW_H
#define UI_DAYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DayWindowClass
{
public:
    QGridLayout *gridLayout;
    QLabel *currentDate;
    QListView *attachmentsListView;
    QVBoxLayout *verticalLayout;
    QPushButton *addNewAttachment;
    QPushButton *editAttachmentButton;
    QPushButton *deleteAttachmentButton;
    QPushButton *exitButton;

    void setupUi(QDialog *DayWindowClass)
    {
        if (DayWindowClass->objectName().isEmpty())
            DayWindowClass->setObjectName("DayWindowClass");
        DayWindowClass->resize(537, 275);
        gridLayout = new QGridLayout(DayWindowClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        currentDate = new QLabel(DayWindowClass);
        currentDate->setObjectName("currentDate");

        gridLayout->addWidget(currentDate, 0, 0, 1, 1);

        attachmentsListView = new QListView(DayWindowClass);
        attachmentsListView->setObjectName("attachmentsListView");

        gridLayout->addWidget(attachmentsListView, 3, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        addNewAttachment = new QPushButton(DayWindowClass);
        addNewAttachment->setObjectName("addNewAttachment");

        verticalLayout->addWidget(addNewAttachment);

        editAttachmentButton = new QPushButton(DayWindowClass);
        editAttachmentButton->setObjectName("editAttachmentButton");

        verticalLayout->addWidget(editAttachmentButton);

        deleteAttachmentButton = new QPushButton(DayWindowClass);
        deleteAttachmentButton->setObjectName("deleteAttachmentButton");

        verticalLayout->addWidget(deleteAttachmentButton);

        exitButton = new QPushButton(DayWindowClass);
        exitButton->setObjectName("exitButton");

        verticalLayout->addWidget(exitButton);


        gridLayout->addLayout(verticalLayout, 3, 2, 1, 1);


        retranslateUi(DayWindowClass);

        QMetaObject::connectSlotsByName(DayWindowClass);
    } // setupUi

    void retranslateUi(QDialog *DayWindowClass)
    {
        DayWindowClass->setWindowTitle(QCoreApplication::translate("DayWindowClass", "DayWindow", nullptr));
        currentDate->setText(QCoreApplication::translate("DayWindowClass", "Wydarzenia dla:", nullptr));
        addNewAttachment->setText(QCoreApplication::translate("DayWindowClass", "Add new attachment", nullptr));
        editAttachmentButton->setText(QCoreApplication::translate("DayWindowClass", "Edit Attachment", nullptr));
        deleteAttachmentButton->setText(QCoreApplication::translate("DayWindowClass", "Delete attachment", nullptr));
        exitButton->setText(QCoreApplication::translate("DayWindowClass", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DayWindowClass: public Ui_DayWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DAYWINDOW_H

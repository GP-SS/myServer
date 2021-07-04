/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QTextBrowser *text_receive;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QTextEdit *text_send;
    QLineEdit *edt_port;
    QLabel *label_2;
    QPushButton *btn_initSocket;
    QPushButton *btn_send;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(647, 454);
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(100, 60, 280, 151));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        text_receive = new QTextBrowser(groupBox);
        text_receive->setObjectName(QString::fromUtf8("text_receive"));

        gridLayout->addWidget(text_receive, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(100, 230, 280, 151));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        text_send = new QTextEdit(groupBox_2);
        text_send->setObjectName(QString::fromUtf8("text_send"));

        gridLayout_2->addWidget(text_send, 0, 0, 1, 1);

        edt_port = new QLineEdit(Widget);
        edt_port->setObjectName(QString::fromUtf8("edt_port"));
        edt_port->setGeometry(QRect(470, 260, 61, 21));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(420, 260, 72, 15));
        btn_initSocket = new QPushButton(Widget);
        btn_initSocket->setObjectName(QString::fromUtf8("btn_initSocket"));
        btn_initSocket->setGeometry(QRect(420, 297, 91, 31));
        btn_send = new QPushButton(Widget);
        btn_send->setObjectName(QString::fromUtf8("btn_send"));
        btn_send->setGeometry(QRect(420, 340, 81, 31));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        groupBox->setTitle(QApplication::translate("Widget", "\346\216\245\346\224\266\347\252\227\345\217\243", nullptr));
        groupBox_2->setTitle(QApplication::translate("Widget", "\345\217\221\351\200\201\347\252\227\345\217\243", nullptr));
        label_2->setText(QApplication::translate("Widget", "\347\253\257\345\217\243\345\217\267", nullptr));
        btn_initSocket->setText(QApplication::translate("Widget", "\345\210\235\345\247\213\345\214\226Socket", nullptr));
        btn_send->setText(QApplication::translate("Widget", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H

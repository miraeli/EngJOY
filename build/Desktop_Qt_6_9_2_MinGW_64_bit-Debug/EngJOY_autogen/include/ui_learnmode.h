/********************************************************************************
** Form generated from reading UI file 'learnmode.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEARNMODE_H
#define UI_LEARNMODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LearnMode
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *wordLabel;
    QPushButton *choiceButton1;
    QPushButton *choiceButton2;
    QPushButton *choiceButton3;
    QPushButton *choiceButton4;
    QPushButton *backButton;
    QLabel *resultLabel;

    void setupUi(QWidget *LearnMode)
    {
        if (LearnMode->objectName().isEmpty())
            LearnMode->setObjectName("LearnMode");
        LearnMode->resize(619, 449);
        widget = new QWidget(LearnMode);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(210, 50, 191, 331));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        wordLabel = new QLabel(widget);
        wordLabel->setObjectName("wordLabel");

        verticalLayout->addWidget(wordLabel);

        choiceButton1 = new QPushButton(widget);
        choiceButton1->setObjectName("choiceButton1");

        verticalLayout->addWidget(choiceButton1);

        choiceButton2 = new QPushButton(widget);
        choiceButton2->setObjectName("choiceButton2");

        verticalLayout->addWidget(choiceButton2);

        choiceButton3 = new QPushButton(widget);
        choiceButton3->setObjectName("choiceButton3");

        verticalLayout->addWidget(choiceButton3);

        choiceButton4 = new QPushButton(widget);
        choiceButton4->setObjectName("choiceButton4");

        verticalLayout->addWidget(choiceButton4);

        backButton = new QPushButton(widget);
        backButton->setObjectName("backButton");

        verticalLayout->addWidget(backButton);

        resultLabel = new QLabel(widget);
        resultLabel->setObjectName("resultLabel");

        verticalLayout->addWidget(resultLabel);


        retranslateUi(LearnMode);

        QMetaObject::connectSlotsByName(LearnMode);
    } // setupUi

    void retranslateUi(QWidget *LearnMode)
    {
        LearnMode->setWindowTitle(QCoreApplication::translate("LearnMode", "Form", nullptr));
        wordLabel->setText(QCoreApplication::translate("LearnMode", "\320\241\320\273\320\276\320\262\320\276 \320\261\321\203\320\264\320\265\321\202 \320\267\320\264\320\265\321\201\321\214", nullptr));
        choiceButton1->setText(QCoreApplication::translate("LearnMode", "PushButton", nullptr));
        choiceButton2->setText(QCoreApplication::translate("LearnMode", "PushButton", nullptr));
        choiceButton3->setText(QCoreApplication::translate("LearnMode", "PushButton", nullptr));
        choiceButton4->setText(QCoreApplication::translate("LearnMode", "PushButton", nullptr));
        backButton->setText(QCoreApplication::translate("LearnMode", "\320\227\320\260\320\262\320\265\321\200\321\210\320\270\321\202\321\214", nullptr));
        resultLabel->setText(QCoreApplication::translate("LearnMode", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LearnMode: public Ui_LearnMode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEARNMODE_H

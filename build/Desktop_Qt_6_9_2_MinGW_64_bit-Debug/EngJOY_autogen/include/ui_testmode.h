/********************************************************************************
** Form generated from reading UI file 'testmode.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTMODE_H
#define UI_TESTMODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestMode
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *wordLabel;
    QLineEdit *answerInput;
    QPushButton *submitButton;
    QLabel *resultLabel;
    QPushButton *finishButton;
    QLabel *progressLabel;

    void setupUi(QWidget *TestMode)
    {
        if (TestMode->objectName().isEmpty())
            TestMode->setObjectName("TestMode");
        TestMode->resize(633, 432);
        widget = new QWidget(TestMode);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(200, 40, 221, 321));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        wordLabel = new QLabel(widget);
        wordLabel->setObjectName("wordLabel");

        verticalLayout->addWidget(wordLabel);

        answerInput = new QLineEdit(widget);
        answerInput->setObjectName("answerInput");

        verticalLayout->addWidget(answerInput);

        submitButton = new QPushButton(widget);
        submitButton->setObjectName("submitButton");

        verticalLayout->addWidget(submitButton);

        resultLabel = new QLabel(widget);
        resultLabel->setObjectName("resultLabel");

        verticalLayout->addWidget(resultLabel);

        finishButton = new QPushButton(widget);
        finishButton->setObjectName("finishButton");

        verticalLayout->addWidget(finishButton);

        progressLabel = new QLabel(widget);
        progressLabel->setObjectName("progressLabel");

        verticalLayout->addWidget(progressLabel);


        retranslateUi(TestMode);

        QMetaObject::connectSlotsByName(TestMode);
    } // setupUi

    void retranslateUi(QWidget *TestMode)
    {
        TestMode->setWindowTitle(QCoreApplication::translate("TestMode", "Form", nullptr));
        wordLabel->setText(QCoreApplication::translate("TestMode", "\320\241\320\273\320\276\320\262\320\276", nullptr));
        submitButton->setText(QCoreApplication::translate("TestMode", "\320\236\321\202\320\262\320\265\321\202\320\270\321\202\321\214", nullptr));
        resultLabel->setText(QCoreApplication::translate("TestMode", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202", nullptr));
        finishButton->setText(QCoreApplication::translate("TestMode", "\320\227\320\260\320\262\320\265\321\200\321\210\320\270\321\202\321\214 \321\202\320\265\321\201\321\202", nullptr));
        progressLabel->setText(QCoreApplication::translate("TestMode", "\320\237\321\200\320\276\320\263\321\200\320\265\321\201\321\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TestMode: public Ui_TestMode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTMODE_H

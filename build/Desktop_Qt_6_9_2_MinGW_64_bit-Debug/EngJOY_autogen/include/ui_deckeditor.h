/********************************************************************************
** Form generated from reading UI file 'deckeditor.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DECKEDITOR_H
#define UI_DECKEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeckEditor
{
public:
    QTableWidget *cardsTable;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *addCardButton;
    QLineEdit *englishWordInput;
    QLineEdit *translationInput;
    QPushButton *removeCardButton;
    QPushButton *backButton;

    void setupUi(QWidget *DeckEditor)
    {
        if (DeckEditor->objectName().isEmpty())
            DeckEditor->setObjectName("DeckEditor");
        DeckEditor->resize(603, 427);
        cardsTable = new QTableWidget(DeckEditor);
        cardsTable->setObjectName("cardsTable");
        cardsTable->setGeometry(QRect(310, 30, 251, 361));
        widget = new QWidget(DeckEditor);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(40, 40, 231, 341));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        addCardButton = new QPushButton(widget);
        addCardButton->setObjectName("addCardButton");

        verticalLayout->addWidget(addCardButton);

        englishWordInput = new QLineEdit(widget);
        englishWordInput->setObjectName("englishWordInput");

        verticalLayout->addWidget(englishWordInput);

        translationInput = new QLineEdit(widget);
        translationInput->setObjectName("translationInput");

        verticalLayout->addWidget(translationInput);

        removeCardButton = new QPushButton(widget);
        removeCardButton->setObjectName("removeCardButton");

        verticalLayout->addWidget(removeCardButton);

        backButton = new QPushButton(widget);
        backButton->setObjectName("backButton");

        verticalLayout->addWidget(backButton);


        retranslateUi(DeckEditor);

        QMetaObject::connectSlotsByName(DeckEditor);
    } // setupUi

    void retranslateUi(QWidget *DeckEditor)
    {
        DeckEditor->setWindowTitle(QCoreApplication::translate("DeckEditor", "Form", nullptr));
        addCardButton->setText(QCoreApplication::translate("DeckEditor", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\272\320\260\321\200\321\202\320\276\321\207\320\272\321\203", nullptr));
        removeCardButton->setText(QCoreApplication::translate("DeckEditor", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\272\320\260\321\200\321\202\320\276\321\207\320\272\321\203", nullptr));
        backButton->setText(QCoreApplication::translate("DeckEditor", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeckEditor: public Ui_DeckEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DECKEDITOR_H

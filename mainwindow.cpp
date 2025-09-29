#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "deckeditor.h"
#include "learnmode.h"
#include "testmode.h"
#include "filemanager.h"
#include <QPushButton>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_deckEditor(nullptr),
    m_learnMode(nullptr),
    m_testMode(nullptr)
{
    ui->setupUi(this);

    connect(ui->editorButton, &QPushButton::clicked, this, &MainWindow::on_editorButton_clicked);
    connect(ui->learnButton, &QPushButton::clicked, this, &MainWindow::on_learnButton_clicked);
    connect(ui->testButton, &QPushButton::clicked, this, &MainWindow::on_testButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
    if (m_deckEditor != nullptr) {
        delete m_deckEditor;
    }
    if (m_learnMode != nullptr) {
        delete m_learnMode;
    }
    if (m_testMode != nullptr) {
        delete m_testMode;
    }
}

void MainWindow::on_editorButton_clicked()
{
    if (m_deckEditor == nullptr) {
        m_deckEditor = new DeckEditor(this);
    }
    m_deckEditor->show();
}

void MainWindow::on_learnButton_clicked()
{
    std::vector<Card> deck = loadDeckFromFile("deck.txt");

    if (deck.empty()) {
        QMessageBox::information(this, "Ошибка", "Колода пуста! Сначала добавьте карточки в редакторе.");
        return;
    }

    if (m_learnMode == nullptr) {
        m_learnMode = new LearnMode(this);
    }

    m_learnMode->startLearning(deck);
    m_learnMode->show();
}

void MainWindow::on_testButton_clicked()
{
    std::vector<Card> deck = loadDeckFromFile("deck.txt");

    if (deck.empty()) {
        QMessageBox::information(this, "Ошибка", "Колода пуста! Сначала добавьте карточки в редакторе.");
        return;
    }

    if (m_testMode == nullptr) {
        m_testMode = new TestMode(this);
    }

    m_testMode->startTest(deck);
    m_testMode->show();
}

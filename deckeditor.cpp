#include "deckeditor.h"
#include "ui_deckeditor.h"
#include "filemanager.h"
#include <QTableWidgetItem>
#include <QMessageBox>

DeckEditor::DeckEditor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeckEditor)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window);

    // Загружаем колоду из файла при запуске редактора
    m_deck = loadDeckFromFile(m_filename.toStdString());

    // Настраиваем таблицу: 2 колонки (Слово и Перевод)
    ui->cardsTable->setColumnCount(2);
    QStringList headers;
    headers << "Английское слово" << "Перевод";
    ui->cardsTable->setHorizontalHeaderLabels(headers);

    // Обновляем таблицу, чтобы показать загруженные карточки
    updateTable();
}

DeckEditor::~DeckEditor()
{
    delete ui;
}

// Функция для обновления данных в таблице на экране
void DeckEditor::updateTable() {
    ui->cardsTable->setRowCount(m_deck.size());

    for (int i = 0; i < m_deck.size(); ++i) {
        ui->cardsTable->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(m_deck[i].getEnglishWord())));
        ui->cardsTable->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(m_deck[i].getTranslation())));
    }
}

void DeckEditor::on_addCardButton_clicked() {
    QString englishWord = ui->englishWordInput->text();
    QString translation = ui->translationInput->text();

    if (englishWord.isEmpty() || translation.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Заполните оба поля!");
        return;
    }

    m_deck.push_back(Card(englishWord.toStdString(), translation.toStdString()));
    saveDeckToFile(m_deck, m_filename.toStdString());
    updateTable();

    ui->englishWordInput->clear();
    ui->translationInput->clear();
}

void DeckEditor::on_removeCardButton_clicked() {
    int currentRow = ui->cardsTable->currentRow();
    if (currentRow == -1) {
        QMessageBox::information(this, "Информация", "Выберите карточку для удаления.");
        return;
    }

    m_deck.erase(m_deck.begin() + currentRow);
    saveDeckToFile(m_deck, m_filename.toStdString());
    updateTable();
}

void DeckEditor::on_backButton_clicked() {
    this->close();
}

#include "learnmode.h"
#include "ui_learnmode.h"
#include "filemanager.h" // Для наших функций getRandomCard и getRandomChoices
#include <QPushButton>
#include <QMessageBox>
#include <QTimer>

LearnMode::LearnMode(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LearnMode)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window); // Делаем окно самостоятельным
}

LearnMode::~LearnMode()
{
    delete ui;
}

void LearnMode::startLearning(const std::vector<Card>& deck) {
    if (deck.size() < 4) {
        QMessageBox::information(this, "Информация", "В колоде должно быть минимум 4 карточки для режима заучивания.");
        this->close();
        return;
    }
    m_deck = deck;
    nextCard(); // Начинаем с первой карточки
}

void LearnMode::nextCard() {
    // Получаем случайную карточку
    m_currentCard = getRandomCard(m_deck);
    // Получаем 4 варианта ответа для нее
    m_currentChoices = getRandomChoices(m_currentCard, m_deck, 4);

    // Отображаем слово на метке
    ui->wordLabel->setText(QString::fromStdString(m_currentCard.getEnglishWord()));
    // Очищаем результат предыдущего раунда
    ui->resultLabel->setText("");

    // Отображаем варианты ответов на кнопках
    for (int i = 0; i < 4 && i < m_currentChoices.size(); ++i) {
        QPushButton* button = nullptr;
        switch (i) {
        case 0: button = ui->choiceButton1; break;
        case 1: button = ui->choiceButton2; break;
        case 2: button = ui->choiceButton3; break;
        case 3: button = ui->choiceButton4; break;
        }
        if (button) {
            button->setText(QString::fromStdString(m_currentChoices[i].getTranslation()));
            button->setEnabled(true); // Включаем кнопку
            // Можно сбросить стиль кнопки на стандартный, если меняли цвет
            button->setStyleSheet("");
        }
    }
}

void LearnMode::checkAnswer(const Card& selectedCard) {
    // Отключаем кнопки, чтобы нельзя было нажать еще раз
    ui->choiceButton1->setEnabled(false);
    ui->choiceButton2->setEnabled(false);
    ui->choiceButton3->setEnabled(false);
    ui->choiceButton4->setEnabled(false);

    // Сравниваем выбранный перевод с правильным
    if (selectedCard.getEnglishWord() == m_currentCard.getEnglishWord()) {
        ui->resultLabel->setText("Верно! ✅");
        // Через секунду автоматически переходим к следующей карточке
        QTimer::singleShot(1000, this, &LearnMode::nextCard);
    } else {
        ui->resultLabel->setText("Неверно! ❌");
        // Можно подсветить правильный ответ зеленым, а неправильный - красным
        // Это задание для следующего шага, пока просто сообщение
    }
}

// РЕАЛИЗАЦИЯ СЛОТОВ ДЛЯ КАЖДОЙ КНОПКИ
void LearnMode::on_choiceButton1_clicked() { checkAnswer(m_currentChoices[0]); }
void LearnMode::on_choiceButton2_clicked() { checkAnswer(m_currentChoices[1]); }
void LearnMode::on_choiceButton3_clicked() { checkAnswer(m_currentChoices[2]); }
void LearnMode::on_choiceButton4_clicked() { checkAnswer(m_currentChoices[3]); }

void LearnMode::on_backButton_clicked() {
    this->close();
}

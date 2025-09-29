#include "testmode.h"
#include "ui_testmode.h"
#include "filemanager.h" // для getRandomCard и перемешивания
#include <QMessageBox>
#include <algorithm> // для std::shuffle
#include <random>    // для std::random_device
#include <QTimer>

TestMode::TestMode(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestMode)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window); // Делаем окно самостоятельным
}

TestMode::~TestMode()
{
    delete ui;
}

void TestMode::startTest(const std::vector<Card>& deck) {
    if (deck.empty()) {
        QMessageBox::information(this, "Ошибка", "Колода пуста! Сначала добавьте карточки в редакторе.");
        this->close();
        return;
    }

    m_deck = deck;
    m_testDeck = deck; // Копируем колоду

    // Перемешиваем колоду для теста
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(m_testDeck.begin(), m_testDeck.end(), g);

    m_currentQuestionIndex = 0;
    m_correctAnswers = 0;
    nextQuestion();
}

void TestMode::nextQuestion() {
    // Проверяем, не закончился ли тест
    if (m_currentQuestionIndex >= m_testDeck.size()) {
        showResults();
        return;
    }

    m_currentCard = m_testDeck[m_currentQuestionIndex];

    // Обновляем интерфейс
    ui->wordLabel->setText(QString::fromStdString(m_currentCard.getEnglishWord()));
    ui->answerInput->clear();
    ui->resultLabel->setText("");
    ui->progressLabel->setText(QString("Вопрос %1 из %2").arg(m_currentQuestionIndex + 1).arg(m_testDeck.size()));

    // Устанавливаем фокус на поле ввода
    ui->answerInput->setFocus();
}

void TestMode::on_submitButton_clicked() {
    QString userAnswer = ui->answerInput->text().trimmed(); // Убираем лишние пробелы
    QString correctAnswer = QString::fromStdString(m_currentCard.getTranslation());

    if (userAnswer.isEmpty()) {
        QMessageBox::information(this, "Ошибка", "Введите ответ!");
        return;
    }

    // Сравниваем ответы (без учета регистра)
    if (userAnswer.compare(correctAnswer, Qt::CaseInsensitive) == 0) {
        ui->resultLabel->setText("Верно! ✅");
        m_correctAnswers++;
    } else {
        ui->resultLabel->setText("Неверно! ❌ Правильный ответ: " + correctAnswer);
    }

    m_currentQuestionIndex++;

    // Ждем 1.5 секунды и переходим к следующему вопросу
    QTimer::singleShot(1500, this, &TestMode::nextQuestion);
}

void TestMode::showResults() {
    int totalQuestions = m_testDeck.size();
    double percentage = (double)m_correctAnswers / totalQuestions * 100;

    QString results = QString("Тест завершен!\n"
                              "Правильных ответов: %1 из %2\n"
                              "Успешность: %3%")
                          .arg(m_correctAnswers).arg(totalQuestions).arg(percentage, 0, 'f', 1);

    QMessageBox::information(this, "Результаты теста", results);
    this->close();
}

void TestMode::on_finishButton_clicked() {
    // Показываем результаты досрочно
    showResults();
}

#ifndef TESTMODE_H
#define TESTMODE_H

#include <QWidget>
#include <vector>
#include "card.h"

namespace Ui {
class TestMode;
}

/**
 * @brief Класс TestMode реализует режим тестирования с вводом перевода вручную
 *
 * Показывает английское слово, пользователь вводит перевод, в конце показывается результат
 */
class TestMode : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор окна режима тестирования
     * @param parent Родительский виджет
     */
    explicit TestMode(QWidget *parent = nullptr);

    /**
     * @brief Деструктор окна режима тестирования
     */
    ~TestMode();

    /**
     * @brief Запускает тест с указанной колодой
     * @param deck Колода карточек для тестирования
     */
    void startTest(const std::vector<Card>& deck);

private slots:
    /**
     * @brief Обработчик нажатия кнопки "Ответить"
     *
     * Проверяет введенный ответ и переходит к следующему вопросу
     */
    void on_submitButton_clicked();

    /**
     * @brief Обработчик нажатия кнопки "Завершить тест"
     *
     * Досрочно завершает тест и показывает результаты
     */
    void on_finishButton_clicked();

private:
    Ui::TestMode *ui;                  ///< Указатель на пользовательский интерфейс
    std::vector<Card> m_deck;          ///< Исходная колода карточек
    std::vector<Card> m_testDeck;      ///< Перемешанная колода для текущего теста
    Card m_currentCard;                ///< Текущая карточка
    int m_currentQuestionIndex;        ///< Номер текущего вопроса
    int m_correctAnswers;              ///< Количество правильных ответов

    /**
     * @brief Переход к следующему вопросу
     *
     * Если вопросы закончились, показывает результаты теста
     */
    void nextQuestion();

    /**
     * @brief Показывает итоговые результаты теста
     */
    void showResults();
};

#endif // TESTMODE_H

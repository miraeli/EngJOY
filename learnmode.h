#ifndef LEARNMODE_H
#define LEARNMODE_H

#include <QWidget>
#include <vector>
#include "card.h"

namespace Ui {
class LearnMode;
}

/**
 * @brief Класс LearnMode реализует режим заучивания слов с выбором из 4 вариантов
 *
 * Показывает английское слово и 4 варианта перевода, один из которых правильный
 */
class LearnMode : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор окна режима заучивания
     * @param parent Родительский виджет
     */
    explicit LearnMode(QWidget *parent = nullptr);

    /**
     * @brief Деструктор окна режима заучивания
     */
    ~LearnMode();

    /**
     * @brief Запускает сессию заучивания с указанной колодой
     * @param deck Колода карточек для заучивания
     */
    void startLearning(const std::vector<Card>& deck);

private slots:
    /// @brief Обработчик нажатия на кнопку выбора 1
    void on_choiceButton1_clicked();
    /// @brief Обработчик нажатия на кнопку выбора 2
    void on_choiceButton2_clicked();
    /// @brief Обработчик нажатия на кнопку выбора 3
    void on_choiceButton3_clicked();
    /// @brief Обработчик нажатия на кнопку выбора 4
    void on_choiceButton4_clicked();
    /// @brief Обработчик нажатия кнопки "Завершить"
    void on_backButton_clicked();

private:
    Ui::LearnMode *ui;                 ///< Указатель на пользовательский интерфейс
    std::vector<Card> m_deck;          ///< Колода для заучивания
    Card m_currentCard;                ///< Текущая карточка, которую угадываем
    std::vector<Card> m_currentChoices;///< Текущие варианты ответов

    /**
     * @brief Переход к следующей карточке
     *
     * Выбирает случайную карточку и генерирует варианты ответов для нее
     */
    void nextCard();

    /**
     * @brief Проверяет выбранный ответ
     * @param selectedCard Выбранная карточка-ответ
     */
    void checkAnswer(const Card& selectedCard);
};

#endif // LEARNMODE_H

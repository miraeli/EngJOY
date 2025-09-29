#ifndef DECKEDITOR_H
#define DECKEDITOR_H

#include <QWidget>
#include <vector>
#include "card.h"

namespace Ui {
class DeckEditor;
}

class QTableWidgetItem;

/**
 * @brief Класс DeckEditor предоставляет интерфейс для редактирования колоды карточек
 *
 * Позволяет добавлять, удалять и просматривать карточки, а также автоматически сохраняет изменения в файл
 */
class DeckEditor : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор окна редактора колод
     * @param parent Родительский виджет
     */
    explicit DeckEditor(QWidget *parent = nullptr);

    /**
     * @brief Деструктор окна редактора колод
     */
    ~DeckEditor();

private slots:
    /**
     * @brief Обработчик нажатия кнопки "Добавить карточку"
     *
     * Добавляет новую карточку в колоду на основе введенных данных и сохраняет в файл
     */
    void on_addCardButton_clicked();

    /**
     * @brief Обработчик нажатия кнопки "Удалить карточку"
     *
     * Удаляет выбранную карточку из колоды и сохраняет изменения в файл
     */
    void on_removeCardButton_clicked();

    /**
     * @brief Обработчик нажатия кнопки "Назад"
     *
     * Закрывает окно редактора и возвращает в главное меню
     */
    void on_backButton_clicked();

private:
    Ui::DeckEditor *ui;                ///< Указатель на пользовательский интерфейс
    std::vector<Card> m_deck;          ///< Текущая колода карточек
    const QString m_filename = "deck.txt";  ///< Имя файла для сохранения колоды

    /**
     * @brief Обновляет таблицу отображения карточек
     *
     * Синхронизирует содержимое таблицы на экране с текущей колодой в памяти
     */
    void updateTable();
};

#endif // DECKEDITOR_H

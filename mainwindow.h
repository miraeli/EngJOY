#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class DeckEditor;
class LearnMode;
class TestMode;

namespace Ui {
class MainWindow;
}

/**
 * @brief Класс MainWindow представляет главное окно приложения EngJOY
 *
 * Содержит меню с кнопками для перехода в различные режимы работы приложения
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор главного окна
     * @param parent Родительский виджет
     */
    explicit MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Деструктор главного окна
     */
    ~MainWindow();

private slots:
    /**
     * @brief Обработчик нажатия кнопки "Редактор колод"
     *
     * Открывает окно редактора для работы с карточками
     */
    void on_editorButton_clicked();

    /**
     * @brief Обработчик нажатия кнопки "Режим заучивания"
     *
     * Открывает окно режима заучивания с выбором из вариантов
     */
    void on_learnButton_clicked();

    /**
     * @brief Обработчик нажатия кнопки "Режим теста"
     *
     * Открывает окно режима тестирования с вводом ответов вручную
     */
    void on_testButton_clicked();

private:
    Ui::MainWindow *ui;        ///< Указатель на пользовательский интерфейс
    DeckEditor *m_deckEditor;  ///< Указатель на окно редактора колод
    LearnMode *m_learnMode;    ///< Указатель на окно режима заучивания
    TestMode *m_testMode;      ///< Указатель на окно режима тестирования
};

#endif // MAINWINDOW_H

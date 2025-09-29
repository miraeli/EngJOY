#ifndef CARD_H
#define CARD_H

#include <string>

/**
 * @brief Класс Card представляет одну учебную карточку с английским словом и переводом
 *
 * Этот класс используется для хранения пар "английское слово - перевод"
 * в различных режимах приложения (редактор, заучивание, тестирование)
 */
class Card
{
public:
    /**
     * @brief Конструктор по умолчанию. Создает пустую карточку.
     */
    Card();

    /**
     * @brief Конструктор с параметрами для удобного создания карточки
     * @param englishWord Английское слово
     * @param translation Перевод на русский язык
     */
    Card(const std::string& englishWord, const std::string& translation);

    /**
     * @brief Возвращает английское слово карточки
     * @return Английское слово в виде строки
     */
    std::string getEnglishWord() const;

    /**
     * @brief Возвращает перевод карточки
     * @return Перевод на русский язык в виде строки
     */
    std::string getTranslation() const;

    /**
     * @brief Устанавливает английское слово карточки
     * @param englishWord Новое английское слово
     */
    void setEnglishWord(const std::string& englishWord);

    /**
     * @brief Устанавливает перевод карточки
     * @param translation Новый перевод
     */
    void setTranslation(const std::string& translation);

private:
    std::string m_englishWord;  ///< Английское слово
    std::string m_Translation;  ///< Перевод на русский язык
};

#endif // CARD_H

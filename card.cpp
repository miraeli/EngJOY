#include "card.h"

// Реализация конструкторов
Card::Card() : m_englishWord(""), m_Translation("") {} // Инициализируем пустыми строками

Card::Card(const std::string& englishWord, const std::string& translation)
    : m_englishWord(englishWord), m_Translation(translation) {}

// Реализация геттеров
std::string Card::getEnglishWord() const {
    return m_englishWord;
}

std::string Card::getTranslation() const {
    return m_Translation;
}

// Реализация сеттеров
void Card::setEnglishWord(const std::string& englishWord) {
    m_englishWord = englishWord;
}

void Card::setTranslation(const std::string& translation) {
    m_Translation = translation;
}

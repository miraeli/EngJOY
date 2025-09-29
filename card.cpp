#include "card.h"

Card::Card() : m_englishWord(""), m_Translation("") {}

Card::Card(const std::string& englishWord, const std::string& translation)
    : m_englishWord(englishWord), m_Translation(translation) {}

std::string Card::getEnglishWord() const {
    return m_englishWord;
}

std::string Card::getTranslation() const {
    return m_Translation;
}

void Card::setEnglishWord(const std::string& englishWord) {
    m_englishWord = englishWord;
}

void Card::setTranslation(const std::string& translation) {
    m_Translation = translation;
}

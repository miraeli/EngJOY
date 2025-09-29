#include "filemanager.h"
#include <fstream> // для работы с файлами
#include <sstream> // для разбора строк
#include <algorithm> // для std::shuffle (перемешивание)
#include <random>    // для генератора случайных чисел

std::vector<Card> loadDeckFromFile(const std::string& filename) {
    std::vector<Card> deck;
    std::ifstream file(filename); // Пытаемся открыть файл для чтения

    // Если файл не открылся (например, его нет), просто возвращаем пустую колоду
    if (!file.is_open()) {
        return deck;
    }

    std::string line;
    // Читаем файл построчно
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string englishWord, translation;

        // Разбиваем строку по символу ';'
        if (std::getline(iss, englishWord, ';') && std::getline(iss, translation)) {
            // Если получилось извлечь два слова, создаем карточку и добавляем в колоду
            deck.push_back(Card(englishWord, translation));
        }
    }

    file.close();
    return deck;
}

void saveDeckToFile(const std::vector<Card>& deck, const std::string& filename) {
    std::ofstream file(filename); // Открываем файл для записи (старое содержимое удалится)

    // Если файл не открылся, просто выходим из функции
    if (!file.is_open()) {
        return;
    }

    // Проходим по всем карточкам в колоде
    for (const Card& card : deck) {
        // Записываем в файл строку в формате "слово;перевод"
        file << card.getEnglishWord() << ";" << card.getTranslation() << std::endl;
    }

    file.close();
}

Card getRandomCard(const std::vector<Card>& deck) {
    // Проверяем, что колода не пустая, чтобы не было ошибки
    if (deck.empty()) {
        return Card(); // Возвращаем пустую карточку
    }

    // Создаем генератор случайных чисел
    std::random_device rd;
    std::mt19937 gen(rd());
    // Создаем распределение от 0 до размера колоды - 1
    std::uniform_int_distribution<> dis(0, deck.size() - 1);

    // Возвращаем карточку со случайным индексом
    return deck[dis(gen)];
}

std::vector<Card> getRandomChoices(const Card& correctCard, const std::vector<Card>& deck, int numberOfChoices) {
    std::vector<Card> choices;

    // Всегда добавляем правильный ответ
    choices.push_back(correctCard);

    // Теперь нужно добавить случайные НЕправильные ответы
    // Создаем копию колоды, чтобы не менять оригинал
    std::vector<Card> tempDeck = deck;

    // Удаляем правильный ответ из временной колоды, чтобы он не попал в неправильные варианты
    tempDeck.erase(std::remove_if(tempDeck.begin(), tempDeck.end(),
                                  [&correctCard](const Card& card) {
                                      return card.getEnglishWord() == correctCard.getEnglishWord();
                                  }), tempDeck.end());

    // Перемешиваем оставшиеся карточки
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(tempDeck.begin(), tempDeck.end(), g);

    // Добавляем случайные неправильные ответы (сколько поместится)
    int wrongAnswersNeeded = numberOfChoices - 1;
    for (int i = 0; i < wrongAnswersNeeded && i < tempDeck.size(); ++i) {
        choices.push_back(tempDeck[i]);
    }

    // Если неправильных карточек не хватило, просто возвращаем то, что есть
    // Теперь перемешаем правильный и неправильные ответы
    std::shuffle(choices.begin(), choices.end(), g);

    return choices;
}

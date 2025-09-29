#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

// Подключаем наши файлы для тестирования
#include "../card.h"
#include "../filemanager.h"
#include <vector>
#include <fstream>

TEST_CASE("Testing Card class") {
    SUBCASE("Constructor and getters work correctly") {
        Card card("hello", "привет");
        CHECK(card.getEnglishWord() == "hello");
        CHECK(card.getTranslation() == "привет");
    }

    SUBCASE("Default constructor creates empty card") {
        Card card;
        CHECK(card.getEnglishWord() == "");
        CHECK(card.getTranslation() == "");
    }

    SUBCASE("Setters change card values") {
        Card card;
        card.setEnglishWord("test");
        card.setTranslation("тест");
        CHECK(card.getEnglishWord() == "test");
        CHECK(card.getTranslation() == "тест");
    }
}

TEST_CASE("Testing file manager functions") {
    SUBCASE("Save and load deck preserves data") {
        std::vector<Card> original_deck;
        original_deck.push_back(Card("cat", "кот"));
        original_deck.push_back(Card("dog", "собака"));

        // Сохраняем колоду
        saveDeckToFile(original_deck, "test_deck.txt");

        // Загружаем колоду
        std::vector<Card> loaded_deck = loadDeckFromFile("test_deck.txt");

        // Проверяем количество карточек
        CHECK(loaded_deck.size() == original_deck.size());

        // Проверяем содержимое (если есть карточки)
        if (!loaded_deck.empty()) {
            CHECK(loaded_deck[0].getEnglishWord() == "cat");
            CHECK(loaded_deck[0].getTranslation() == "кот");
        }
    }

    SUBCASE("Loading from non-existent file returns empty deck") {
        std::vector<Card> deck = loadDeckFromFile("non_existent_file_12345.txt");
        CHECK(deck.size() == 0);
    }

    SUBCASE("Saving empty deck creates file") {
        std::vector<Card> empty_deck;
        saveDeckToFile(empty_deck, "empty_test.txt");

        // Проверяем, что файл создался (исправленная строка)
        std::ifstream file("empty_test.txt");
        CHECK(file.good());
        file.close(); // Закрываем файл
    }
}

TEST_CASE("Testing random card functions") {
    std::vector<Card> deck;
    deck.push_back(Card("one", "один"));
    deck.push_back(Card("two", "два"));
    deck.push_back(Card("three", "три"));

    SUBCASE("Get random card returns valid card from deck") {
        Card random_card = getRandomCard(deck);

        // Проверяем, что карточка из нашей колоды
        bool found = false;
        for (const auto& card : deck) {
            if (card.getEnglishWord() == random_card.getEnglishWord() &&
                card.getTranslation() == random_card.getTranslation()) {
                found = true;
                break;
            }
        }
        CHECK(found == true);
    }

    SUBCASE("Get random choices includes correct answer") {
        Card correct_card = deck[0];
        std::vector<Card> choices = getRandomChoices(correct_card, deck, 3);

        // Проверяем, что правильный ответ есть среди вариантов
        bool correct_found = false;
        for (const auto& choice : choices) {
            if (choice.getEnglishWord() == correct_card.getEnglishWord()) {
                correct_found = true;
                break;
            }
        }
        CHECK(correct_found == true);
        CHECK(choices.size() == 3);
    }

    SUBCASE("Get random card from empty deck returns empty card") {
        std::vector<Card> empty_deck;
        Card random_card = getRandomCard(empty_deck);
        CHECK(random_card.getEnglishWord() == "");
        CHECK(random_card.getTranslation() == "");
    }
}

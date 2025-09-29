// Подключаем doctest
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "tests/doctest.h"

// Подключаем наши файлы для тестирования
#include "card.h"
#include "filemanager.h"
#include <vector>
#include <fstream>

TEST_CASE("Testing Card class") {
    SUBCASE("Constructor and getters") {
        Card card("hello", "привет");
        CHECK(card.getEnglishWord() == "hello");
        CHECK(card.getTranslation() == "привет");
    }

    SUBCASE("Default constructor") {
        Card card;
        CHECK(card.getEnglishWord() == "");
        CHECK(card.getTranslation() == "");
    }
}

TEST_CASE("Testing file manager functions") {
    SUBCASE("Save and load deck") {
        std::vector<Card> original_deck;
        original_deck.push_back(Card("cat", "кот"));
        original_deck.push_back(Card("dog", "собака"));

        // Сохраняем колоду
        saveDeckToFile(original_deck, "test_deck.txt");

        // Загружаем колоду
        std::vector<Card> loaded_deck = loadDeckFromFile("test_deck.txt");

        // Проверяем, что загрузилось столько же карточек
        CHECK(loaded_deck.size() == original_deck.size());

        // Проверяем содержимое
        if (loaded_deck.size() == 2) {
            CHECK(loaded_deck[0].getEnglishWord() == "cat");
            CHECK(loaded_deck[0].getTranslation() == "кот");
            CHECK(loaded_deck[1].getEnglishWord() == "dog");
            CHECK(loaded_deck[1].getTranslation() == "собака");
        }
    }

    SUBCASE("Load from non-existent file") {
        std::vector<Card> deck = loadDeckFromFile("non_existent_file.txt");
        CHECK(deck.size() == 0); // Должна вернуться пустая колода
    }
}

TEST_CASE("Testing random card functions") {
    std::vector<Card> deck;
    deck.push_back(Card("one", "один"));
    deck.push_back(Card("two", "два"));
    deck.push_back(Card("three", "три"));

    SUBCASE("Get random card from non-empty deck") {
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

    SUBCASE("Get random card from empty deck") {
        std::vector<Card> empty_deck;
        Card random_card = getRandomCard(empty_deck);
        CHECK(random_card.getEnglishWord() == "");
        CHECK(random_card.getTranslation() == "");
    }
}

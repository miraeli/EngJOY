#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../card.h"
#include "../filemanager.h"
#include <vector>
#include <fstream>

TEST_CASE("Testing file manager functions") {
    SUBCASE("Save and load deck preserves data") {
        std::vector<Card> original_deck;
        original_deck.push_back(Card("cat", "кот"));
        original_deck.push_back(Card("dog", "собака"));

        saveDeckToFile(original_deck, "test_deck.txt");

        std::vector<Card> loaded_deck = loadDeckFromFile("test_deck.txt");

        CHECK(loaded_deck.size() == original_deck.size());

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

        std::ifstream file("empty_test.txt");
        CHECK(file.good());
        file.close();
    }
}


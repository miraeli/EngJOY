#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../card.h"
#include "../filemanager.h"
#include <vector>

TEST_CASE("Testing random card functions") {
    std::vector<Card> deck;
    deck.push_back(Card("one", "один"));
    deck.push_back(Card("two", "два"));
    deck.push_back(Card("three", "три"));

    SUBCASE("Get random card returns valid card from deck") {
        Card random_card = getRandomCard(deck);

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
}

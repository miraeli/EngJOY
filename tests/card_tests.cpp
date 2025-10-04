#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../card.h"

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

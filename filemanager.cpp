#include "filemanager.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <random>

std::vector<Card> loadDeckFromFile(const std::string& filename) {
    std::vector<Card> deck;
    std::ifstream file(filename);

    if (!file.is_open()) {
        return deck;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string englishWord, translation;

        if (std::getline(iss, englishWord, ';') && std::getline(iss, translation)) {
            deck.push_back(Card(englishWord, translation));
        }
    }

    file.close();
    return deck;
}

void saveDeckToFile(const std::vector<Card>& deck, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        return;
    }

    for (const Card& card : deck) {
        file << card.getEnglishWord() << ";" << card.getTranslation() << std::endl;
    }

    file.close();
}

Card getRandomCard(const std::vector<Card>& deck) {
    if (deck.empty()) {
        return Card();
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, deck.size() - 1);

    return deck[dis(gen)];
}

std::vector<Card> getRandomChoices(const Card& correctCard, const std::vector<Card>& deck, int numberOfChoices) {
    std::vector<Card> choices;

    choices.push_back(correctCard);

    std::vector<Card> tempDeck = deck;

    tempDeck.erase(std::remove_if(tempDeck.begin(), tempDeck.end(),
                                  [&correctCard](const Card& card) {
                                      return card.getEnglishWord() == correctCard.getEnglishWord();
                                  }), tempDeck.end());

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(tempDeck.begin(), tempDeck.end(), g);

    int wrongAnswersNeeded = numberOfChoices - 1;
    for (int i = 0; i < wrongAnswersNeeded && i < tempDeck.size(); ++i) {
        choices.push_back(tempDeck[i]);
    }

    std::shuffle(choices.begin(), choices.end(), g);

    return choices;
}

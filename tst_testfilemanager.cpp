#include <QTest>
#include <QString>
#include "filemanager.h"
#include "card.h"

class TestFileManager : public QObject
{
    Q_OBJECT

private slots:
    void testSaveAndLoad();
    void testRandomCard();
    void testEmptyDeck();
};

void TestFileManager::testSaveAndLoad()
{
    // Создаем тестовую колоду
    std::vector<Card> originalDeck;
    originalDeck.push_back(Card("apple", "яблоко"));
    originalDeck.push_back(Card("house", "дом"));
    originalDeck.push_back(Card("book", "книга"));

    // Сохраняем и загружаем
    saveDeckToFile(originalDeck, "test_deck.txt");
    std::vector<Card> loadedDeck = loadDeckFromFile("test_deck.txt");

    // Проверяем
    QCOMPARE(loadedDeck.size(), originalDeck.size());
}

void TestFileManager::testRandomCard()
{
    std::vector<Card> deck;
    deck.push_back(Card("cat", "кот"));
    deck.push_back(Card("dog", "собака"));

    Card randomCard = getRandomCard(deck);

    // Проверяем, что карточка не пустая
    QVERIFY(!randomCard.getEnglishWord().empty());
}

void TestFileManager::testEmptyDeck()
{
    std::vector<Card> emptyDeck;
    Card card = getRandomCard(emptyDeck);

    // Проверяем, что вернулась пустая карточка
    QVERIFY(card.getEnglishWord().empty());
}

QTEST_APPLESS_MAIN(TestFileManager)

#include "tst_testfilemanager.moc"

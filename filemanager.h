#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <vector>
#include <string>
#include "card.h"

/**
 * @brief Функция для загрузки колоды карточек из файла
 * @param filename Имя файла для загрузки
 * @return Вектор карточек, загруженных из файла. Если файл не существует, возвращает пустой вектор.
 *
 * @note Формат файла: каждая строка содержит "английское_слово;перевод"
 */
std::vector<Card> loadDeckFromFile(const std::string& filename);

/**
 * @brief Функция для сохранения колоды карточек в файл
 * @param deck Колода карточек для сохранения
 * @param filename Имя файла для сохранения
 *
 * @note Если файл существует, он будет перезаписан. Если нет - создан новый.
 */
void saveDeckToFile(const std::vector<Card>& deck, const std::string& filename);

/**
 * @brief Функция для получения случайной карточки из колоды
 * @param deck Колода карточек
 * @return Случайная карточка из колоды. Если колода пуста, возвращает пустую карточку.
 */
Card getRandomCard(const std::vector<Card>& deck);

/**
 * @brief Функция для генерации вариантов ответов (включая правильный)
 * @param correctCard Правильная карточка, которая должна быть среди вариантов
 * @param deck Колода карточек для выбора неправильных ответов
 * @param numberOfChoices Количество вариантов ответов (по умолчанию 4)
 * @return Вектор карточек-вариантов ответов, перемешанных в случайном порядке
 *
 * @note Если в колоде недостаточно карточек для numberOfChoices, вернет столько, сколько есть.
 */
std::vector<Card> getRandomChoices(const Card& correctCard, const std::vector<Card>& deck, int numberOfChoices = 4);

#endif // FILEMANAGER_H

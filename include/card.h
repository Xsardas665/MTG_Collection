#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
public:
    int id; // id z bazy danych
    std::string name;
    std::string color;
    std::string type;
    std::string manaCost;
    int quantity;

    Card() = default;
    Card(const std::string& n, const std::string& c, const std::string& t, const std::string& m, int q);
};

#endif

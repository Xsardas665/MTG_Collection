#include "../include/card.h"

Card::Card(const std::string& n, const std::string& c,
           const std::string& t, const std::string& m, int q)
    : id(0), name(n), color(c), type(t), manaCost(m), quantity(q) {}

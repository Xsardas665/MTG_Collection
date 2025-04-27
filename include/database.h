#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h>
#include <vector>
#include <string>
#include "card.h"

class Database {
private:
    sqlite3* db; // Pointer to Database
    int open(const std::string& dbName); // Method for opening connection to database
    void close(); // Metoda do zamykania bazy danych

public:
    Database(); // Konstruktor
    ~Database(); // Destruktor

    bool addCard(const Card& card); // Dodanie karty do bazy
    std::vector<Card> getAllCards(); // Pobranie wszystkich kart z bazy
};

#endif

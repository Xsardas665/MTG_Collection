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
    void close(); // Method for closing connection to database

public:
    Database(); // Class Constructor
    ~Database(); // Class Deconstructor

    bool addCard(const Card& card); // Method for adding card to database
    std::vector<Card> getAllCards(); // Method for getting all cards from database
};

#endif

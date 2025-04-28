#include "../include/database.h"
#include <iostream>
#include <fstream>
#include <sstream>

// Constructor — opens the database.
Database::Database() : db(nullptr) {
    if (open("data/cards.db") != SQLITE_OK) {
        std::cerr << "Failed to open the database!" << std::endl;
    }
}

// Destructor — closes the database.
Database::~Database() {
    close();
}

// Opening a connection to the database.
int Database::open(const std::string& dbName) {
    return sqlite3_open(dbName.c_str(), &db);
}

// Closing the connection to the database.
void Database::close() {
    if (db) {
        sqlite3_close(db);
    }
}

// Adding a card to the database.
bool Database::addCard(const Card& card) {
    std::ifstream file("sql/insert_card.sql");
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string sql = buffer.str();
    
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0);
    
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    sqlite3_bind_text(stmt, 1, card.name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, card.color.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, card.type.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, card.manaCost.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 5, card.quantity);

    rc = sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    if (rc != SQLITE_DONE) {
        std::cerr << "Execution failed: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    return true;
}

// Retrieving all cards from the database.
std::vector<Card> Database::getAllCards() {
    std::vector<Card> cards;
    //std::string sql = "SELECT * FROM cards;";
    std::ifstream file("sql/select_all.sql");
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string sql = buffer.str();
    sqlite3_stmt* stmt;

    int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to fetch data: " << sqlite3_errmsg(db) << std::endl;
        return cards;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        Card card(
            reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)), // name
            reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)), // color
            reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)), // type
            reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4)), // mana_cost
            sqlite3_column_int(stmt, 5) // quantity
        );
        card.id = sqlite3_column_int(stmt, 0);
        cards.push_back(card);
    }
    
    sqlite3_finalize(stmt);
    return cards;
}

-- SQL Query for Creating Table in Database
CREATE TABLE IF NOT EXISTS cards (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL,
    color TEXT,
    type TEXT,
    mana_cost TEXT,
    quantity INTEGER DEFAULT 1
);

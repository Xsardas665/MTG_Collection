# Magic the Gathering Collection Manager
A simple desktop application for cataloging Magic: The Gathering cards.
Written in C++ using GTKmm3.

## Technology Used
![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![SQLite](https://img.shields.io/badge/sqlite-%2307405e.svg?style=for-the-badge&logo=sqlite&logoColor=white)

## Project Structure
```
MTG_COLLECTION/
├── src/                 # All source files (.cpp)
│   ├── card.cpp         # Implementation of the Card model
│   └── database.cpp     # Implementation of database operations (SQLite)
├── include/             # All header files (.h)
│   ├── card.h           # Definition of the Card class
│   └── database.h       # Definition of the Database class
├── build/               # Build artifacts (object files and the final binary)
├── data/                # User data (e.g., SQLite database files like cards.db)
│   └── cards.db         # File of SQLite3 database
├── sql/                 # SQL scripts (e.g., database initialization)
│   └── init.sql         # SQL script to create the database schema
├── Makefile             # Build instructions for the project
└── README.md            # Project documentation
```

## Building Project
```bash
make
./build/mtg-catalog

# Magic the Gathering Collection Manager
A simple desktop application for cataloging Magic: The Gathering cards.
Written in C++ using GTKmm3.

## Technology Used
![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![SQLite](https://img.shields.io/badge/sqlite-%2307405e.svg?style=for-the-badge&logo=sqlite&logoColor=white)

GTKmm3 - Gui Library for the application interface.
## Project Structure
```
MTG_COLLECTION/
├── build/               # Build artifacts (object files and the final binary)
├── data/                # User data (e.g., SQLite database files like cards.db)
│   └── cards.db         # File of SQLite3 database
├── include/             # All header files (.h)
│   ├── card.h           # Declaration of the Card class
│   ├── database.h       # Declaration of the Database class
│   └── mainwindow.h     # Declaration of the MainWindow class (GUI)
├── sql/                 # SQL scripts (e.g., database initialization)
│   └── init.sql         # SQL script to create the database schema
├── src/                 # All source files (.cpp)
│   ├── card.cpp         # Implementation of the Card model
│   ├── database.cpp     # Implementation of database operations (SQLite)
│   ├── main.cpp         # Entry point of the application
│   └── mainwindow.cpp   # Implementation of the MainWindow class (GUI)
├── test/                # Source File for gtkmm installation test
│   └── test_gtkmm.cpp   # Implementation of Single Window in GTKmm for testing purposes
├── Makefile             # Build instructions for the project
└── README.md            # Project documentation
```

## Building Project
```bash
make
./build/mtg-catalog

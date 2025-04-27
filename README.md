# Magic the Gathering Collection Manager
A simple desktop application for cataloging Magic: The Gathering cards.
Written in C++ using GTKmm3.

## Project Structure
```
mtg-gtk/
├── src/                 # All source files (.cpp)
│   └── card.cpp         # Implementation of the Card model
├── include/             # All header files (.h)
│   └── card.h           # Definition of the Card class
├── build/               # Build artifacts (object files and the final binary)
├── data/                # User data (e.g., SQLite database files like cards.db)
├── sql/                 # SQL scripts (e.g., database initialization)
│   └── init.sql         # SQL script to create the database schema
├── Makefile             # Build instructions for the project
├── README.md            # Project documentation
```

## Building Project
```bash
make
./build/mtg-catalog

# Magic the Gathering Collection Manager
A simple desktop application for cataloging Magic: The Gathering cards.
Written in C++ using GTKmm3.

## Project Structure

- `build/` — Compiled object files (.o) and the final application binary.
- `data/` — User data files, such as card collections stored in CSV format.
- `include/` — C++ header files (.h) defining interfaces and data structures.
- `src/` — C++ source files (.cpp) containing the application's main logic.
- `test/` — C++ source file (.cpp) for testing if GTKMM is working correctly.
- `Makefile` — Script for building and managing the project.
- `README.md` — Project documentation and usage instructions.

## Building Project
```bash
make
./build/mtg-catalog

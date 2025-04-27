# Magic the Gathering Collection Manager
A simple desktop application for cataloging Magic: The Gathering cards.
Written in C++ using GTKmm3.

## Project Structure

- `src/` — C++ source files (.cpp) containing the application's main logic.
- `include/` — C++ header files (.h) defining interfaces and data structures.
- `build/` — Compiled object files (.o) and the final application binary.
- `data/` — User data files, such as card collections stored in CSV format.
- `Makefile` — Script for building and managing the project.
- `README.md` — Project documentation and usage instructions.

## Building Project
```bash
make
./build/mtg-catalog

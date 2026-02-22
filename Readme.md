# CalendarApp (Qt6 + PostgreSQL)

Basic QT6 application - Calendar that allows user to check date, create, edit and delete events. Data save is implemented in PostgreSQL

## Functions
- Checking date.
- Adding, Editing and Deleting events
- Storing data in PostgreSQL DB

## Requirements
- Qt 6.x (With modules Widgets and QSQL)
- PostgreSQL
- C++20 Compiler
- CMake 3.19+

## How to Run
1. Be sure that PostgreSQL DB is working on localhost (port 5432).
2. Check login credentials in `DatabaseManager.cpp` (default: postgres/123321).
3. Build project:
   ```bash
   mkdir build && cd build
   cmake ..
   make
   ./CalendarApp

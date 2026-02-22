# CalendarApp (Qt6 + PostgreSQL)

Prosta aplikacja kalendarza napisana w C++ przy użyciu frameworka Qt6. Projekt umożliwia zarządzanie wydarzeniami z zapisem do bazy danych PostgreSQL.

## Funkcje
- Wyświetlanie siatki kalendarza.
- Dodawanie, edytowanie i usuwanie wydarzeń.
- Przechowywanie danych w PostgreSQL.

## Wymagania
- Qt 6.x (z modułami Widgets i Sql)
- PostgreSQL
- Kompilator C++20
- CMake 3.19+

## Uruchomienie
1. Upewnij się, że serwer PostgreSQL działa na localhost (port 5432).
2. Skonfiguruj dane logowania w `DatabaseManager.cpp` (domyślnie: postgres/123321).
3. Zbuduj projekt:
   ```bash
   mkdir build && cd build
   cmake ..
   make
   ./CalendarApp
cmake_minimum_required(VERSION 3.1)
project(Ruletka)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Definiowanie plików źródłowych znajdujących się wewnątrz folderu src/
set(SOURCES
        src/main.cpp
        src/GameManager.cpp
        src/BetManager.cpp
        src/UI.cpp
        src/Wallet.cpp
        src/Wheel.cpp
        # src/Statistics.cpp  <-- odkomentuj, jeśli używasz statystyk w danym branchu
)

# 2. Tworzenie pliku wykonywalnego
add_executable(Casino_online ${SOURCES})

# 3. Kluczowy krok: dodanie folderu include/ do ścieżek poszukiwania nagłówków.
# Dzięki temu pliki w src/ znajdą nagłówki używając prostego #include "Nazwa.h"
target_include_directories(Casino_online PRIVATE include)
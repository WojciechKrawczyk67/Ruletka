cmake_minimum_required(VERSION 3.10)
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
)

# 2. Tworzenie pliku wykonywalnego
add_executable(Ruletka ${SOURCES})

# 3. Kluczowy krok: dodanie folderu include/ do ścieżek poszukiwania nagłówków.
# Dzięki temu pliki w src/ znajdą nagłówki używając prostego #include "Nazwa.h"
target_include_directories(Ruletka PRIVATE include)
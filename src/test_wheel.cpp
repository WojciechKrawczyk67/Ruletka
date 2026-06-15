#include <iostream>
#include <cassert>
#include "../include/Wheel.h"

void runWheelTests() {
    std::cout << "--- Rozpoczecie testow klasy Wheel ---\n";

    Wheel rouletteWheel;
    bool allValid = true;

    // Krecimy kolem 1000 razy, aby sprawdzic rozklad i zakres losowanych liczb
    for (int i = 0; i < 1000; i++) {
        int result = rouletteWheel.spin();
        
        if (result < 0 || result > 36) {
            allValid = false;
            std::cout << "[BLAD] Wylosowano liczbe spoza zakresu (0-36): " << result << "\n";
            break; // Przerwerywamy pętlę przy pierwszym błędzie
        }
    }

    assert(allValid == true && "Blad: Mechanizm losujacy zwrocil nieprawidlowa wartosc!");
    
    std::cout << "[OK] Wykonano 1000 losowan. Wszystkie wyniki mieszcza sie w przedziale 0-36.\n";
    std::cout << "--- Wszystkie testy Wheel zakonczone SUKCESEM! ---\n";
}
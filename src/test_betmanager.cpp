#include <iostream>
#include <cassert>
#include "../include/BetManager.h"

void runBetTests() {
    std::cout << "--- Rozpoczecie testow logiki zakladow (BetManager) ---\n";

    // Test 1: Zaklad na Parzyste / Nieparzyste (ParityBet)
    ParityBet evenBet(100.0, true); // true oznacza zaklad na Parzyste
    assert(evenBet.isWinning(2) == true && "Blad: 2 to liczba parzysta, zaklad powinien wygrac");
    assert(evenBet.isWinning(3) == false && "Blad: 3 to liczba nieparzysta, zaklad powinien przegrac");
    assert(evenBet.isWinning(0) == false && "Blad: Ziobro (0) powinno oznaczac przegrana dla parzystych");
    std::cout << "[OK] Logika zakladow Parzyste/Nieparzyste dziala poprawnie.\n";

    // Test 2: Zaklad na Niskie / Wysokie (HalfBet)
    HalfBet lowBet(100.0, true); // true oznacza zaklad na Niskie (1-18)
    assert(lowBet.isWinning(10) == true && "Blad: 10 to niska liczba, zaklad powinien wygrac");
    assert(lowBet.isWinning(20) == false && "Blad: 20 to wysoka liczba, zaklad powinien przegrac");
    assert(lowBet.isWinning(0) == false && "Blad: 0 przegrywa dla niskich/wysokich");
    std::cout << "[OK] Logika zakladow Niskie/Wysokie dziala poprawnie.\n";

    // Test 3: Zaklad na Kolory (ColorBet)
    ColorBet redBet(100.0, true); // true oznacza zaklad na Czerwone
    assert(redBet.isWinning(1) == true && "Blad: 1 to czerwona liczba"); 
    assert(redBet.isWinning(2) == false && "Blad: 2 to czarna liczba");
    assert(redBet.isWinning(0) == false && "Blad: 0 jest zielone, wszystkie kolory przegrywaja");
    std::cout << "[OK] Logika zakladow Czerwone/Czarne dziala poprawnie.\n";

    std::cout << "--- Wszystkie testy BetManager zakonczone SUKCESEM! ---\n";
}
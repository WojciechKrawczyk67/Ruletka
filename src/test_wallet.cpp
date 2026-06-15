#include <iostream>
#include <cassert>
#include "../include/Wallet.h"

void runWalletTests() {
    std::cout << "--- Rozpoczecie testow klasy Wallet ---\n";

    // Test 1: Poprawna inicjalizacja portfela
    Wallet w1;
    assert(w1.getBalance() == 1000.0 && "Blad: Domyslny balans powinien wynosic 1000.0");

    Wallet w2(500.0);
    assert(w2.getBalance() == 500.0 && "Blad: Balans poczatkowy powinien wynosic 500.0");
    std::cout << "[OK] Inicjalizacja portfela dziala poprawnie.\n";

    // Test 2: Dodawanie srodkow
    w2.addFunds(200.0);
    assert(w2.getBalance() == 700.0 && "Blad: Po dodaniu 200, balans powinien wynosic 700.0");

    w2.addFunds(-100.0); 
    assert(w2.getBalance() == 700.0 && "Blad: Balans nie powinien sie zmienic po dodaniu ujemnej kwoty");
    std::cout << "[OK] Dodawanie srodkow dziala poprawnie.\n";

    // Test 3: Odejmowanie srodkow
    bool success1 = w2.deductFunds(300.0);
    assert(success1 == true && "Blad: Odejmowanie powinno zwrocic true");
    assert(w2.getBalance() == 400.0 && "Blad: Po odjeciu 300, balans powinien wynosic 400.0");
    std::cout << "[OK] Odejmowanie dozwolonych srodkow dziala poprawnie.\n";

    // Test 4: Odejmowanie zbyt duzej kwoty (brak srodkow)
    bool success2 = w2.deductFunds(1000.0);
    assert(success2 == false && "Blad: Odejmowanie kwoty wiekszej niz balans powinno zwrocic false");
    assert(w2.getBalance() == 400.0 && "Blad: Balans nie powinien sie zmienic po nieudanej transakcji");
    std::cout << "[OK] Blokada wyplaty ponad stan dziala poprawnie.\n";

    std::cout << "--- Wszystkie testy Wallet zakonczone SUKCESEM! ---\n";
}
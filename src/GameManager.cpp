#include "GameManager.h"

GameManager::GameManager() : wallet(1000.0) {}

void GameManager::run() {
    bool isRunning = true;
    while (isRunning) {
        int choice = ui.displayMenu();
        
        switch (choice) {
            case 1:
                playRound();
                break;
            case 2:
                ui.showMessage("\nAktualny stan konta: " + std::to_string(wallet.getBalance()) + " żetonów.");
                break;
            case 3:
                ui.showMessage("\nStatystyki: Modul w budowie.");
                break;
            case 4:
                ui.showMessage("\nDziękujemy za gre!");
                isRunning = false;
                break;
        }
    }
}

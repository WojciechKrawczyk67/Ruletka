#pragma once

#include "UI.h"
#include "Wheel.h"
#include "Wallet.h"
#include "BetManager.h"
#include <string>

class GameManager {
private:
    UI ui;
    Wheel wheel;
    Wallet wallet;
    BetManager betManager;

public:
    GameManager();
    void run();

private:
    void playRound();
};

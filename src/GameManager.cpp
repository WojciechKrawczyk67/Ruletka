#pragma once

#include <vector>
#include <memory>

class Bet;
enum class Color; 

class BetManager {
private:
    std::vector<std::unique_ptr<Bet>> activeBets;

public:
    BetManager();
    void addParityBet(double amount, bool isEven);
    
    void addHalfBet(double amount, bool isFirstHalf);
    
    void addColorBet(double amount, Color choice);

    // a następnie zwraca zsumowaną kwotę wygranej do przekazania graczowi.
    double resolveAllBets(int winNumber);
};

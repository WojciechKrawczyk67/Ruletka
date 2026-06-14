#pragma once

#include <vector>
#include <memory>

class Bet {
protected:
    double amount;          
    int payoutMultiplier;  

public:

    Bet(double amount, int multiplier = 2);

    virtual ~Bet() = default;

    virtual bool isWinning(int winningNumber) const = 0;

    double resolveBet(int winningNumber) const;
};
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

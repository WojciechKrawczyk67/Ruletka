#include "BetManager.h"

Bet::Bet(double amount, int multiplier) : amount(amount), payoutMultiplier(multiplier) {}

double Bet::resolveBet(int winningNumber) const {
    if (isWinning(winningNumber)) {
        return amount * payoutMultiplier;
    }
    return 0.0;
}

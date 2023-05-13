#ifndef TRADERALEATOIRE_H
#define TRADERALEATOIRE_H

#include "trader.h"
#include "bourse.h"
#include "portefeuille.h"

class TraderAleatoire : public Trader {
public:
    TraderAleatoire(double soldeInitial);

    Transaction choisirTransaction(const Bourse& bourse, const Portefeuille& portefeuille) override;

private:
    double soldeInitial;
    int transactionsParJour;
};

#endif // TRADERALEATOIRE_H


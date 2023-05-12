#ifndef TRADERALGORITHMIQUE_H
#define TRADERALGORITHMIQUE_H

#include "trader.h"
#include "bourse.h"
#include "portefeuille.h"

class TraderAlgorithmique : public Trader {
public:
    TraderAlgorithmique(double soldeInitial);

    Transaction choisirTransaction(const Bourse& bourse, const Portefeuille& portefeuille) override;

private:
    double soldeInitial;
    int transactionsParJour;
};

#endif // TRADERALGORITHMIQUE_H

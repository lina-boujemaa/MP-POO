#ifndef TRADERALGORITHMIQUE_H
#define TRADERALGORITHMIQUE_H

#include "trader.h"
#include "boursevecteur.h"
#include "portefeuille.h"

class TraderAlgorithmique : public Trader {
public:
    TraderAlgorithmique(double soldeInitial);

    Transaction choisirTransaction(const BourseVector& bourse, const Portefeuille& portefeuille) ;

private:
    double soldeInitial;
    int transactionsParJour;
};

#endif // TRADERALGORITHMIQUE_H


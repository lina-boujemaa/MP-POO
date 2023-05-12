#ifndef TRADER_H
#define TRADER_H

#include "transaction.h"
#include "bourse.h"
#include "portefeuille.h"

class Trader {
public:
    virtual Transaction choisirTransaction(const Bourse& bourse, const Portefeuille& portefeuille) = 0;
};

#endif // TRADER_H

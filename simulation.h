#ifndef SIMULATION_H
#define SIMULATION_H

#include "bourse.h"
#include "trader.h"
#include "date.h"

class Simulation {
public:
    static void executer(Bourse& bourse, Trader& trader, Date dateDebut, Date dateFin, double solde);
};

#endif // SIMULATION_H

#ifndef SIMULATION_H
#define SIMULATION_H

#include "bourse.h"
#include "trader.h"
#include "portefeuille.h"
#include "date.h"
#include <map>

class Simulation {
public:
    static std::map<std::string, long> executer(Bourse& bourse, Trader& trader, Date dateDebut, Date dateFin, double solde);

private:
    static void executer(Bourse& bourse, Trader& trader, Portefeuille& portefeuille, Date dateDebut, Date dateFin, double solde);
};

#endif // SIMULATION_H

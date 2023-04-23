#include "simulation.h"

void Simulation::executer(Bourse& bourse, Trader& trader, Date dateDebut, Date dateFin, double solde) {
Portefeuille portefeuille(solde);
Date date = dateDebut;
int nbTransactions = 0;
while (date <= dateFin) {
    std::vector<Action*> actions = bourse.getActionsDisponibles(date, portefeuille.getSolde());


    if (nbTransactions < 100) {
        Transaction transaction = trader.choisirTransaction(bourse, portefeuille, actions, date);

        portefeuille.executerTransaction(transaction, bourse, date);

        nbTransactions++;
    }

    date = date.incrementer();

    nbTransactions = 0;
}

trader.setPortefeuille(portefeuille);
}

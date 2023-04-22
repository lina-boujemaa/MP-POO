#include "simulation.h"

void Simulation::executer(Bourse& bourse, Trader& trader, Date dateDebut, Date dateFin, double solde) {
    // initialize the trader's portfolio with the initial balance
    Portefeuille portefeuille(solde);

    // simulate the trading days
    Date date = dateDebut;
    while (date <= dateFin) {
        // get the available actions for the trader
        std::vector<Action*> actions = bourse.getActionsDisponibles(date, portefeuille.getSolde());

        // let the trader choose a transaction
        Transaction transaction = trader.choisirTransaction(bourse, portefeuille, actions, date);

        // execute the transaction
        portefeuille.executerTransaction(transaction, bourse, date);

        // move to the next trading day
        date = date.addJours(1);
    }

    // update the trader's portfolio
    trader.setPortefeuille(portefeuille);
}

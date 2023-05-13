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

std::map<std::string, long> Simulation::executer(Bourse& bourse, Trader& trader, Date dateDebut, Date dateFin, double solde) {
    Portefeuille portefeuille;
    portefeuille.setSolde(solde);

    executer(bourse, trader, portefeuille, dateDebut, dateFin, solde);

    std::map<std::string, long> result;
    for (const auto& action : portefeuille.getActions()) {
        result[action.first] = action.second;
    }
    return result;
}

void Simulation::executer(Bourse& bourse, Trader& trader, Portefeuille& portefeuille, Date dateDebut, Date dateFin, double solde) {
    portefeuille.setSolde(solde);
    portefeuille.viderActions();

    Date currentDate = dateDebut;
    int nbTransactions = 0;

    while (currentDate <= dateFin) {
        std::vector<std::string> actions = bourse.getActionsDisponiblesParDate(currentDate, portefeuille.getSolde());

        if (nbTransactions < 100) {
            Transaction transaction = trader.choisirTransaction(bourse, portefeuille);

            portefeuille.executerTransaction(transaction, bourse, currentDate);

            nbTransactions++;
        }

        currentDate.suivant();
        nbTransactions = 0;
    }

    
}



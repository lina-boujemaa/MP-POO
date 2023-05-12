#include "traderaleatoire.h"
#include "bourse.h"
#include "portefeuille.h"
#include <cstdlib>
#include <ctime>

TraderAleatoire::TraderAleatoire(double soldeInitial)
    : soldeInitial(soldeInitial), transactionsParJour(0)
{
    std::srand(std::time(nullptr));
}

Transaction TraderAleatoire::choisirTransaction(const Bourse& bourse, const Portefeuille& portefeuille)
{
    if (transactionsParJour >= 100) {
        return Transaction(TypeTransaction::RIEN, "", 0.0, 0);
    }

    if (portefeuille.getActions().empty()) {
        auto actionsDisponibles = bourse.getActionsDisponiblesAujourdhui(portefeuille.getSolde());
        if (actionsDisponibles.empty()) {
            return Transaction(TypeTransaction::RIEN, "", 0.0, 0);
        }
        int randomIndex = std::rand() % actionsDisponibles.size();
        std::string action = actionsDisponibles[randomIndex];
        double prix = bourse.getPrixActionAujourdhui(action)->getPrix();
        int quantite = static_cast<int>(portefeuille.getSolde() / prix);
        return Transaction(TypeTransaction::ACHAT, action, prix, quantite);
    } else {
        auto actions = portefeuille.getActions();
        int randomIndex = std::rand() % actions.size();
        std::string action = actions[randomIndex];
        double prix = bourse.getPrixActionAujourdhui(action)->getPrix();
        int quantite = portefeuille.getQuantite(action);
        if (std::rand() % 2 == 0) {
            return Transaction(TypeTransaction::VENTE, action, prix, quantite);
        } else {
            if (portefeuille.getSolde() >= prix) {
                return Transaction(TypeTransaction::ACHAT, action, prix, quantite);
            } else {
                return Transaction(TypeTransaction::RIEN, "", 0.0, 0);
            }
        }
    }

    transactionsParJour++;
}

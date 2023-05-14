#include "traderalgorithmique.h"
#include "bourse.h"
#include "portefeuille.h"
#include <cstdlib>
#include <ctime>

TraderAlgorithmique::TraderAlgorithmique(double soldeInitial)
    : soldeInitial(soldeInitial), transactionsParJour(0)
{
    std::srand(std::time(nullptr));
}

Transaction TraderAlgorithmique::choisirTransaction(const BourseVector& bourse, const Portefeuille& portefeuille)
{
    if (transactionsParJour >= 100) {
        return Transaction(TypeTransaction::RIEN, "", 0.0, 0);
    }

    if (portefeuille.getActions().empty()) {
        auto actionsDisponibles = bourse.getActionsDisponiblesParDate(bourse.getAujourdhui());
        if (actionsDisponibles.empty()) {
            return Transaction(TypeTransaction::RIEN, "", 0.0, 0);
        }
        int randomIndex = std::rand() % actionsDisponibles.size();
        std::string action = actionsDisponibles[randomIndex];
        auto prixJournalier = bourse.getPrixActionParDate(action, bourse.getAujourdhui());
        if (prixJournalier == nullptr) {
            return Transaction(TypeTransaction::RIEN, "", 0.0, 0);
        }
        double prix = prixJournalier->getPrix();
        int quantite = static_cast<int>(portefeuille.getSolde() / prix);
        return Transaction(TypeTransaction::ACHAT, action, prix, quantite);
    } else {
        auto actions = portefeuille.getActions();
        int randomIndex = std::rand() % actions.size();
        auto it = std::next(actions.begin(), randomIndex);
        std::string action = it->first;

        auto prixJournalier = bourse.getPrixActionParDate(action, bourse.getAujourdhui());
        if (prixJournalier == nullptr) {
            return Transaction(TypeTransaction::RIEN, "", 0.0, 0);
        }
        double prix = prixJournalier->getPrix();
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

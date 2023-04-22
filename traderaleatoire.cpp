#include "trader.h"
#include "bourse.h"
#include "portefeuille.h"
#include <cstdlib>
#include <ctime>

class TraderAleatoire : public Trader {
public:
    TraderAleatoire(double soldeInitial);

    virtual Transaction choisirTransaction(const Bourse& bourse, const Portefeuille &portefeuille) override;

private:
    double m_soldeInitial;
    int m_transactionsParJour;
};

TraderAleatoire::TraderAleatoire(double soldeInitial)
    : m_soldeInitial(soldeInitial), m_transactionsParJour(0)
{
    std::srand(std::time(nullptr));
}

Transaction TraderAleatoire::choisirTransaction(const Bourse& bourse, const Portefeuille& portefeuille)
{
    if (m_transactionsParJour >= 100) {
        return Transaction::Neutre;
    }

    if (portefeuille.actions().empty()) {
        return Transaction::Achat;
    }

    auto actionsDisponibles = bourse.actionsDisponibles(m_soldeInitial);

    if (actionsDisponibles.empty()) {
        return Transaction::Neutre;
    }

    auto actionIndex = std::rand() % actionsDisponibles.size();
    auto action = actionsDisponibles[actionIndex];

    auto prix = bourse.cours(action).dernier();

    if (portefeuille.contains(action)) {
        if (std::rand() % 2 == 0) {
            return Transaction::Vente;
        } else {
            return Transaction::Neutre;
        }
    } else {
        if (m_soldeInitial >= prix) {
            return Transaction::Achat;
        } else {
            return Transaction::Neutre;
        }
    }
}

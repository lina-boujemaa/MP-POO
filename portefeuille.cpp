#include "portefeuille.h"
#include <algorithm>

void Portefeuille::ajouterAction(Action action, int quantite) {
    auto it = std::find_if(m_actions.begin(), m_actions.end(), [action](const ActionQuantite& aq) { return aq.action == action; });
    if (it != m_actions.end()) {
        it->quantite += quantite;
    } else {
        m_actions.push_back(ActionQuantite{action, quantite});
    }
}

void Portefeuille::retirerAction(Action action, int quantite) {
    auto it = std::find_if(m_actions.begin(), m_actions.end(), [action](const ActionQuantite& aq) { return aq.action == action; });
    if (it != m_actions.end()) {
        it->quantite -= quantite;
        if (it->quantite <= 0) {
            m_actions.erase(it);
        }
    }
}

int Portefeuille::getQuantite(Action action) const {
    auto it = std::find_if(m_actions.begin(), m_actions.end(), [action](const ActionQuantite& aq) { return aq.action == action; });
    return (it != m_actions.end()) ? it->quantite : 0;
}

double Portefeuille::getValeur(const Bourse& bourse) const {
    double valeur = 0.0;
    for (const auto& aq : m_actions) {
        double prix = bourse.getPrix(aq.action, bourse.getDernierJour());
        valeur += prix * aq.quantite;
    }
    return valeur;
}

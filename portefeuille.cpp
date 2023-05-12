#include "portefeuille.h"

Portefeuille::Portefeuille() : solde(0.0) {}

void Portefeuille::setSolde(double solde) {
    this->solde = solde;
}

double Portefeuille::getSolde() const {
    return solde;
}

void Portefeuille::viderActions() {
    actions.clear();
}

void Portefeuille::acheter(const std::string& nomAction, double prix, int quantite) {
    if (quantite > 0) {
        solde -= prix * quantite;
        actions[nomAction] += quantite;
    }
}

void Portefeuille::vendre(const std::string& nomAction, double prix, int quantite) {
    if (quantite > 0 && actions.count(nomAction) > 0) {
        int& quantiteActuelle = actions[nomAction];
        if (quantite <= quantiteActuelle) {
            solde += prix * quantite;
            quantiteActuelle -= quantite;
            if (quantiteActuelle == 0) {
                actions.erase(nomAction);
            }
        }
    }
}

int Portefeuille::getQuantite(const std::string& nomAction) const {
    if (actions.count(nomAction) > 0) {
        return actions.at(nomAction);
    }
    return 0;
}

std::map<std::string, int> Portefeuille::getActions() const {
    return actions;
}

#ifndef PORTEFEUILLE_H
#define PORTEFEUILLE_H

#include <vector>
#include "action.h"

class Portefeuille {
public:
    Portefeuille();
    void acheter(Action* action, double prix, int quantite);
    void vendre(Action* action, double prix, int quantite);
    double getSolde() const;
    void setSolde(double solde);
    std::vector<Action*>& getActions();
    const std::vector<Action*>& getActions() const;
    bool operator==(const Portefeuille& autre) const;

private:
    std::vector<Action*> m_actions;
    double m_solde;
};

#endif // PORTEFEUILLE_H

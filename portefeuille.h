#ifndef PORTEFEUILLE_H
#define PORTEFEUILLE_H

#include <map>
#include <string>

class Portefeuille {
public:
    Portefeuille();
    void setSolde(double solde);
    double getSolde() const;
    void viderActions();
    void acheter(const std::string& nomAction, double prix, int quantite);
    void vendre(const std::string& nomAction, double prix, int quantite);
    int getQuantite(const std::string& nomAction) const;
    std::map<std::string, int> getActions() const;

private:
    double solde;
    std::map<std::string, int> actions;
};

#endif // PORTEFEUILLE_H

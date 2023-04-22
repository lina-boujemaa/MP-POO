#ifndef TRADER_H
#define TRADER_H

#include "Bourse.h"
#include "Portefeuille.h"

enum class TypeTransaction { ACHAT, VENTE, ATTENTE };

class Transaction {
public:
    Transaction(TypeTransaction type, std::string nom, double prix, int quantite)
        : m_type(type), m_nom(nom), m_prix(prix), m_quantite(quantite) {}

    TypeTransaction getType() const { return m_type; }
    std::string getNom() const { return m_nom; }
    double getPrix() const { return m_prix; }
    int getQuantite() const { return m_quantite; }

private:
    TypeTransaction m_type;
    std::string m_nom;
    double m_prix;
    int m_quantite;
};

class Trader {
public:
    virtual Transaction choisirTransaction(const Bourse& bourse, const Portefeuille& portefeuille) = 0;
};

#endif // TRADER_H

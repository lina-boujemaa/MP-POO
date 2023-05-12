#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
enum class TypeTransaction { ACHAT, VENTE, RIEN };

class Transaction {
public:
    Transaction(TypeTransaction type, std::string nom, double prix, int quantite)
        : type(type), nom(nom), prix(prix), quantite(quantite) {}

    TypeTransaction getType() const { return type; }
    std::string getNom() const { return nom; }
    double getPrix() const { return prix; }
    int getQuantite() const { return quantite; }

private:
    TypeTransaction type;
    std::string nom;
    double prix;
    int quantite;
};

#endif // TRANSACTION_H

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

enum class TypeTransaction { ACHAT, VENTE, RIEN };

class Transaction {
public:
    Transaction(TypeTransaction type, std::string nom, double prix, int quantite);

    TypeTransaction getType() const;
    std::string getNom() const;
    double getPrix() const;
    int getQuantite() const;

private:
    TypeTransaction type;
    std::string nom;
    double prix;
    int quantite;
};

#endif // TRANSACTION_H

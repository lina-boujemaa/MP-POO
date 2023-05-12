#include "transaction.h"

Transaction::Transaction(TypeTransaction type, std::string nom, double prix, int quantite)
    : type(type), nom(nom), prix(prix), quantite(quantite) {}

TypeTransaction Transaction::getType() const { return type; }

std::string Transaction::getNom() const { return nom; }

double Transaction::getPrix() const { return prix; }

int Transaction::getQuantite() const { return quantite; }

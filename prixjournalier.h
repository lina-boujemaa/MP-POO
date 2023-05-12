#ifndef PRIXJOURNALIER_H
#define PRIXJOURNALIER_H

#include "Date.h"
#include <string>

class PrixJournalier {
public:
    PrixJournalier();
    PrixJournalier(const std::string& nomAction, const Date& date, double prix);
    std::string getNomAction() const;
    Date getDate() const;
    double getPrix() const;

private:
    std::string nomAction;
    Date date;
    double prix;
};

#endif // PRIXJOURNALIER_H

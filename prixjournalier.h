#ifndef PRIXJOURNALIER_H
#define PRIXJOURNALIER_H

#include "date.h"
#include <string>
#include <istream>

class PrixJournalier {
public:
    PrixJournalier();
    PrixJournalier(const std::string& nomAction, const Date& date, double prix);
    PrixJournalier(const std::pair<const Date, PrixJournalier>& pair); // Added constructor
    std::string getNomAction() const;
    Date getDate() const;
    double getPrix() const;

    friend std::istream& operator>>(std::istream& is, PrixJournalier& prixJournalier);

private:
    std::string nomAction;
    Date date;
    double prix;
};

std::istream& operator>>(std::istream& is, PrixJournalier& prixJournalier);

#endif

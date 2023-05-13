#ifndef PRIXJOURNALIER_H
#define PRIXJOURNALIER_H

#include "date.h"
#include <string>
#include <istream>

class PrixJournalier {
public:
    PrixJournalier();
    PrixJournalier(const std::string& nomAction, const Date& date, double prix);
    std::string getNomAction() const;
    Date getDate() const;
    double getPrix() const;

    friend std::istream& operator>>(std::istream& is, PrixJournalier& prixJournalier);

private:
    std::string nomAction;
    Date date;
    double prix;
};
std::istream& operator>>(std::istream& is, PrixJournalier& prixJournalier) {
    std::string nomAction;
    Date date;
    double prix;
    is >> nomAction >> date >> prix;
    prixJournalier = PrixJournalier(nomAction, date, prix);
    return is;
}

#endif



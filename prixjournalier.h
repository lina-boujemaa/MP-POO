#ifndef PRIXJOURNALIER_H
#define PRIXJOURNALIER_H

#include <string>
#include "date.h"

class PrixJournalier {
public:
    PrixJournalier();
    PrixJournalier(const std::string& nomAction, const Date& date, double prix);
    std::string getNomAction() const;
    Date getDate() const;
    double getPrix() const;

private:
    std::string m_nomAction;
    Date m_date;
    double m_prix;
};

#endif

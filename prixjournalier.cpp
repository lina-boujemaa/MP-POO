#include "PrixJournalier.h"

PrixJournalier::PrixJournalier() : nomAction(""), date(Date(1,1,1970)), prix(0.0) {}

PrixJournalier::PrixJournalier(const std::string& nomAction, const Date& date, double prix)
    : nomAction(nomAction), date(date), prix(prix)
{
}

std::string PrixJournalier::getNomAction() const
{
    return nomAction;
}

Date PrixJournalier::getDate() const {
    return date;
}

double PrixJournalier::getPrix() const {
    return prix;
}

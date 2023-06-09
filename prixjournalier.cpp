#include "prixjournalier.h"

PrixJournalier::PrixJournalier() : nomAction(""), date(Date(1, 1, 1970)), prix(0.0) {}

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

std::istream& operator>>(std::istream& is, PrixJournalier& prixJournalier) {
    std::string nomAction;
    Date date;
    double prix;
    is >> nomAction >> date >> prix;
    prixJournalier = PrixJournalier(nomAction, date, prix);
    return is;
}

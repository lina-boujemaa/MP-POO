#include "PrixJournalier.h"

PrixJournalier::PrixJournalier() : m_nomAction(""), m_date(Date(1,1,1970)), m_prix(0.0) {}

PrixJournalier::PrixJournalier(const std::string& nomAction, const Date& date, double prix)
    : m_nomAction(nomAction), m_date(date), m_prix(prix)
{
}

std::string PrixJournalier::getNomAction() const
{
    return m_nomAction;
}

Date PrixJournalier::getDate() const {
    return m_date;
}

double PrixJournalier::getPrix() const {
    return m_prix;
}

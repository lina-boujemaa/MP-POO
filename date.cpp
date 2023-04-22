#include "date.h"

Date::Date(int jour, int mois, int annee)
    : m_jour(jour), m_mois(mois), m_annee(annee)
{
}

int Date::getJour() const
{
    return m_jour;
}

int Date::getMois() const
{
    return m_mois;
}

int Date::getAnnee() const
{
    return m_annee;
}

bool Date::operator==(const Date& autre) const
{
    return m_jour == autre.m_jour && m_mois == autre.m_mois && m_annee == autre.m_annee;
}

std::ostream& operator<<(std::ostream& os, const Date& date)
{
    os << date.m_jour << "/" << date.m_mois << "/" << date.m_annee;
    return os;
}


std::istream& operator>>(std::istream& is, Date& date)
{
    char sep1, sep2;
    is >> date.m_jour >> sep1 >> date.m_mois >> sep2 >> date.m_annee;
    if (sep1 != '/' || sep2 != '/') {
        is.setstate(std::ios::failbit);
    }
    return is;
}

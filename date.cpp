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

void Date::incrementer()
{
    int max_jour = joursDansMois(m_mois, m_annee);

    if (m_jour < max_jour) {
        ++m_jour;
    }
    else {
        m_jour = 1;
        if (m_mois < 12) {
            ++m_mois;
        }
        else {
            m_mois = 1;
            ++m_annee;
        }
    }
}
bool Date::estBissextile(int annee)
{
    return (annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0);
}

int Date::joursDansMois(int mois, int annee)
{
    int jours = 31;

    if (mois == 2) {
        if (estBissextile(annee)) {
            jours = 29;
        }
        else {
            jours = 28;
        }
    }
    else if (mois == 4 || mois == 6 || mois == 9 || mois == 11) {
        jours = 30;
    }

    return jours;
}



#include "date.h"

Date::Date(int jour, int mois, int annee)
    : jour(jour), mois(mois), annee(annee)
{
}

int Date::getJour() const
{
    return jour;
}

int Date::getMois() const
{
    return mois;
}

int Date::getAnnee() const
{
    return  annee;
}

bool Date::operator==(const Date& autre) const
{
    return jour == autre.jour && mois == autre.mois && annee == autre.annee;
}

std::ostream& operator<<(std::ostream& os, const Date& date)
{
    os << date.jour << "/" << date.mois << "/" << date.annee;
    return os;
}

std::istream& operator>>(std::istream& is, Date& date)
{
    char sep1, sep2;
    is >> date.jour >> sep1 >> date.mois >> sep2 >> date.annee;
    if (sep1 != '/' || sep2 != '/') {
        is.setstate(std::ios::failbit);
    }
    return is;
}

void Date::incrementer()
{
    int maxi = joursDansMois(mois, annee);

    if (jour < maxi) {
        ++jour;
    }
    else {
        jour = 1;
        if (mois < 12) {
            ++mois;
        }
        else {
            mois = 1;
            ++annee;
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

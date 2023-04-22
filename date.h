#ifndef DATE_H
#define DATE_H

#include <string>

class Date {
public:
    Date(int jour, int mois, int annee);
    int getJour() const;
    int getMois() const;
    int getAnnee() const;
    bool operator==(const Date& autre) const;

private:
    int m_jour;
    int m_mois;
    int m_annee;
};
std::ostream& operator<<(std::ostream& os, const Date& date);
std::istream& operator>>(std::istream& is, Date& date);

#endif

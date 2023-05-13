#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <iostream>
#include <string>

class Date {
public:
    Date();
    Date(int jour, int mois, int annee);
    int getJour() const;
    int getMois() const;
    int getAnnee() const;
    bool operator==(const Date& autre) const;
    bool operator<(const Date& autre) const; // Added < operator overload

    void incrementer();
    void suivant();

    friend std::ostream& operator<<(std::ostream& os, const Date& date);
    friend std::istream& operator>>(std::istream& is, Date& date);

private:
    int jour;
    int mois;
    int annee;
    static int joursDansMois(int mois, int annee);
    static bool estBissextile(int annee);
};

#endif // DATE_H_INCLUDED


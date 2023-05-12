#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

class Date {
public:
    Date(int jour, int mois, int annee);
    int getJour() const;
    int getMois() const;
    int getAnnee() const;
    bool operator==(const Date& autre) const;
    void incrementer();

    friend std::ostream& operator<<(std::ostream& os, const Date& date);
    friend std::istream& operator>>(std::istream& is, Date& date);

private:
    int jour;
    int mois;
    int annee;
    static int joursDansMois(int mois, int annee);
    static bool estBissextile(int annee);
};


#endif

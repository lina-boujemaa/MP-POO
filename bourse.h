#ifndef BOURSE_H
#define BOURSE_H

#include <vector>
#include <string>
#include "PrixJournalier.h"

class Bourse {
public:
    Bourse(const std::vector<PrixJournalier>& prixJournaliers);
    Date getAujourdhui() const { return aujourdhui; }
    void setAujourdhui(Date jour) { aujourdhui = jour; }
    virtual std::vector<std::string> getActionsDisponiblesParDate(const Date& date) const = 0;
    virtual std::vector<PrixJournalier> getPrixJournaliersParDate(const Date& date) const = 0;
    virtual PrixJournalier* getPrixActionParDate(std::string action, const Date& date) const = 0;

protected:
    Date aujourdhui;
};

#endif

#ifndef BOURSEVECTOR_H
#define BOURSEVECTOR_H

#include "bourse.h"

class BourseVector : public Bourse {
public:
    BourseVector(const std::vector<PrixJournalier>& prixJournaliers);
    std::vector<std::string> getActionsDisponiblesParDate(const Date& date) const override;
    std::vector<PrixJournalier> getPrixJournaliersParDate(const Date& date) const override;
    PrixJournalier* getPrixActionParDate(std::string action, const Date& date) const override;
    void ajouterPrixJournalier(const PrixJournalier& prix);

private:
    std::vector<PrixJournalier> prixJournaliers;
};

#endif


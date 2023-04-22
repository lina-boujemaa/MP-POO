#ifndef BOURSEVECTOR_H
#define BOURSEVECTOR_H

#include <vector>
#include <string>
#include "PrixJournalier.h"

class BourseVector {
public:
    BourseVector(const std::vector<PrixJournalier>& prixJournaliers);
    std::vector<std::string> getActionsDisponiblesParDate(const Date& date, double prixMax) const;
    std::vector<PrixJournalier> getPrixJournaliersParDate(const Date& date) const;

private:
    std::vector<PrixJournalier> m_prixJournaliers;
};

#endif

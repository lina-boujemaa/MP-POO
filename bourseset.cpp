#ifndef BOURSESET_H
#define BOURSESET_H

#include <set>
#include <string>
#include "bourse.h"

class BourseSet : public Bourse {
public:
    BourseSet(const std::set<PrixJournalier>& prixJournaliers);
    std::set<std::string> getActionsDisponiblesAujourdhui(double prixmax) const;

private:
    std::set<PrixJournalier> prixJournaliersSet;
};

#endif // BOURSESET_H


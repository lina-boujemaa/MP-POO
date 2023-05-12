#ifndef BOURSEMULTIMAP_H
#define BOURSEMULTIMAP_H

#include <map>
#include <string>
#include "Bourse.h"

class BourseMultiMap : public Bourse {
public:
    BourseMultiMap(const std::multimap<Date, PrixJournalier>& prixJournaliers);

    std::multimap<Date, PrixJournalier> getActionsDisponiblesAujourdhui(double prixmax) const override;

private:
    std::multimap<Date, PrixJournalier> prixJournaliersMultiMap;
};

#endif

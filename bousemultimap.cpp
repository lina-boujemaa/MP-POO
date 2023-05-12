#include "boursemultimap.h"
#include <algorithm>

BourseMultiMap::BourseMultiMap(const std::multimap<Date, PrixJournalier>& prixJournaliers)
    : Bourse(std::vector<PrixJournalier>(prixJournaliers.begin(), prixJournaliers.end())),
      prixJournaliersMultiMap(prixJournaliers)
{
}

std::multimap<Date, PrixJournalier> BourseMultiMap::getActionsDisponiblesAujourdhui(double prixmax) const
{
    std::multimap<Date, PrixJournalier> actions;
    for (const auto& pair : prixJournaliersMultiMap) {
        const PrixJournalier& prix = pair.second;
        if (prix.getDate() == aujourdhui && prix.getPrix() <= prixmax) {
            actions.insert(pair);
        }
    }
    return actions;
}

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
    std::multimap<Date, PrixJournalier>::const_iterator it;
    for (it = prixJournaliersMultiMap.begin(); it != prixJournaliersMultiMap.end(); ++it) {
        const std::pair<const Date, PrixJournalier>& pair = *it;
        const PrixJournalier& prix = pair.second;
        if (prix.getDate() == getAujourdhui() && prix.getPrix() <= prixmax) {
            actions.insert(pair);
        }
    }
    return actions;
}


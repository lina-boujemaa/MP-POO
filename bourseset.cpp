#include "bourseSet.h"
#include <algorithm>

BourseSet::BourseSet(const std::set<PrixJournalier>& prixJournaliers)
    : Bourse(prixJournaliers), prixJournaliersSet(prixJournaliers)
{
}


std::set<std::string> BourseSet::getActionsDisponiblesAujourdhui(double prixmax) const
{
    std::set<std::string> actions;
    for (const PrixJournalier& prix : prixJournaliersSet) {
        if (prix.getDate() == aujourdhui && prix.getPrix() <= prixmax) {
            actions.insert(prix.getNomAction());
        }
    }
    return actions;
}

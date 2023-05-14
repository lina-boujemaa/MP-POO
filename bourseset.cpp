#include "bourseset.h"

BourseSet::BourseSet(const std::set<PrixJournalier>& prixJournaliers)
    : Bourse(std::vector<PrixJournalier>(prixJournaliers.begin(), prixJournaliers.end())), prixJournaliersSet(prixJournaliers)
{
}

std::set<std::string> BourseSet::getActionsDisponiblesAujourdhui(double prixmax) const
{
    std::set<std::string> actions;
    for (const PrixJournalier& prix : prixJournaliersSet) {
        if (prix.getDate() == getAujourdhui() && prix.getPrix() <= prixmax) {
            actions.insert(prix.getNomAction());
        }
    }
    return actions;
}

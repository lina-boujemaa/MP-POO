#include "boursevecteur.h"
#include <algorithm>

BourseVector::BourseVector(const std::vector<PrixJournalier>& prixJournaliers)
    : Bourse(prixJournaliers)
{
    this->prixJournaliers = prixJournaliers;
}

std::vector<std::string> BourseVector::getActionsDisponiblesParDate(const Date& date) const
{
    std::vector<std::string> actions;
    std::vector<PrixJournalier>::const_iterator it;
    for (it = prixJournaliers.begin(); it != prixJournaliers.end(); ++it) {
        const PrixJournalier& prix = *it;
        if (prix.getDate() == date) {
            if (std::find(actions.begin(), actions.end(), prix.getNomAction()) == actions.end()) {
                actions.push_back(prix.getNomAction());
            }
        }
    }
    return actions;
}

std::vector<PrixJournalier> BourseVector::getPrixJournaliersParDate(const Date& date) const
{
    std::vector<PrixJournalier> prixJournaliers;
    std::vector<PrixJournalier>::const_iterator it;
    for (it = this->prixJournaliers.begin(); it != this->prixJournaliers.end(); ++it) {
        const PrixJournalier& prix = *it;
        if (prix.getDate() == date) {
            prixJournaliers.push_back(prix);
        }
    }
    return prixJournaliers;
}

PrixJournalier* BourseVector::getPrixActionParDate(std::string action, const Date& date) const
{
    std::vector<PrixJournalier>::const_iterator it;
    for (it = prixJournaliers.begin(); it != prixJournaliers.end(); ++it) {
        const PrixJournalier& prix = *it;
        if (prix.getNomAction() == action && prix.getDate() == date) {
            return const_cast<PrixJournalier*>(&prix);
        }
    }
    return NULL;
}


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
    for (const PrixJournalier& prix : prixJournaliers) {
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
    for (const PrixJournalier& prix : this->prixJournaliers) {
        if (prix.getDate() == date) {
            prixJournaliers.push_back(prix);
        }
    }
    return prixJournaliers;
}

PrixJournalier* BourseVector::getPrixActionParDate(std::string action, const Date& date) const
{
    for (const PrixJournalier& prix : prixJournaliers) {
        if (prix.getNomAction() == action && prix.getDate() == date) {
            return const_cast<PrixJournalier*>(&prix);
        }
    }
    return nullptr;
}

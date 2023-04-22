#include "bourse.h"
#include <algorithm>
#include <cmath>

// Constructor
BourseVector::BourseVector(const std::vector<PrixJournalier>& prixJournaliers)
    : m_prixJournaliers(prixJournaliers)
{
}

// Find all available actions on a specific date
std::vector<std::string> BourseVector::getActionsDisponiblesParDate(const Date& date) const
{
    std::vector<std::string> actions;
    for (const PrixJournalier& prix : m_prixJournaliers) {
        if (prix.getDate() == date) {
            // Check if the action has already been added
            if (std::find(actions.begin(), actions.end(), prix.getNomAction()) == actions.end()) {
                actions.push_back(prix.getNomAction());
            }
        }
    }
    return actions;
}

// Find all prices for a specific date
std::vector<PrixJournalier> BourseVector::getPrixJournaliersParDate(const Date& date) const
{
    std::vector<PrixJournalier> prixJournaliers;
    for (const PrixJournalier& prix : m_prixJournaliers) {
        if (prix.getDate() == date) {
            prixJournaliers.push_back(prix);
        }
    }
    return prixJournaliers;
}

// Find all actions with a price lower or equal to a given amount on a specific date
std::vector<std::string> BourseVector::getActionsDisponiblesParPrixEtDate(const double prixMax, const Date& date) const
{
    std::vector<std::string> actions;
    for (const PrixJournalier& prix : m_prixJournaliers) {
        if (prix.getDate() == date && prix.getPrix() <= prixMax) {
            // Check if the action has already been added
            if (std::find(actions.begin(), actions.end(), prix.getNomAction()) == actions.end()) {
                actions.push_back(prix.getNomAction());
            }
        }
    }
    return actions;
}

// Find the price of an action at a specific date
double BourseVector::getPrixActionParDate(const std::string& nomAction, const Date& date) const
{
    for (const PrixJournalier& prix : m_prixJournaliers) {
        if (prix.getDate() == date && prix.getNomAction() == nomAction) {
            return prix.getPrix();
        }
    }
    return NAN; // Return NaN if the price is not found
}

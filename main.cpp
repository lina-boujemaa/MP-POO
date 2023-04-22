#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>
#include "date.h"
#include "prixjournalier.h"
#include "bourse.h"

using namespace std;

int main() {

    vector<PrixJournalier> historiquePrix;
    ifstream fichier("historique.txt");
    if (!fichier) {
        cerr << "Erreur: impossible d'ouvrir le fichier d'historique des prix." << endl;
        return 1;
    }
    string ligne;
    while (getline(fichier, ligne)) {
        stringstream ss(ligne);
        string dateStr, action;
        double prix;
        ss >> dateStr;
        Date date(dateStr);
        while (ss >> action >> prix) {
            historiquePrix.emplace_back(date, action, prix);
        }
    }

    BourseVector bourse(historiquePrix);


    Date date1("2022-02-28");
    vector<string> actions1 = bourse.getActionsDisponiblesParDate(date1);
    cout << "Actions disponibles le " << date1 << ":" << endl;
    for (const auto& action : actions1) {
        cout << "- " << action << endl;
    }
    cout << endl;


    Date date2("2022-03-01");
    vector<PrixJournalier> prixJournaliers = bourse.getPrixJournaliersParDate(date2);
    cout << "Prix journaliers pour le " << date2 << ":" << endl;
    for (const auto& prix : prixJournaliers) {
        cout << "- " << prix.getAction() << ": " << prix.getPrix() << endl;
    }

    return 0;
}

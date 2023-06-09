#include "boursevecteur.h"
#include "traderaleatoire.h"
#include "portefeuille.h"
#include "simulation.h"
#include "date.h"
#include "persistanceprixjournalier.h"
#include <iostream>
#include "prixjournalier.h"

int main()
{

    std::string cheminFichier = "prices_simple.csv";
    std::vector<PrixJournalier> historique = PersistancePrixJournaliers::lirePrixJournaliersDUnFichier(cheminFichier);


    double soldeInitial = 10000.0;
    Portefeuille portefeuille(soldeInitial);


    TraderAleatoire trader(soldeInitial);

    BourseVector bourse(historique);
   // BourseVector bourse(historique);

    for (const auto& prix : historique) {
        bourse.ajouterPrixJournalier(prix);
    }


    Date dateDebut(2023, 1, 1);
    Date dateFin(2023, 12, 31);


    std::map<std::string, long> result = Simulation::executer(bourse, trader, dateDebut, dateFin, soldeInitial);

    // Affichage des statistiques
    std::cout << "Statistiques du portefeuille :\n";
    for (const auto& entry : result) {
        std::cout << "Action : " << entry.first << ", Quantit� : " << entry.second << "\n";
    }

    return 0;
}


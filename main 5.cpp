#include "boursevector.h"
#include "portefeuille.h"
#include "traderaleatoire.h"
#include <iostream>
#include <chrono>
#include <map>

int main()
{
    // Lecture du jeu de données
    std::vector<PrixJournalier> prixJournaliers = lireDonnees("donnees.csv");

    // Création d'une instance de la classe BourseVector
    BourseVector bourse(prixJournaliers);

    // Création d'un portefeuille avec un solde initial de 1000 euros
    Portefeuille portefeuille(1000);

    // Création d'un trader aléatoire avec un solde initial de 1000 euros
    TraderAleatoire trader(1000);

    // Définition de la période de simulation
    Date dateDebut(2023, 1, 1);
    Date dateFin(2023, 1, 31);

    // Lancement de la simulation
    auto start = std::chrono::high_resolution_clock::now();
    auto stats = Simulation::executer(bourse, trader, dateDebut, dateFin, portefeuille.getSolde());
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    // Affichage des statistiques de la simulation
    std::cout << "Statistiques de la simulation :" << std::endl;
    for (auto it : stats) {
        std::cout << it.first << "\t" << it.second << std::endl;
    }

    // Affichage du temps d'exécution de la simulation
    std::cout << "Temps d'execution de la simulation : " << duration.count() << " us" << std::endl;

    return 0;
}

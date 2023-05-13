#include <string>
#include "prixjournalier.h"

class PersistancePrixJournaliers {
public:
    std::string chemin = "prices_simple.csv";

    static std::vector<PrixJournalier> lirePrixJournaliersDUnFichier(std::string chemin) {
        std::vector<PrixJournalier> historique;
        std::ifstream f(chemin.c_str());
        int nbLignes = 0;
        std::string entete;
        if (f.is_open()) {
            f >> entete;
            while (!f.eof()) {
                PrixJournalier pj;
                f >> pj;
                historique.push_back(pj);
                nbLignes++;
            }
        }
        return historique;
    }
};

#endif // PERSISTANCEPRIXJOURNALIERS_H

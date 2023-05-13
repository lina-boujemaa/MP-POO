#include <string>
#include "prixjournalier.h"

class PersistancePrixJournaliers {
public:
    std::string chemin = "prices_simple.csv";

<<<<<<< HEAD
class PersistancePrixJournaliers
{
    public:
        string chemin = "prices_simple.csy";
        static vector<PrixJournalier> lirePrixJournaliersDUnFichier(string chemin){
            vector<PrixJournalier> historique;
            ifstream f(chemin);
            int nbLignes= 0;
            string entete;
            if(f.is_open()){
                f>>entete;
                while(!f.eof()){
                    PrixJournalier pj;
                    f >> (pj);
                    historique.push_back(pj);
                    nbLignes++;
                }
=======
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
>>>>>>> aa2f80582621e8b97e23d36b76f7f97c7ec4e42f
            }
        }
        return historique;
    }
};

#endif // PERSISTANCEPRIXJOURNALIERS_H

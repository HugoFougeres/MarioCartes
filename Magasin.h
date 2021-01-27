#ifndef MAGASIN_H_INCLUDED
#define MAGASIN_H_INCLUDED
#include "Carte.h"
#include "Carte_creature.h"
#include "Carte_energie.h"
#include "Carte_speciale.h"
#include <windows.h>
#include <vector>
#include <map>
#include <fstream>
#include "Affichage.h"

class Magasin
{
    private:
        int m_nbCrea;
        int m_nbEne;
        int m_nbSpe;
        std::map<std::string,std::vector<Carte*> > m_mapMag;
        Carte_creature* m_crea;
        Carte_energie* m_ene;
        Carte_speciale* m_spe;

    public:
        /// Constructeurs / Destructeur
        Magasin();
        Magasin(int _nbCrea, int _nbEne, int _nbSpe); //Inutile
        ~Magasin();

        /// Getters / Setters
        Carte_creature* getCrea()const;
        Carte_energie* getEne()const;
        Carte_speciale* getSpe()const;
        int getnbCrea() const;
        int getnbEne() const;
        int getnbSpe() const;
        std::map<std::string,std::vector<Carte*> > getmapMag() const;

        void setCrea(Carte_creature* crea);
        void setEne(Carte_energie* ene);
        void setSpe(Carte_speciale* spe);
        void setnbCrea(int nbCrea);
        void setnbEne(int nbEne);
        void setnbSpe(int nbSpe);
        void setmapMag(std::map<std::string,std::vector<Carte*> > mapMag);

        /// Fonctions
        void remplirMag();
        void affichMag(int x);
        Carte* achatcarte(int x, std::string nom);
        Carte* ajoutcarte(std::string nom);
};

#endif // MAGASIN_H_INCLUDED

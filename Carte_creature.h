#ifndef CARTE_CREATURE_H_INCLUDED
#define CARTE_CREATURE_H_INCLUDED
#include "Carte.h"

class Carte_creature : public Carte
{
    private:
        int m_pv;

    public:

        /// Constructeurs / Destructeur
        Carte_creature();
        Carte_creature(std::string _categorie);
        ~Carte_creature();


        /// Getters / Setters
        std::string getcategorie() const;
        int getpv() const;
        void setpv(int pv);
        void setcategorie(std::string categorie);

        /// Fonctions
        int attaque();
        void pertepv(int _degat);
};


#endif // CARTE_CREATURE_H_INCLUDED

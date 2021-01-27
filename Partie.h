#ifndef PARTIE_H_INCLUDED
#define PARTIE_H_INCLUDED

#include "Joueur.h"
#include "Carte.h"
#include "Affichage.h"
#include <iostream>
#include <queue>

class Partie
{
    private:


    public:

        /// Constructeurs / Destructeur
        Partie();
        ~Partie();


        /// Getters / Setters


        /// Fonctions
        void debutPartie();
        void melange(Joueur &j);
        void Carte_Enjeu(Joueur &j);
        Carte* Firstcrea(Joueur &j);
        void affichEnjeu(Joueur &j);
        void affichMain(Carte &cp);
        Carte* Piocher(Joueur &j);
        void Terrain(Joueur &j1, Joueur &j2);
        void GainEnjeu(Joueur &j1, Joueur &j2);
        void PerteEnjeu(Joueur &j);
        void attaque(Joueur &ja, Joueur &jd);
        void menuattaque(int choix, Joueur &ja, Joueur &jd);
        void Jeu();


};

#endif // PARTIE_H_INCLUDED

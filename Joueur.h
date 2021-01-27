#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED
#include <windows.h>
#include <vector>
#include <map>
#include <fstream>
#include <queue>

#include "Magasin.h"
#include "Collec_carte.h"
#include "Carte.h"
#include "Affichage.h"

class Joueur
{
    private:
        std::string m_pseudo;
        int m_pvJ;
        int m_argent;
        int m_argent_debut;
        std::vector<Carte*> m_deck;
        std::queue<Carte*> m_qdeck;
        Carte_creature* m_creaj;
        Carte_energie* m_enej;
        Carte_speciale* m_spej;
        Carte* m_enjeu;
        Carte* m_carteterrain;
        Collec_carte m_collecCarte;
        std::vector<Carte*> m_energie;
        std::vector<Carte*> m_cimetiere;

    public:
        /// Constructeurs / Destructeur
        Joueur();
        Joueur(int _argent, int _argent_debut);
        ~Joueur();

        /// Getters / Setters
        std::string getpseudo();
        int getpvJ();
        int getargent();
        int getargentdebut();
        Collec_carte& getcollecCarte();
        std::vector<Carte*> getdeck() const;
        std::queue<Carte*> getqdeck() const;
        Carte_creature* getCreaj()const;
        Carte_energie* getEnej()const;
        Carte_speciale* getSpej()const;
        Carte* getEnjeu()const;
        Carte* getcarteterrain()const;
        std::vector<Carte*> getenergie() const;
        std::vector<Carte*> getcimetiere() const;

        void setpseudo(std::string pseudo);
        void setpvJ(int pvJ);
        void setargent(int argent);
        void setargentdebut(int argent);
        void setcollecCarte(Collec_carte& collecCarte);
        virtual void setdeck(std::vector<Carte*> deck);
        virtual void setqdeck(std::queue<Carte*> qdeck);
        void setCreaj(Carte_creature* creaj);
        void setEnej(Carte_energie* enej);
        void setSpej(Carte_speciale* spej);
        void setEnjeu(Carte* enjeu);
        void setcarteterrain(Carte* carteterrain);
        void setenergie(std::vector<Carte*> energie);
        void setcimetiere(std::vector<Carte*> cimetiere);

        /// Fonctions
        void creationCollec(Magasin magasin);
        void paiement(int argent);
        Joueur creerJoueur(Joueur j);
        Joueur chargerJoueur(Joueur j);
        void Erase_Line(Joueur j);
        void creationDeck ();
        Joueur remplirCollec(Joueur j);
        void afficherCollection(int x);

};

#endif // JOUEUR_H_INCLUDED

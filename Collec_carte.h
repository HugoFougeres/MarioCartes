#ifndef COLLEC_CARTE_H_INCLUDED
#define COLLEC_CARTE_H_INCLUDED
#include "Carte.h"
#include "Carte_creature.h"
#include "Carte_energie.h"
#include "Carte_speciale.h"

#include<vector>
#include <map>

class Collec_carte
{
    protected:
        Carte_creature* m_crea;
        Carte_energie* m_ene;
        Carte_speciale* m_spe;
        int m_nbCrea;
        int m_nbEne;
        int m_nbSpe;
        std::map <std::string,std::vector<Carte*> > m_mapCarte;
        std::vector<Carte*> m_vectCrea;
        std::vector<Carte*> m_vectEne;
        std::vector<Carte*> m_vectSpe;

    public:
        /// Constructeurs / Destructeur
        Collec_carte();
        Collec_carte(int _nbCrea, int _nbEne, int _nbSpe);
        ~Collec_carte();

        /// Getters / Setters
        virtual Carte_creature* getcrea() const;
        virtual Carte_energie* getene() const;
        virtual Carte_speciale* getspe() const;
        virtual int getnbCrea() const;
        virtual int getnbEne() const;
        virtual int getnbSpe() const;
        virtual std::map <std::string,std::vector<Carte*> > getmapCarte() const;
        virtual std::vector<Carte*> getvectCrea() const;
        virtual std::vector<Carte*> getvectEne() const;
        virtual std::vector<Carte*> getvectSpe() const;

        virtual void setcrea(Carte_creature* crea);
        virtual void setene(Carte_energie* ene);
        virtual void setspe(Carte_speciale* spe);
        virtual void setnbCrea(int nbCrea);
        virtual void setnbEne(int nbEne);
        virtual void setnbSpe(int nbSpe);
        virtual void setmapCarte(std::map <std::string,std::vector<Carte*> > mapCarte);
        virtual void setvectCrea(std::vector<Carte*> vectCrea) ;
        virtual void setvectEne(std::vector<Carte*> vectEne) ;
        virtual void setvectSpe(std::vector<Carte*> vectSpe) ;

        /// Fonctions

};

#endif // COLLEC_CARTE_H_INCLUDED

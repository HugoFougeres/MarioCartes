#ifndef CARTE_H_INCLUDED
#define CARTE_H_INCLUDED

#include <iostream>

class Carte
{
    protected:

        std::string m_nom;
        std::string m_categorie;
        std::string m_description;
        std::string m_type;
        int m_pv;
        int m_deg_faible;
        int m_deg_fort;
        int m_multi;
        int m_prix;

    public:

        /// Constructeurs / Destructeur
        Carte();
        Carte(std::string _nom, int _pv);
        ~Carte();

        /// Getters / Setters
        virtual std::string getnom() const;
        virtual std::string getcategorie() const;
        virtual std::string getdescription() const;
        virtual std::string gettype() const;
        virtual int getpv() const;
        virtual int getdeg_faible()const;
        virtual int getdeg_fort()const;
        virtual int getmulti() const;
        virtual int getprix() const;

        virtual void setnom(std::string nom);
        virtual void setcategorie(std::string categorie);
        void setdescription(std::string description);
        void settype(std::string type);
        virtual void setpv(int pv);
        virtual void setdeg_faible(int deg_faible);
        virtual void setdeg_fort(int deg_fort);
        virtual void setmulti(int multi);
        virtual void setprix(int prix);

        /// Fonctions
};

#endif // CARTE_H_INCLUDED

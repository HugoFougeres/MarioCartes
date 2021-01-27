#include <iostream>
#include "Carte.h"

/// Constructeurs / Destructeur

Carte::Carte()
       :m_nom(), m_prix(), m_pv()
{

}

Carte::Carte(std::string _nom,int _pv)
       :m_nom(_nom),m_pv(_pv)
{

}

Carte::~Carte()
{

}

/// Getters / Setters

std::string Carte::getnom() const
{
    return m_nom;
}

std::string Carte::getcategorie() const
{
    return m_categorie;
}

std::string Carte::getdescription() const
{
    return m_description;
}

std::string Carte::gettype() const
{
    return m_type;
}

int Carte::getpv() const
{
    return m_pv;
}

int Carte::getdeg_faible()const
{
    return m_deg_faible;
}

int Carte::getdeg_fort()const
{
    return m_deg_fort;
}

int Carte::getmulti() const
{
        return m_multi;
}

int Carte::getprix() const
{
    return m_prix;
}

void Carte::setnom(std::string nom)
{
        m_nom=nom;
}

void Carte::setcategorie(std::string categorie)
{
        m_categorie=categorie;
}

void Carte::setdescription(std::string description)
{
    m_description= description;
}

void Carte::settype(std::string type)
{
    m_type= type;
}

void Carte::setpv(int pv)
{
        m_pv=pv;
}

void Carte::setdeg_faible(int deg_faible)
{
    m_deg_faible=deg_faible;
}


void Carte::setdeg_fort(int deg_fort)
{
    m_deg_fort=deg_fort;
}

void Carte::setmulti(int multi)
{
    m_multi=multi;
}

void Carte::setprix(int prix)
{
        m_prix=prix;
}

/// Fonctions

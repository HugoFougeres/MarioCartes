#include <iostream>
#include "Carte_creature.h"

/// Constructeurs / Destructeur

Carte_creature::Carte_creature()
{
    Carte();
}

Carte_creature::Carte_creature(std::string _categorie)
{
    m_categorie= _categorie;
}

Carte_creature::~Carte_creature()
{

}

/// Getters / Setters

std::string Carte_creature::getcategorie() const
{
    return m_categorie;
}

int Carte_creature::getpv() const
{
    return m_pv;
}

void Carte_creature::setpv(int pv)
{
    m_pv=pv;
}

void Carte_creature::setcategorie(std::string categorie)
{
    m_categorie= categorie;
}

/// Fonctions

int Carte_creature::attaque()
{
    std::cout <<"Attaque de la carte" << std::endl;
}

void Carte_creature::pertepv(int _degat)
{
    std::cout << "Perte de" <<_degat << "PV !" << std::endl;
}

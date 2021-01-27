#include <iostream>
#include "Carte_energie.h"

/// Constructeurs / Destructeur

Carte_energie::Carte_energie()
{
    Carte();
}

Carte_energie::Carte_energie(std::string _description, int _multi)
{
    m_description= _description;
    m_multi= _multi;
}

Carte_energie::~Carte_energie()
{

}

/// Getters / Setters

int Carte_energie::getmulti() const
{
        return m_multi;
}

void Carte_energie::setmulti(int multi)
{
    m_multi=multi;
}
/// Fonctions

int Carte_energie::multiply()
{
    std::cout <<"Multiplie les degats" << std::endl;
}


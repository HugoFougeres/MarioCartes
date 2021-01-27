#include <iostream>
#include "Collec_carte.h"

/// Constructeurs / Destructeur

Collec_carte::Collec_carte()
    :m_nbCrea(), m_nbEne(), m_nbSpe()
{

}

Collec_carte::Collec_carte(int _nbCrea, int _nbEne, int _nbSpe)
    :m_nbCrea(_nbCrea), m_nbEne(_nbEne), m_nbSpe(_nbSpe)
{

}

Collec_carte::~Collec_carte()
{

}

/// Getters / Setters

Carte_creature* Collec_carte::getcrea() const
{
    return m_crea;
}

Carte_energie* Collec_carte::getene() const
{
    return m_ene;
}

Carte_speciale* Collec_carte::getspe() const
{
    return m_spe;
}

int Collec_carte::getnbCrea() const
{
    return m_nbCrea;
}

int Collec_carte::getnbEne() const
{
    return m_nbEne;
}

int Collec_carte::getnbSpe() const
{
    return m_nbSpe;
}

std::map<std::string,std::vector<Carte*> > Collec_carte::getmapCarte() const
{
    return m_mapCarte;
}

std::vector<Carte*> Collec_carte::getvectCrea() const
{
    return m_vectCrea;
}

std::vector<Carte*> Collec_carte::getvectEne() const
{
    return m_vectEne;
}

std::vector<Carte*> Collec_carte::getvectSpe() const
{
    return m_vectSpe;
}

void Collec_carte::setcrea(Carte_creature* crea)
{
    m_crea=crea;
}

void Collec_carte::setene(Carte_energie*ene)
{
    m_ene=ene;
}

void Collec_carte::setspe(Carte_speciale* spe)
{
    m_spe=spe;
}

void Collec_carte::setnbCrea(int nbCrea)
{
    m_nbCrea=nbCrea;
}

void Collec_carte::setnbEne(int nbEne)
{
    m_nbEne=nbEne;
}

void Collec_carte::setnbSpe(int nbSpe)
{
    m_nbSpe=nbSpe;
}


void Collec_carte::setmapCarte(std::map<std::string,std::vector<Carte*> > mapCarte)
{
    m_mapCarte=mapCarte;
}

void Collec_carte::setvectCrea(std::vector<Carte*> vectCrea)
{
    m_vectCrea=vectCrea;
}

void Collec_carte::setvectEne(std::vector<Carte*> vectEne)
{
    m_vectEne=vectEne;
}
void Collec_carte::setvectSpe(std::vector<Carte*> vectSpe)
{
    m_vectSpe=vectSpe;
}

/// Fonctions


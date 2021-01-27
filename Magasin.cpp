#include <iostream>
#include "Magasin.h"
#include <string>
#include<fstream>
#include <windows.h>
#include <stdio.h>
#include<stdlib.h>

/// Constructeurs / Destructeur

Magasin::Magasin()
        :m_nbCrea(20), m_nbEne(4), m_nbSpe(7)
{

}

Magasin::Magasin(int _nbCrea, int _nbEne, int _nbSpe)
        :m_nbCrea(_nbCrea), m_nbEne(_nbEne), m_nbSpe(_nbSpe)
{

}

Magasin::~Magasin()
{

}

/// Getters / Setters

Carte_creature* Magasin::getCrea()const
{
    return  m_crea;
}

Carte_energie* Magasin::getEne()const
{
    return  m_ene;
}

Carte_speciale* Magasin::getSpe()const
{
    return  m_spe;
}

int Magasin::getnbCrea() const
{
    return m_nbCrea;
}

int Magasin::getnbEne() const
{
    return m_nbEne;
}

int Magasin::getnbSpe() const
{
    return m_nbSpe;
}

std::map <std::string,std::vector<Carte*> > Magasin::getmapMag() const
{
    return m_mapMag;
}

void Magasin::setCrea(Carte_creature* crea)
{
    m_crea=crea;
}

void Magasin::setEne(Carte_energie* ene)
{
    m_ene=ene;
}

void Magasin::setSpe(Carte_speciale* spe)
{
    m_spe=spe;
}

void Magasin::setnbCrea(int nbCrea)
{
    m_nbCrea=nbCrea;
}

void Magasin::setnbEne(int nbEne)
{
    m_nbEne=nbEne;
}

void Magasin::setnbSpe(int nbSpe)
{
    m_nbSpe=nbSpe;
}

void Magasin::setmapMag(std::map<std::string,std::vector<Carte*> > mapMag)
{
    m_mapMag=mapMag;
}

/// Fonctions

void Magasin::remplirMag() /// fonction qui lit les fichiers afin de remplier le magasin
{
    Carte_creature* Crea;
    Carte_energie* Ene;
    Carte_speciale* Spe;
    std::string nom;
    std::string categorie;
    std::string description;
    std::string type;
    int pv;
    int deg_faible;
    int deg_fort;
    int multi;
    int prix;

    std::vector <Carte*> vectCrea;
    std::vector <Carte*> vectEne;
    std::vector <Carte*> vectSpe;
    std::map<std::string,std::vector<Carte*> > mapMag;
    std::string File1="CartesCreatures.txt";
    std::string File2="CartesEnergies.txt";
    std::string File3="CartesSpeciales.txt";

    std::ifstream Mag1(File1.c_str(),std::ios::in);
    std::ifstream Mag2(File2.c_str(),std::ios::in);
    std::ifstream Mag3(File3.c_str(),std::ios::in);

    if(Mag1)
    {

        for(int i=0; i<getnbCrea(); i++)
        {

            Crea= new Carte_creature;
            Mag1>>nom;
            Crea->setnom(nom);
            Mag1>>categorie;
            Crea->setcategorie(categorie);
            Mag1>>pv;
            Crea->setpv(pv);
            Mag1>>deg_faible;
            Crea->setdeg_faible(deg_faible);
            Mag1>>deg_fort;
            Crea->setdeg_fort(deg_fort);
            Mag1>>prix;
            Crea->setprix(prix);
            Mag1>>type;
            Crea->settype(type);
            setCrea(Crea);
            vectCrea.push_back(getCrea());
        }
        mapMag["Cartes de base"] = vectCrea;
    }Mag1.close();

    if(Mag2)
    {

        for(int i=0; i<getnbEne(); i++)
        {

            Ene= new Carte_energie;
            Mag2>>nom;
            Ene->setnom(nom);
            Mag2>>categorie;
            Ene->setcategorie(categorie);
            Mag2>>multi;
            Ene->setmulti(multi);
            Mag2>>description;
            Ene->setdescription(description);
            Mag2>>prix;
            Ene->setprix(prix);
            Mag2>>type;
            Ene->settype(type);
            setEne(Ene);
            vectEne.push_back(getEne());
        }
        mapMag["Cartes terrain"] = vectEne;
    }Mag2.close();

    if(Mag3)
    {

        for(int i=0; i<getnbSpe(); i++)
        {

            Spe= new Carte_speciale;
            Mag3>>nom;
            Spe->setnom(nom);
            Mag3>>description;
            Spe->setdescription(description);
            Mag3>>prix;
            Spe->setprix(prix);
            Mag3>>type;
            Spe->settype(type);
            setSpe(Spe);
            vectSpe.push_back(getSpe());
        }
        mapMag["Cartes speciale"] = vectSpe;
    }Mag3.close();

    setmapMag(mapMag);
}

void Magasin::affichMag(int x) /// fonction qui affiche le magasin grâce à remplirMag()
{
    int ligne,colonne;
    ligne=1;
    colonne=3;
    std::map<std::string,std::vector<Carte*> >mapMag;
    mapMag=getmapMag();

    Affichage a;
    std::map<std::string,std::vector<Carte*> >::iterator p; //Création d'un itérator sur le 'map'
    for(p = mapMag.begin(); p != mapMag.end(); p++)
    {

        if(x==1 && p->first == "Cartes de base"){
            for(int i=0;i<getnbCrea();++i)
            {
                a.gotoligcol(ligne,colonne);
                std::cout<<"'---------------------------------------";
                if (p->second[i]->getcategorie()== "Hero")
                {
                    a.Color(12,15);
                }
                else if (p->second[i]->getcategorie()== "Bebe")
                {
                    a.Color(1,15);
                }
                else if (p->second[i]->getcategorie()== "Boss")
                {
                    a.Color(5,15);
                }
                else if (p->second[i]->getcategorie()== "Sbires")
                {
                    a.Color(2,15);
                }
                a.gotoligcol(ligne+1,colonne);
                std::cout<<"| Nom de la carte : "<< p->second[i]->getnom()<<"                ";
                a.Color(15,0);
                a.gotoligcol(ligne+2,colonne);
                std::cout<<"'--------------------------------------'";
                a.gotoligcol(ligne+3,colonne);
                std::cout<<"  Categorie : "<<p->second[i]->getcategorie()<<"              ";
                a.gotoligcol(ligne+4,colonne);
                std::cout<<"| Pv : "<<p->second[i]->getpv()<<"                               |";
                a.gotoligcol(ligne+5,colonne);
                std::cout<<"| Degat faible : "<<p->second[i]->getdeg_faible()<<"                     |";
                a.gotoligcol(ligne+6,colonne);
                std::cout<<"| Degat fort : "<<p->second[i]->getdeg_fort()<<"                       |";
                a.gotoligcol(ligne+7,colonne);
                std::cout<<"| Prix : "<<p->second[i]->getprix()<<"                           |";
                a.gotoligcol(ligne+8,colonne);
                std::cout<<"'--------------------------------------'";
                colonne=colonne+40;
                if (colonne>200)
                {
                    ligne+=10;
                    colonne=3;
                }
            }
        }

        if(x==2 && p->first == "Cartes terrain"){
            colonne=50;
            for(int i=0;i<getnbEne();++i)
            {

                a.gotoligcol(ligne,colonne);
                std::cout<<"'----------------------------------------------------";
                if (p->second[i]->getcategorie()== "Hero")
                {
                    a.Color(12,15);
                }
                else if (p->second[i]->getcategorie()== "Bebe")
                {
                    a.Color(1,15);
                }
                else if (p->second[i]->getcategorie()== "Boss")
                {
                    a.Color(5,15);
                }
                else if (p->second[i]->getcategorie()== "Sbires")
                {
                    a.Color(2,15);
                }
                a.gotoligcol(ligne+1,colonne);
                std::cout<<"| Nom de la carte : "<< p->second[i]->getnom()<<"                         ";
                a.Color(15,0);
                a.gotoligcol(ligne+2,colonne);
                std::cout<<"'----------------------------------------------------";
                a.gotoligcol(ligne+3,colonne);
                std::cout<<"  Categorie : "<<p->second[i]->getcategorie()<<"              ";
                a.gotoligcol(ligne+4,colonne);
                std::cout<<"  Description : "<<p->second[i]->getdescription()<<"              ";
                a.gotoligcol(ligne+5,colonne);
                std::cout<<"| Prix : "<<p->second[i]->getprix()<<"                            ";
                a.gotoligcol(ligne+6,colonne);
                std::cout<<"'----------------------------------------------------'";
                colonne=colonne+53;
                if (colonne>126)
                {
                    ligne+=10;
                    colonne=50;
                }
            }
        }

        if(x==3 & p->first == "Cartes speciale"){
            colonne=30;
            for(int i=0;i<getnbSpe();++i)
            {
                a.gotoligcol(ligne,colonne);
                std::cout<<"'---------------------------------------------------------";
                a.Color(5,15);
                a.gotoligcol(ligne+1,colonne);
                std::cout<<"| Nom de la carte : "<< p->second[i]->getnom()<<"                               ";
                a.Color(15,0);
                a.gotoligcol(ligne+2,colonne);
                std::cout<<"'---------------------------------------------------------";
                a.gotoligcol(ligne+3,colonne);
                std::cout<<"  Description : "<<p->second[i]->getdescription()<<"              ";
                a.gotoligcol(ligne+4,colonne);
                std::cout<<"| Prix : "<<p->second[i]->getprix()<<"                                      ";
                a.gotoligcol(ligne+5,colonne);
                std::cout<<"''---------------------------------------------------------";
                colonne=colonne+55;
                if (colonne>150)
                {
                    ligne+=10;
                    colonne=30;
                }
            }
        }
    }



}

Carte* Magasin::ajoutcarte(std::string nom) /// ajoute une carte
{

    std::map<std::string, std::vector<Carte*> > mapMag;
    mapMag= getmapMag();
    Carte* carte;
    carte = new Carte;

    std::map<std::string,std::vector<Carte*> >::iterator q; //Création d'un itérator sur le 'map'
     for(q = mapMag.begin(); q != mapMag.end(); q++)
    {
         if(q->first == "Cartes de base"){
                 for(int i=0;i<getnbCrea();++i)
            {
                if(q->second[i]->getnom()==nom){

                    carte=q->second[i];
                }
            }

        }
        if(q->first == "Cartes terrain"){
                 for(int i=0;i<getnbEne();++i)
            {
                if(q->second[i]->getnom()==nom){

                    carte=q->second[i];
                }
            }

        }
        if(q->first == "Cartes speciale"){
                 for(int i=0;i<getnbSpe();++i)
            {
                if(q->second[i]->getnom()==nom){

                    carte=q->second[i];
                }
            }

        }
    }
    return carte;
}

Carte* Magasin::achatcarte(int x, std::string nom) /// fonction qui permet au joueur d'acheter une carte
{
    int ligne,colonne;
    ligne=1;
    colonne=3;
    std::map<std::string, std::vector<Carte*> > mapMag;
    mapMag= getmapMag();
    Carte* carte;
    carte= new Carte;

    std::map<std::string,std::vector<Carte*> >::iterator p; //Création d'un itérator sur le 'map'
    for(p = mapMag.begin(); p != mapMag.end(); p++)
    {
        if(p->first == "Cartes de base"){
            for(int i=0;i<getnbCrea();++i)
            {
                if(nom== p->second[i]->getnom())
                {
                    carte= p->second[i];

                }
            }
        }

        if(p->first == "Cartes terrain"){
            for(int i=0;i<getnbEne();++i)
            {
                if(nom== p->second[i]->getnom())
                {
                    carte= p->second[i];

                }
            }
        }

        if(p->first == "Cartes speciale"){
            for(int i=0;i<getnbSpe();++i)
            {
                if(nom== p->second[i]->getnom())
                {
                    carte= p->second[i];

                }
            }
        }
    }
    return carte;
}



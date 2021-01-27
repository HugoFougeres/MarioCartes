#include <iostream>
#include "Joueur.h"

/// Constructeurs / Destructeur

Joueur::Joueur()
    :m_argent(4000),m_argent_debut(4000)
{

}

Joueur::Joueur(int _argent, int _argent_debut)
        :m_argent(_argent),m_argent_debut(_argent_debut)
{

}

Joueur::~Joueur()
{

}

/// Getters / Setters

std::string Joueur::getpseudo()
{
    return m_pseudo;
}

int Joueur::getpvJ()
{
    return m_pvJ;
}

int Joueur::getargent()
{
    return m_argent;

}

int Joueur::getargentdebut()
{
    return m_argent_debut;

}

Collec_carte& Joueur::getcollecCarte()
{
    return m_collecCarte;
}

Carte_creature* Joueur::getCreaj()const
{
    return  m_creaj;
}

Carte_energie* Joueur::getEnej()const
{
    return  m_enej;
}

Carte_speciale* Joueur::getSpej()const
{
    return  m_spej;
}

Carte* Joueur::getEnjeu()const
{
    return  m_enjeu;
}

Carte* Joueur::getcarteterrain()const
{
    return  m_carteterrain;
}

std::vector<Carte*> Joueur::getdeck() const
{
    return m_deck;
}

std::queue<Carte*> Joueur::getqdeck() const
{
    return m_qdeck;
}

std::vector<Carte*> Joueur::getenergie() const
{
    return m_energie;
}

std::vector<Carte*> Joueur::getcimetiere() const
{
    return m_cimetiere;
}

void Joueur::setCreaj(Carte_creature* creaj)
{
    m_creaj=creaj;
}

void Joueur::setEnej(Carte_energie* enej)
{
    m_enej=enej;
}

void Joueur::setSpej(Carte_speciale* spej)
{
    m_spej=spej;
}

void Joueur::setEnjeu(Carte* enjeu)
{
    m_enjeu=enjeu;
}

void Joueur::setcarteterrain(Carte* carteterrain)
{
    m_carteterrain=carteterrain;
}

void Joueur::setpseudo(std::string pseudo)
{
    m_pseudo=pseudo;
}

void Joueur::setpvJ(int pvJ)
{
    m_pvJ=pvJ;
}

void Joueur::setargent(int argent)
{
    m_argent=argent;
}

void Joueur::setargentdebut(int argent)
{
    m_argent_debut=argent;
}

void Joueur::setcollecCarte(Collec_carte& collecCarte)
{
    m_collecCarte= collecCarte;
}

void Joueur::setdeck(std::vector<Carte*> deck)
{
    m_deck=deck;
}

void Joueur::setqdeck(std::queue<Carte*> qdeck)
{
    m_qdeck=qdeck;
}

void Joueur::setenergie(std::vector<Carte*> energie)
{
    m_energie=energie;
}

void Joueur::setcimetiere(std::vector<Carte*> cimetiere)
{
    m_cimetiere=cimetiere;
}

/// Fonctions

void Joueur::creationCollec(Magasin magasin) /// fonction qui crée la collection du joueur
{
    Affichage a;
    int choix;
    std::map<std::string, std::vector<Carte*> > collec;
    std::vector <Carte*> collecCrea;
    std::vector <Carte*> collecEne;
    std::vector <Carte*> collecSpe;
    collecCrea = collec["Cartes de base"];
    collecEne = collec["Cartes terrain"];
    collecSpe = collec["Cartes speciale"];
    int boucle = 1;

    magasin.remplirMag();

    do
    {
        a.gotoligcol(23,85);
        std::cout<<"|                Maintenant,                 |";
        a.gotoligcol(24,85);
        std::cout<<"|     Il faut vous creer une collection      |";
        a.gotoligcol(25,85);
        std::cout<<"|     Quelle type de cartes voulez vous      |";
        a.gotoligcol(27,85);
        std::cout<<"|  1 - Carte de base                         |";
        a.gotoligcol(28,85);
        std::cout<<"|  2 - Carte terrain                         |";
        a.gotoligcol(29,85);
        std::cout<<"|  3 - Carte speciale                        |";
        a.gotoligcol(32,85);
        std::cout<<"'~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~'";
        a.gotoligcol(30,87);
        std::cin>>choix;

        switch(choix)
        {
            case 1:
                system("cls");
                {magasin.affichMag(choix);
                a.gotoligcol(40,10);
                std::cout<< "Quelle carte voulez vous :"<<std::endl;
                std::string saisie1;
                a.gotoligcol(40,38);
                std::cin>>saisie1;
                Carte* carte1;
                carte1 = new Carte;
                carte1 = magasin.ajoutcarte(saisie1);

                if(getargent() - carte1->getprix()>=0)
                {

                if(carte1->getnom()=="")
                {
                    a.gotoligcol(40,38);
                    std::cout<<" --------------------------------------------------------- Carte non existante, try again";
                }else{
                    collecCrea.push_back(carte1);
                    paiement(carte1->getprix());
                }
                }
                collec["Cartes de base"] = collecCrea;
                break;}

            case 2:
                system("cls");
                {magasin.affichMag(choix);
                a.gotoligcol(40,10);
                std::cout<< "Quelle carte voulez vous :";
                std::string saisie2;
                a.gotoligcol(40,38);
                std::cin>>saisie2;
                Carte* carte2;
                carte2 = new Carte;
                carte2 = magasin.ajoutcarte(saisie2);

                if(getargent() - carte2->getprix()>=0)
                {
                    if(carte2->getnom()=="")
                {
                    a.gotoligcol(40,38);
                    std::cout<<" --------------------------------------------------------- Carte non existante, try again";
                }else{
                    collecEne.push_back(carte2);
                    paiement(carte2->getprix());
                }
                }
                collec["Cartes terrain"] = collecEne;
                break;}

            case 3:
                system("cls");
                {magasin.affichMag(choix);
                a.gotoligcol(40,10);
                std::cout<< "Quelle carte voulez vous :";
                std::string saisie3;
                a.gotoligcol(40,38);
                std::cin>>saisie3;
                Carte* carte3;
                carte3 = new Carte;
                carte3 = magasin.ajoutcarte(saisie3);

                if(getargent() - carte3->getprix()>=0)
                {
                   if(carte3->getnom()=="")
                {
                    a.gotoligcol(40,38);
                    std::cout<<" --------------------------------------------------------- Carte non existante, try again";
                }else{
                    collecSpe.push_back(carte3);
                    paiement(carte3->getprix());
                }
                }
                collec["Cartes speciale"] = collecSpe;
                break;}
        }
        a.gotoligcol(40,150);
        std::cout<<"'~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        a.gotoligcol(41,150);
        std::cout<<"|Il vous reste : "<<getargent()<< "euros";
        a.gotoligcol(42,150);
        std::cout<<"'~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        a.gotoligcol(43,10);
        std::cout<<"Souhaitez vous acheter une autre carte?" <<std::endl;
        a.gotoligcol(44,10);
        std::cout<<"1-oui" <<std::endl;
        a.gotoligcol(45,10);
        std::cout<<"2-non" <<std::endl;
        a.gotoligcol(46,10);
        std::cin>> boucle;
        system("cls");

    }while(boucle == 1);
    std::ofstream File1(getpseudo() + "Creatures.txt",std::ios::app);
    std::ofstream File2(getpseudo() + "Energies.txt",std::ios::app);
    std::ofstream File3(getpseudo() + "Speciales.txt",std::ios::app);
    if(File1)
    {
        for(int i=0;i<collecCrea.size(); i++){

           File1 << collecCrea[i]->getnom() <<" "
                 << collecCrea[i]->getcategorie() <<" "
                 << collecCrea[i]->getpv() <<" "
                 << collecCrea[i]->getdeg_faible() <<" "
                 << collecCrea[i]->getdeg_fort() <<" "
                 << collecCrea[i]->getprix() <<" "
                 << collecCrea[i]->gettype() <<" "
                 << std::endl;
        }
    }File1.close();
    if(File2)
    {
        for(int i=0;i<collecEne.size(); i++){

           File2 << collecEne[i]->getnom() <<" "
                 << collecEne[i]->getcategorie() <<" "
                 << collecEne[i]->getmulti() <<" "
                 << collecEne[i]->getdescription() <<" "
                 << collecEne[i]->getprix() <<" "
                 << collecEne[i]->gettype() <<" "
                 << std::endl;
        }
    }File2.close();
    if(File3)
    {
        for(int i=0;i<collecSpe.size(); i++){

           File3 << collecSpe[i]->getnom() <<" "
                 << collecSpe[i]->getdescription() <<" "
                 << collecSpe[i]->getprix() <<" "
                 << collecSpe[i]->gettype() <<" "
                 << std::endl;


        }
    }File3.close();
    getcollecCarte().setmapCarte(collec);
    Erase_Line(*this);
}

void Joueur::paiement(int argent) ///fonction qui baisse l'argent du joueur lorsqu'il achete une carte
{

    setargent(getargent()-argent);
}

Joueur Joueur::creerJoueur(Joueur j) /// fonction permettant de créer de nouveaux joueur
{
    Affichage a;

    a.gotoligcol(1,10);
    std::cout<<"d8888b. d888888b d88888b d8b   db db    db d88888b d8b   db db    db d88888b     d8b   db  .d88b.  db    db db    db d88888b  .d8b.  db    db        d88b  .d88b.  db    db d88888b db    db d8888b.";
    a.gotoligcol(2,10);
    std::cout<<"88  `8D   `88'   88'     888o  88 88    88 88'     888o  88 88    88 88'         888o  88 .8P  Y8. 88    88 88    88 88'     d8' `8b 88    88        `8P' .8P  Y8. 88    88 88'     88    88 88  `8D ";
    a.gotoligcol(3,10);
    std::cout<<"88oooY'    88    88ooooo 88V8o 88 Y8    8P 88ooooo 88V8o 88 88    88 88ooooo     88V8o 88 88    88 88    88 Y8    8P 88ooooo 88ooo88 88    88         88  88    88 88    88 88ooooo 88    88 88oobY' ";
    a.gotoligcol(4,10);
    std::cout<<"88~~~b.    88    88~~~~~ 88 V8o88 `8b  d8' 88~~~~~ 88 V8o88 88    88 88~~~~~     88 V8o88 88    88 88    88 `8b  d8' 88~~~~~ 88~~~88 88    88         88  88    88 88    88 88~~~~~ 88    88 88`8b   ";
    a.gotoligcol(5,10);
    std::cout<<"88   8D   .88.   88.     88  V888  `8bd8'  88.     88  V888 88b  d88 88.         88  V888 `8b  d8' 88b  d88  `8bd8'  88.     88   88 88b  d88     db. 88  `8b  d8' 88b  d88 88.     88b  d88 88 `88. ";
    a.gotoligcol(6,10);
    std::cout<<"Y8888P' Y888888P Y88888P VP   V8P    YP    Y88888P VP   V8P ~Y8888P' Y88888P     VP   V8P  `Y88P'  ~Y8888P'    YP    Y88888P YP   YP ~Y8888P'     Y8888P   `Y88P'  ~Y8888P' Y88888P ~Y8888P' 88   YD";


    std::string nom;
    a.gotoligcol(15,85);
    std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl;
    a.gotoligcol(17,85);
    std::cout<<"|  Quel est ton nom ?                        |"<<std::endl;

    a.gotoligcol(21,85);
    std::cout<<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|"<<std::endl;

    a.gotoligcol(19,87);
    std::cin>>nom;
    j.setpseudo(nom);
    std::string File1="Joueur.txt";
    std::string verification_prenom;
    std::ofstream FichierJoueur(File1.c_str(),std::ios::app);

    if(FichierJoueur)
    {
            FichierJoueur << j.getpseudo() <<" "<< j.getargent() <<" "<<std::endl;
    }FichierJoueur.close();
    return j;

}

Joueur Joueur::chargerJoueur(Joueur j) /// fonction permettant de charger les joueurs créés, à l'aide de fichiers
{
    Affichage a;
    a.gotoligcol(1,40);
    std::cout<<" .o88b. db   db  .d8b.  d8888b.  d888b  d88888b d8888b.      d88b  .d88b.  db    db d88888b db    db d8888b. ";
    a.gotoligcol(2,40);
    std::cout<<"d8P  Y8 88   88 d8' `8b 88  `8D 88' Y8b 88'     88  `8D      `8P' .8P  Y8. 88    88 88'     88    88 88  `8D ";
    a.gotoligcol(3,40);
    std::cout<<"8P      88ooo88 88ooo88 88oobY' 88      88ooooo 88oobY'       88  88    88 88    88 88ooooo 88    88 88oobY' ";
    a.gotoligcol(4,40);
    std::cout<<"8b      88~~~88 88~~~88 88`8b   88  ooo 88~~~~~ 88`8b         88  88    88 88    88 88~~~~~ 88    88 88`8b ";
    a.gotoligcol(5,40);
    std::cout<<"Y8b  d8 88   88 88   88 88 `88. 88. ~8~ 88.     88 `88.   db. 88  `8b  d8' 88b  d88 88.     88b  d88 88 `88. ";
    a.gotoligcol(6,40);
    std::cout<<" `Y88P' YP   YP YP   YP 88   YD  Y888P  Y88888P 88   YD   Y8888P   `Y88P'  ~Y8888P' Y88888P ~Y8888P' 88   YD";

    std::string nom;
    a.gotoligcol(10,20);
    std::cout<<"Bienvenue joueur"<<std::endl;
    std::string File1="Joueur.txt";
    a.gotoligcol(12,20);
    std::cout<<"Voici la liste des joueurs enregistres"<<std::endl<<std::endl;
    std::ifstream FichierJoueur(File1.c_str(),std::ios::in);
    if(FichierJoueur){

        std::string mot; //Une variable pour stocker les lignes lues
        std::string argent;
        int ligne=13;
        while(FichierJoueur >> mot) //Tant qu'on n'est pas à la fin, on lit
        {   ligne=ligne+1;
            a.gotoligcol(ligne,20);
            std::cout <<"Prenom : "<<mot<<" ";
            FichierJoueur >> argent;
            a.gotoligcol(ligne,38) ;
            std::cout<<"Argent :"<<argent<<std::endl;
        }
    }FichierJoueur.close();
    std::cout<<std::endl;
    int ok = 0;
    while(ok!=1){
        a.gotoligcol(25,20);
        std::cout<<"Quel est ton nom ?";
        a.gotoligcol(25,40);
        std::cin>>nom;
        std::ifstream FichierJoueur1(File1.c_str(),std::ios::in);
        if(FichierJoueur1){
            std::string verification_prenom; //Une variable pour stocker les lignes lues
            std::string verification_argent;

            while(FichierJoueur1 >> verification_prenom) //Tant qu'on n'est pas à la fin, on lit
              {
                  if(verification_prenom == nom){
                    ok++;
                    j.setpseudo(nom);
                    FichierJoueur1 >> verification_argent;
                    j.setargent(std::stoi(verification_argent));
                    j.setargentdebut(std::stoi(verification_argent));

                  }else{

                  }
              }
        }FichierJoueur.close();

        if(ok==0){
            a.gotoligcol(25,20);
            std::cout<<"Quel est ton nom?";
            a.gotoligcol(25,40);
            std::cout<<"                        ";
        }
    }
    system("cls");
    return j;

}

void Joueur::Erase_Line(Joueur j) /// fonction permettant d'effacer une ligne d'un fichier
{

    std::string File1="Joueur.txt";
    //std::cout<<"Erase line"<<std::endl;
    std::ifstream FichierJoueur(File1,std::ios::in);
    std::string Buffer = j.getpseudo()+" "+std::to_string(j.getargent())+" "+'\n'; //Variable contenant le texte à réécrire dans le fichier
    if (FichierJoueur) //Si le fichier est trouvé
    {

        std::string line;
        int Line = 0;
        std::string nom = j.getpseudo() +" ";
        int argent = j.getargentdebut();
        nom = nom + std::to_string(argent)+" ";
        while ( std::getline( FichierJoueur, line ) ) //on parcours le fichier et on initialise line à la ligne actuelle
        {
            //std::cout<<line<<std::endl;

            if(line!=nom){
                Buffer += line + '\n';
            }
        }
    }
    FichierJoueur.close(); //On ferme le fichier en lecture

    if( remove( "Joueur.txt" ) != 0 ){
    }
  else{
  }
    std::ofstream NewFichierJoueur(File1, std::ios::app);
    NewFichierJoueur << Buffer;
    NewFichierJoueur.close();
    j.setargentdebut(j.getargent());


}

void Joueur::creationDeck() /// fonction qui crée un deck pour le joueur
{
    Affichage a;
    int saisie;
    std::vector<Carte*> deck;
    int boucle=1;
    int boucle1=1;
    int erreur=1;
    do
    {
        a.gotoligcol(23,85);
        std::cout<<"|                AJOUT DES CARTES AU DECK                |";
        a.gotoligcol(24,85);
        std::cout<<"|    Entrez le type de la carte que vous souhaitez :     |";
        a.gotoligcol(25,85);
        std::cout<<"|  1 - Carte de base                                     |";
        a.gotoligcol(26,85);
        std::cout<<"|  2 - Carte terrain                                     |";
        a.gotoligcol(27,85);
        std::cout<<"|  3 - Carte speciale                                    |";
        a.gotoligcol(30,85);
        std::cout<<"'~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~'";
        a.gotoligcol(28,87);
        std::cin>>saisie;
        system("cls");
        switch(saisie)
        {

            case 1:
            {
                std::string choixCrea;
                remplirCollec(*this);
                afficherCollection(saisie);
                std::map <std::string,std::vector<Carte*> > mapCollec;
                mapCollec=getcollecCarte().getmapCarte();

                do{
                    std::cout<<std::endl;
                    std::cout<< "Quelle carte voulez vous :"<<std::endl;
                    std::cin>>choixCrea;
                    std::map<std::string,std::vector<Carte*> >::iterator p; //Création d'un itérator sur le 'map'
                    for(p = mapCollec.begin(); p != mapCollec.end(); p++)
                    {
                        if(p->first == "Cartes de base")
                        {
                            for(int i=0; i<p->second.size(); ++i)
                            {
                                if(p->second[i]->getnom() == choixCrea)
                                {
                                    deck.push_back(p->second[i]);
                                    erreur = 0;
                                    system("cls");
                                }
                            }
                        }
                    }
                }while(erreur==1);
                break;
            }

            case 2:
            {
                std::string choixEne;
                remplirCollec(*this);
                afficherCollection(saisie);
                std::map <std::string,std::vector<Carte*> > mapCollec;
                mapCollec=getcollecCarte().getmapCarte();
                do{
                    std::cout<<std::endl;
                    std::cout<< "Quelle carte voulez vous :"<<std::endl;
                    std::cin>>choixEne;
                    std::map<std::string,std::vector<Carte*> >::iterator p; //Création d'un itérator sur le 'map'
                    for(p = mapCollec.begin(); p != mapCollec.end(); p++)
                    {
                        if(p->first == "Cartes terrain")
                        {
                            for(int i=0; i<p->second.size(); ++i)
                            {
                                if(p->second[i]->getnom() == choixEne)
                                {
                                    deck.push_back(p->second[i]);
                                    erreur= 0;
                                    system("cls");
                                }

                            }
                        }
                    }
                }while(erreur==1);
                break;
            }

            case 3:
            {
                std::string choixSpe;
                remplirCollec(*this);
                afficherCollection(saisie);
                std::map <std::string,std::vector<Carte*> > mapCollec;
                mapCollec=getcollecCarte().getmapCarte();
                do{
                    std::cout<<std::endl;
                    std::cout<< "Quelle carte voulez vous :"<<std::endl;
                    std::cin>>choixSpe;
                    std::map<std::string,std::vector<Carte*> >::iterator p; //Création d'un itérator sur le 'map'
                    for(p = mapCollec.begin(); p != mapCollec.end(); p++)
                    {
                        if(p->first == "Cartes speciale")
                        {
                            for(int i=0; i<p->second.size(); ++i)
                            {
                                if(p->second[i]->getnom() == choixSpe)
                                {
                                    deck.push_back(p->second[i]);
                                    erreur= 0;
                                    system("cls");
                                }

                            }
                        }
                    }
                }while(erreur==1);
                break;
            }
            default:
                std::cout<<"Mauvaise categorie"<<std::endl;
                break;
        }
    }while(deck.size()<=7);
    this->setdeck(deck);
}

Joueur Joueur::remplirCollec(Joueur j) /// fonction qui rempli la collection du joueur, en parcourant des fichiers
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
    std::map<std::string, std::vector<Carte*> > collecj;
    std::vector <Carte*> collecCreaj;
    std::vector <Carte*> collecEnej;
    std::vector <Carte*> collecSpej;
    collecCreaj = collecj["Cartes de base"];
    collecEnej = collecj["Cartes terrain"];
    collecSpej = collecj["Cartes speciale"];
    std::string File1= j.getpseudo()+"Creatures.txt";
    std::string File2=j.getpseudo()+"Energies.txt";
    std::string File3=j.getpseudo()+"Speciales.txt";
    std::ifstream CollecCrea(File1.c_str(),std::ios::in);
    std::ifstream CollecEne(File2.c_str(),std::ios::in);
    std::ifstream CollecSpe(File3.c_str(),std::ios::in);

    int compteur = 0;
    int compteurEne = 0;
    int compteurSpe = 0;
    std::string line;
    std::string lineEne;
    std::string lineSpe;
    if(CollecCrea)
    {
        while (getline(CollecCrea, line))
        compteur++;

    }CollecCrea.close();
    if(CollecEne)
    {
        while(getline(CollecEne, lineEne))
            compteurEne++;
    }CollecEne.close();
    if(CollecSpe)
    {
        while(getline(CollecSpe, lineSpe))
            compteurSpe++;
    }CollecSpe.close();

    std::ifstream CollecCrea1(File1.c_str(),std::ios::in);
    if(CollecCrea1)
    {
        for(int i=0; i<compteur; i++)
        {

            Crea= new Carte_creature;
            CollecCrea1>>nom;
            Crea->setnom(nom);
            CollecCrea1>>categorie;
            Crea->setcategorie(categorie);
            CollecCrea1>>pv;
            Crea->setpv(pv);
            CollecCrea1>>deg_faible;
            Crea->setdeg_faible(deg_faible);
            CollecCrea1>>deg_fort;
            Crea->setdeg_fort(deg_fort);
            CollecCrea1>>prix;
            Crea->setprix(prix);
            CollecCrea1>>type;
            Crea->settype(type);
            setCreaj(Crea);
            collecCreaj.push_back(getCreaj());
        }
    }CollecCrea1.close();
    collecj["Cartes de base"] = collecCreaj;

    std::ifstream CollecEne1(File2.c_str(),std::ios::in);
    if(CollecEne1)
    {
        for(int i=0; i<compteurEne; i++)
        {

            Ene= new Carte_energie;
            CollecEne1>>nom;
            Ene->setnom(nom);
            CollecEne1>>categorie;
            Ene->setcategorie(categorie);
            CollecEne1>>multi;
            Ene->setmulti(multi);
            CollecEne1>>description;
            Ene->setdescription(description);
            CollecEne1>>prix;
            Ene->setprix(prix);
            CollecEne1>>type;
            Ene->settype(type);
            setEnej(Ene);
            collecEnej.push_back(getEnej());
        }
    }CollecEne1.close();
    collecj["Cartes terrain"] = collecEnej;

    std::ifstream CollecSpe1(File3.c_str(),std::ios::in);
    if(CollecSpe1)
    {
        for(int i=0; i<compteurSpe; i++)
        {

            Spe= new Carte_speciale;
            CollecSpe1>>nom;
            Spe->setnom(nom);
            CollecSpe1>>description;
            Spe->setdescription(description);
            CollecSpe1>>prix;
            Spe->setprix(prix);
            CollecSpe1>>type;
            Spe->settype(type);

            setSpej(Spe);
            collecSpej.push_back(getSpej());
        }
    }CollecSpe1.close();
    collecj["Cartes speciale"] = collecSpej;

    getcollecCarte().setmapCarte(collecj);
    return j;
}

void Joueur::afficherCollection(int x) /// fonction qui affiche la collection de joueur, en parcourant utilisant remplirCollec
{
    Affichage a;
    std::map <std::string,std::vector<Carte*> > mapCollec;
    mapCollec=getcollecCarte().getmapCarte();
    int ligne,colonne;
    ligne=1;
    colonne=3;
     std::map<std::string,std::vector<Carte*> >::iterator p; //Création d'un itérator sur le 'map'

    for(p = mapCollec.begin(); p != mapCollec.end(); p++)
    {
        if(x==1 && p->first == "Cartes de base")
        {
            for(int i=0; i<p->second.size(); ++i)
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
                std::cout<<"'--------------------------------------'";
                colonne=colonne+40;
                if (colonne>200)
                {
                    ligne+=10;
                    colonne=3;
                }
            }
        }
        if(x==2 && p->first == "Cartes terrain")
        {
            for(int i=0; i<p->second.size(); ++i)
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
                std::cout<<"'----------------------------------------------------'";
                colonne=colonne+53;
                if (colonne>126)
                {
                    ligne+=10;
                    colonne=50;
                }
            }
        }
        if(x==3 && p->first == "Cartes speciale")
        {
            for(int i=0; i<p->second.size(); ++i)
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




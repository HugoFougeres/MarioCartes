#include <iostream>
#include "Partie.h"
#include <algorithm>
#include <ctime>

/// Constructeurs / Destructeur

Partie::Partie()
{

}

Partie::~Partie()
{

}

/// Fonctions

void Partie::debutPartie() /// menu partie
{

    int choix;
    Magasin m;
    Affichage a;

    a.gotoligcol(25,85);

    do{
    a.gotoligcol(1,70);
    std::cout<<"d8888b. d888888b d88888b d8b   db db    db d88888b d8b   db db    db d88888b "<<std::endl;
    a.gotoligcol(2,70);
    std::cout<<"88  `8D   `88'   88'     888o  88 88    88 88'     888o  88 88    88 88'    "<<std::endl;
    a.gotoligcol(3,70);
    std::cout<<"88oooY'    88    88ooooo 88V8o 88 Y8    8P 88ooooo 88V8o 88 88    88 88ooooo "<<std::endl;
    a.gotoligcol(4,70);
    std::cout<<"88~~~b.    88    88~~~~~ 88 V8o88 `8b  d8' 88~~~~~ 88 V8o88 88    88 88~~~~~"<<std::endl;
    a.gotoligcol(5,70);
    std::cout<<"88   8D   .88.   88.     88  V888  `8bd8'  88.     88  V888 88b  d88 88.  "<<std::endl;
    a.gotoligcol(6,70);
    std::cout<<"Y8888P' Y888888P Y88888P VP   V8P    YP    Y88888P VP   V8P ~Y8888P' Y88888P"<<std::endl;
    a.gotoligcol(10,40);
    std::cout<<"d8888b.  .d8b.  d8b   db .d8888.   .88b  d88.  .d8b.  d8888b. d888888b  .d88b.     .o88b.  .d8b.  d8888b. d888888b d88888b .d8888."<<std::endl;
    a.gotoligcol(11,40);
    std::cout<<"88  `8D d8' `8b 888o  88 88'  YP   88'YbdP`88 d8' `8b 88  `8D   `88'   .8P  Y8.   d8P  Y8 d8' `8b 88  `8D `~~88~~' 88'     88'  YP"<<std::endl;
    a.gotoligcol(12,40);
    std::cout<<"88   88 88ooo88 88V8o 88 `8bo.     88  88  88 88ooo88 88oobY'    88    88    88   8P      88ooo88 88oobY'    88    88ooooo `8bo."<<std::endl;
    a.gotoligcol(13,40);
    std::cout<<"88   88 88~~~88 88 V8o88   `Y8b.   88  88  88 88~~~88 88`8b      88    88    88   8b      88~~~88 88`8b      88    88~~~~~   `Y8b."<<std::endl;
    a.gotoligcol(14,40);
    std::cout<<"88  .8D 88   88 88  V888 db   8D   88  88  88 88   88 88 `88.   .88.   `8b  d8'   Y8b  d8 88   88 88 `88.    88    88.     db   8D "<<std::endl;
    a.gotoligcol(15,40);
    std::cout<<"Y8888D' YP   YP VP   V8P `8888Y'   YP  YP  YP YP   YP 88   YD Y888888P  `Y88P'     `Y88P' YP   YP 88   YD    YP    Y88888P `8888Y'"<<std::endl;
    a.gotoligcol(28,85);
    std::cout<<"|   Que voulez vous faire ? :                  |"<<std::endl;
    a.gotoligcol(30,85);
    std::cout<<"|     1 - Creer un nouveau joueur              |"<<std::endl;
    a.gotoligcol(32,85);
    std::cout<<"|     2 - Acheter des cartes                   |"<<std::endl;
    a.gotoligcol(34,85);
    std::cout<<"|     3 - Jouer un duel                        |"<<std::endl;
    a.gotoligcol(36,85);
    std::cout<<"|     4 - Quitter                              |"<<std::endl;
    a.gotoligcol(40,85);
    std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl;

    a.gotoligcol(38,88);
    std::cin>>choix;



    switch(choix)
        {
            case 1:
                {

                system("cls");
                Joueur j;
                j = j.creerJoueur(j);
                j.creationCollec(m);
                break;
                }

            case 2:
                {
                    system("cls");
                    Joueur j;
                    j=j.chargerJoueur(j);
                    j.creationCollec(m);
                break;}

            case 3:
                {
                    Partie p;
                    p.Jeu();
                break;}
            case 4:
                {
                break;}
        }

    }while(choix==1||choix==2||choix==3||choix==4);
}

void Partie::melange(Joueur &j) /// melange le deck
{
    std::srand ( unsigned ( std::time(0) ) );
    std::vector<Carte*> deck;
    deck=j.getdeck();
    std::random_shuffle(deck.begin(), deck.end());
    j.setdeck(deck);

    std::queue<Carte*> qdeck;
    for (const auto& e: deck) /// le vecteur devient une file
    {
        qdeck.push(e);
    }
    j.setqdeck(qdeck);
}

void Partie::Carte_Enjeu(Joueur &j) /// selection carte enjeu
{
    std::queue<Carte*> qdeck;
    qdeck=j.getqdeck();
    Carte* carte1=new Carte();
    carte1=qdeck.front();
    j.setEnjeu(carte1);

    qdeck.pop(); /// on retire la carte du deck
    j.setqdeck(qdeck);
}

void Partie::affichEnjeu(Joueur &j) /// affiche carte enjeu
{
    std::cout<<"Voici votre carte Enjeu"<<std::endl;
    Carte* carte1=new Carte();
    carte1=j.getEnjeu();
    if(carte1->gettype()=="creature")
    {
        std::cout<<"Nom: "<<carte1->getnom()<<std::endl;
        std::cout<<"Categorie: "<<carte1->getcategorie()<<std::endl;
    }
    if(carte1->gettype()=="energie")
    {
        std::cout<<"Nom: "<<carte1->getnom()<<std::endl;
        std::cout<<"Categorie: "<<carte1->getcategorie()<<std::endl;
    }
    if(carte1->gettype()=="speciale")
    {
        std::cout<<"Nom: "<<carte1->getnom()<<std::endl;
    }
}

Carte* Partie::Firstcrea(Joueur &j) /// alloue la premiere creature au joueur
{
    Carte* carte1=new Carte();
    Carte* carte2=new Carte();
    std::queue<Carte*> qdeck;
    qdeck=j.getqdeck();
    for(int i = 0 ; i < qdeck.size() ; i++)
    {
        if(qdeck.front()->gettype()=="creature")
        {
            carte1 = qdeck.front();
        }
        else{
            carte2 = qdeck.front();
            qdeck.push(carte2);
            qdeck.pop();
        }
    }
    qdeck.pop();
    j.setqdeck(qdeck);
    return carte1;
}

Carte* Partie::Piocher(Joueur &j) /// le joueur pioche
{
    Carte* carte1=new Carte();
    std::queue<Carte*> qdeck;
    qdeck=j.getqdeck();
    std::cout<<"Il vous reste "<<qdeck.size()<<"carte(s) !"<<std::endl;
    carte1=qdeck.front();
    qdeck.pop();
    return carte1;
}

void Partie::GainEnjeu(Joueur &j1, Joueur &j2) /// le joueur gagne la carte enjeu
{
    Carte* carte1=new Carte();
    carte1=j2.getEnjeu();
    j1.setEnjeu(carte1);

    if(j1.getEnjeu()->gettype()=="creature")
    {
        std::ofstream File1(j1.getpseudo() + "Creatures.txt",std::ios::app);
        if(File1)
        {
           File1 << j1.getEnjeu()->getnom() <<" "
                 << j1.getEnjeu()->getcategorie() <<" "
                 << j1.getEnjeu()->getpv() <<" "
                 << j1.getEnjeu()->getdeg_faible() <<" "
                 << j1.getEnjeu()->getdeg_fort() <<" "
                 << j1.getEnjeu()->getprix() <<" "
                 << j1.getEnjeu()->gettype() <<" "
                 << std::endl;
        }File1.close();
    }
    if(j1.getEnjeu()->gettype()=="energie")
    {
        std::ofstream File2(j1.getpseudo() + "Energies.txt",std::ios::app);
        if(File2)
        {
           File2 << j1.getEnjeu()->getnom() <<" "
                 << j1.getEnjeu()->getcategorie() <<" "
                 << j1.getEnjeu()->getmulti() <<" "
                 << j1.getEnjeu()->getdescription() <<" "
                 << j1.getEnjeu()->getprix() <<" "
                 << j1.getEnjeu()->gettype() <<" "
                 << std::endl;
        }File2.close();
    }
    if(j1.getEnjeu()->gettype()=="speciale")
    {
        std::ofstream File3(j1.getpseudo() + "Speciales.txt",std::ios::app);
        if(File3)
        {
           File3 << j1.getEnjeu()->getnom() <<" "
                 << j1.getEnjeu()->getdescription() <<" "
                 << j1.getEnjeu()->getprix() <<" "
                 << j1.getEnjeu()->gettype() <<" "
                 << std::endl;
        }File3.close();
    }
}

void Partie::PerteEnjeu(Joueur &j) /// le joueur perd la carte enjeu
{
    std::string pseudo = j.getpseudo();
    std::string Buffer;
    std::string line;
    int Line = 0;

    if(j.getEnjeu()->gettype()=="creature")
    {
        std::string File1= pseudo + "Creatures.txt";
        std::ifstream FichierJoueur(File1,std::ios::in);
        if (FichierJoueur) //Si le fichier est trouvé
    {
        std::string carte = j.getEnjeu()->getnom()+ " "
                         +j.getEnjeu()->getcategorie() + " "
                         + std::to_string(j.getEnjeu()->getpv()) + " "
                         + std::to_string(j.getEnjeu()->getdeg_faible()) + " "
                         + std::to_string(j.getEnjeu()->getdeg_fort())+ " "
                         + std::to_string(j.getEnjeu()->getprix())+ " "
                         + j.getEnjeu()->gettype()+ " ";


        while ( std::getline( FichierJoueur, line ) ) //on parcours le fichier et on initialise line à la ligne actuelle
        {
            if(line!=carte){
                Buffer += line + '\n';
            }
        }
    }
    FichierJoueur.close();
    if( remove( File1.c_str() ) != 0 ){
    }
    else{
    }
    std::ofstream NewFichierJoueur(File1, std::ios::app);
    NewFichierJoueur << Buffer;
    NewFichierJoueur.close();
    }
    if(j.getEnjeu()->gettype()=="energie")
    {
        std::string File2 = pseudo + "Energies.txt";
        std::ifstream FichierJoueur2(File2,std::ios::in);
        if (FichierJoueur2) //Si le fichier est trouvé
        {
            std::string carte2 = j.getEnjeu()->getnom()+ " "
                             +j.getEnjeu()->getcategorie() + " "
                             + std::to_string(j.getEnjeu()->getmulti()) + " "
                             + j.getEnjeu()->getdescription() + " "
                             + std::to_string(j.getEnjeu()->getprix())+ " "
                             + j.getEnjeu()->gettype()+ " ";

            while ( std::getline( FichierJoueur2, line ) ) //on parcours le fichier et on initialise line à la ligne actuelle
            {
                if(line!=carte2){
                    Buffer += line + '\n';
                }
            }
        }
        FichierJoueur2.close();
        if( remove( File2.c_str() ) != 0 ){
        }
        else{
        }
        std::ofstream NewFichierJoueur2(File2, std::ios::app);
        NewFichierJoueur2 << Buffer;
        NewFichierJoueur2.close();
    }

    if(j.getEnjeu()->gettype()=="speciale")
    {
        std::string File3 = pseudo + "Speciales.txt";
        std::ifstream FichierJoueur3(File3,std::ios::in);
        if (FichierJoueur3) //Si le fichier est trouvé
        {
            std::string carte3 = j.getEnjeu()->getnom()+ " "
                             +j.getEnjeu()->getdescription() + " "
                             + std::to_string(j.getEnjeu()->getprix()) + " "
                             + j.getEnjeu()->gettype()+ " ";

            while ( std::getline( FichierJoueur3, line ) ) //on parcours le fichier et on initialise line à la ligne actuelle
            {
                if(line!=carte3){
                    Buffer += line + '\n';
                }
            }
        }
        FichierJoueur3.close();
        if( remove( File3.c_str() ) != 0 ){
        }
        else{
        }
        std::ofstream NewFichierJoueur3(File3, std::ios::app);
        NewFichierJoueur3 << Buffer;
        NewFichierJoueur3.close();
    }

}

void Partie::affichMain(Carte &cp) /// affiche la main du joueur
{
    if(cp.gettype()=="creature")
    {
        std::cout<<"Nom: "<<cp.getnom()<<std::endl;
        std::cout<<"Categorie: "<<cp.getcategorie()<<std::endl;
        std::cout<<"Pv: "<<cp.getpv()<<std::endl;
        std::cout<<"1ere attaque: "<<cp.getdeg_faible()<<std::endl;
        std::cout<<"2de attaque: "<<cp.getdeg_fort()<<std::endl;
    }
    if(cp.gettype()=="energie")
    {
        std::cout<<"Nom: "<<cp.getnom()<<std::endl;
        std::cout<<"Categorie: "<<cp.getcategorie()<<std::endl;
    }
    if(cp.gettype()=="speciale")
    {
        std::cout<<"Nom: "<<cp.getnom()<<std::endl;
        std::cout<<"Description: "<<cp.getdescription()<<std::endl;
    }
}

void Partie::Terrain(Joueur &j1, Joueur &j2)
{
    Affichage a; ///Premier joueur en bas a gauche
    a.gotoligcol(34,4);
    std::cout<< " Nom Joueur 1 : "<< j1.getpseudo();

    if(j1.getpvJ()>=0)
    {
        a.gotoligcol(36,4);
        std::cout<< " PV : "<< j1.getpvJ();
    }
    else
    {
        a.gotoligcol(36,4);
        std::cout<< " PV : 0";
    }

    if(j1.getcarteterrain()->getnom().empty())
    {
    }
    else{
        a.gotoligcol(38,4);
        std::cout<< "Creature : "<< j1.getcarteterrain()->getnom()<<std::endl;
        if(j1.getcarteterrain()->getpv()>>0)
        {
            a.gotoligcol(40,4);
            std::cout<< "PV CREATURE : "<<j1.getcarteterrain()->getpv()<<std::endl;
            a.gotoligcol(42,4);
            std::cout<< "DEGAT FAIBLE : "<<j1.getcarteterrain()->getdeg_faible()<<std::endl;
            a.gotoligcol(44,4);
            std::cout<< "DEGAT FORT : "<<j1.getcarteterrain()->getdeg_fort()<<std::endl;
        }
    }

    int ligne1=40;
    int colonne1=54;
    a.gotoligcol(38, 54);
    std::cout << "Energies : ";
    std::vector<Carte*> energie1;
    if(j1.getenergie().empty())
    {

    }else{
        energie1=j1.getenergie();
        for(int i=0; i<energie1.size(); i++)
        {
            a.gotoligcol(ligne1+i, colonne1);
            std::cout<<energie1[i]->getnom();
        }
    }


    a.gotoligcol(2,130);
    std::cout<< " Nom Joueur 2 : "<< j2.getpseudo(); ///Deuxieme joueur en haut a droite
    if(j2.getpvJ()>=0)
    {
        a.gotoligcol(4,130);
        std::cout<< " PV : "<< j2.getpvJ();
    }else
    {
        a.gotoligcol(4,130);
        std::cout<< " PV : 0";
    }

    a.gotoligcol(6,130);
    if(j2.getcarteterrain()->getnom().empty())
    {
    }
    else{
        a.gotoligcol(8,130);
        std::cout<< "Creature : "<< j2.getcarteterrain()->getnom()<<std::endl;
        if(j2.getcarteterrain()->getpv()>>0)
        {
            a.gotoligcol(10, 130);
            std::cout<< "PV CREATURE : "<<j2.getcarteterrain()->getpv()<<std::endl;
            a.gotoligcol(12, 130);
            std::cout<< "DEGAT FAIBLE : "<<j2.getcarteterrain()->getdeg_faible()<<std::endl;
            a.gotoligcol(14, 130);
            std::cout<< "DEGAT FORT : "<<j2.getcarteterrain()->getdeg_fort()<<std::endl;
        }
    }
    a.gotoligcol(8, 180);
    std::cout << "Energies : ";
    std::vector<Carte*> energie2;
    energie2=j2.getenergie();
    int ligne2=10;
    int colonne2=180;
    for(int i=0; i<energie2.size(); i++)
    {
        a.gotoligcol(ligne2+i, colonne2);
        std::cout<<energie2[i]->getnom();
    }
}

void Partie::Jeu()
{
    //////////////////////////////////////////////////INITIALISATION PARTIE////////////////////////////////////////////////////////////
    Affichage a;
    std::cout<<"DUEL"<<std::endl;
    system("cls");
    Joueur j1;
    Joueur j2;
    j1.setpvJ(6);
    j2.setpvJ(6);
    a.gotoligcol(11,20);
    std::cout<<"Choisir joueur 1 :";
    j1=j1.chargerJoueur(j1);
    system("cls");
    a.gotoligcol(11,20);
    std::cout<<"Choisir joueur 2 :";
    j2=j2.chargerJoueur(j2);
    system("cls");
    a.gotoligcol(11,20);
    std::cout<<"Creer deck "<<j1.getpseudo()<<std::endl;
    j1.creationDeck();
    system("cls");
    a.gotoligcol(11,20);
    std::cout<<"Creer deck "<<j2.getpseudo()<<std::endl;
    j2.creationDeck();
    system("cls");

    Partie p;
    p.melange(j1); //melange deck joueur 1
    p.melange(j2); //melange deck joueur 2
    p.Carte_Enjeu(j1); //prise de la carte enjeu
    p.Carte_Enjeu(j2);

    ///////////////////////////////////////////////////////DEBUT PARTIE/////////////////////////////////////////////////////////////////

    Carte* cp=new Carte(); //création de la carte tirée par le joueur
    Joueur jp; //création d'un joueur principal
    bool jeu=true;
    bool fin=true;
    int cpt=0;

    int r= rand() %2 +1; ///tire un nombre entre 1 et 2
    if(r==1)
    {
        jp= j1; // joueur principal choisi de façon aléatoire
    }
    if(r==2)
    {
        jp= j2;
    }
    system("cls");
    do{

        if(cpt>>1)
        {
            if(jp.getcarteterrain()->getpv()<=0) //si une carte creature n'a plus de point de vie
            {
                std::vector<Carte*> cimetiere1;
                cimetiere1=jp.getcimetiere();
                cimetiere1.push_back(cp);
                jp.setcimetiere(cimetiere1); //elle va au cimetiere
                if(jp.getqdeck().size()>=1)
                {
                    cp=p.Firstcrea(jp);
                    std::cout<<"Une nouvelle creature a ete pose :"<<std::endl;
                    p.affichMain(*cp);
                    jp.setcarteterrain(cp);
                }else
                {
                    std::cout<<"Plus de carte creature"<<std::endl;
                    jp.setpvJ(0); /// fin de la partie
                }
                std::string name;
                name=jp.getcarteterrain()->getnom();
                if(name=="")
                {
                    std::cout<<"Plus de carte creature"<<std::endl;
                    jp.setpvJ(0); /// fin de la partie
                }
            }

            cp = p.Piocher(jp);

            if(jp.getpvJ()<=0) //condidtions defaite
            {
                system("cls");
                a.gotoligcol(23,93);
                std::cout<<"| DEFAITE DE "<<jp.getpseudo();
                a.gotoligcol(24,93);
                std::cout<<"| L adversaire a reçu votre carte enjeu :";
                a.gotoligcol(25,93);
                std::cout<<"| "<<jp.getEnjeu()->getnom();

                if(jp.getpseudo()==j1.getpseudo())
                {
                    p.GainEnjeu(j2, j1);
                    p.PerteEnjeu(j1);
                }
                if(jp.getpseudo()==j2.getpseudo())
                {
                    p.GainEnjeu(j1, j2);
                    p.PerteEnjeu(j2);
                }
                Sleep(10000);
                system("cls");
                jeu=false;
                fin=false;
            }
        }
        //system("cls");

        if(jeu) /// boucle des tours de jeu
        {

            std::cout<<"TOUR DE "<<jp.getpseudo()<<std::endl;

            if(cpt==0 || cpt==1) //cas du premier tour pour les deux joueurs
            {
                cp=p.Firstcrea(jp);
                std::cout<<"Voici votre premiere creature :"<<std::endl;
                p.affichMain(*cp);
                jp.setcarteterrain(cp);
                std::cout<<"Taper pret, pour que le joueur suivant fasse son premier tour !"<<std::endl;
                std::string pret;
                std::cin>>pret;
                system("cls");
            }
            else
            {
                std::cout<<"Vous avez pioche : "<<std::endl;
                p.affichMain(*cp);
                std::cout<<"Que voulez vous faire : "<<std::endl;
                if(cp->gettype()=="creature")
                {
                    std::cout<<"1- Placer la carte sous le deck"<<std::endl;
                    std::cout<<"2- Remplacer la carte creature de votre terrain"<<std::endl;
                }
                if(cp->gettype()=="energie")
                {
                    std::cout<<"1- Placer la carte sous le deck"<<std::endl;
                    std::cout<<"2- Placer la carte sur votre terrain"<<std::endl;
                }
                if(cp->gettype()=="speciale")
                {
                    std::cout<<"1- Placer la carte sous le deck"<<std::endl;
                    std::cout<<"2- Utiliser votre carte speciale"<<std::endl;
                }
                int saisie;
                std::cin>>saisie;
                switch(saisie)
                {
                    case 1:
                    {
                        if(cp->gettype()=="creature")
                        {
                            std::queue<Carte*> qdeck1;
                            std::cout<<"coucoucrea"<<std::endl;
                            qdeck1=jp.getqdeck();
                            std::cout<<"coucoucrea"<<std::endl;
                            qdeck1.push(cp);
                            qdeck1.pop();
                            std::cout<<"coucoucrea"<<std::endl;
                            jp.setqdeck(qdeck1);
                            std::cout<<"coucoucrea1"<<std::endl;
                        }
                        if(cp->gettype()=="energie")
                        {
                            std::queue<Carte*> qdeck1;
                            std::cout<<"coucouene"<<std::endl;
                            qdeck1=jp.getqdeck();
                            std::cout<<"coucouene"<<std::endl;
                            qdeck1.push(cp);
                            qdeck1.pop();
                            std::cout<<"coucouene"<<std::endl;
                            jp.setqdeck(qdeck1);
                            std::cout<<"coucouene2"<<std::endl;
                        }
                        if(cp->gettype()=="speciale")
                        {
                            std::queue<Carte*> qdeck1;
                            qdeck1=jp.getqdeck();
                            qdeck1.push(cp);
                            qdeck1.pop();
                            jp.setqdeck(qdeck1);
                        }
                        break;
                    }

                    case 2:
                    {
                        if(cp->gettype()=="creature")
                        {
                            std::queue<Carte*> qdeck2;
                            qdeck2=jp.getqdeck();
                            qdeck2.push(jp.getcarteterrain());
                            qdeck2.pop();
                            jp.setqdeck(qdeck2);
                            jp.setcarteterrain(cp);
                        }
                        if(cp->gettype()=="energie")
                        {
                            std::vector<Carte*> energie;
                            energie = jp.getenergie();
                            energie.push_back(cp);
                            jp.setenergie(energie);
                            std::queue<Carte*> qdeck3;
                            qdeck3=jp.getqdeck();
                            qdeck3.pop();
                            jp.setqdeck(qdeck3);

                        }
                        if(cp->gettype()=="speciale")
                        {
                            if(cp->getnom()=="Carapace_bleu") /// Affiche votre carte enjeu
                            {
                                p.affichEnjeu(jp);
                                Sleep(3500);
                                std::queue<Carte*> qdeck2;
                                qdeck2=jp.getqdeck();
                                qdeck2.pop();
                                jp.setqdeck(qdeck2);

                            }
                            if(cp->getnom()=="Fleur") /// Detruit la premiere carte de votre adversaire
                            {
                                if(jp.getpseudo()==j1.getpseudo())
                                {
                                    j2.getqdeck().pop();
                                    std::queue<Carte*> qdeck2;
                                    qdeck2=jp.getqdeck();
                                    qdeck2.pop();
                                    jp.setqdeck(qdeck2);
                                }
                                if(jp.getpseudo()==j2.getpseudo())
                                {
                                    j1.getqdeck().pop();
                                    std::queue<Carte*> qdeck2;
                                    qdeck2=jp.getqdeck();
                                    qdeck2.pop();
                                    jp.setqdeck(qdeck2);
                                }
                            }
                            if(cp->getnom()=="Champignon") /// Ajoute 3 pv au joueur
                            {
                                jp.setpvJ(jp.getpvJ()+3);
                                std::queue<Carte*> qdeck2;
                                qdeck2=jp.getqdeck();
                                qdeck2.pop();
                                jp.setqdeck(qdeck2);
                            }
                            if(cp->getnom()=="Piece") /// Retire 2 pv a l adversaire
                            {
                                if(jp.getpseudo()==j1.getpseudo())
                                {
                                    j2.setpvJ(jp.getpvJ()-2);
                                    std::queue<Carte*> qdeck2;
                                    qdeck2=jp.getqdeck();
                                    qdeck2.pop();
                                    jp.setqdeck(qdeck2);
                                }
                                if(jp.getpseudo()==j2.getpseudo())
                                {
                                    j1.setpvJ(jp.getpvJ()-2);
                                    std::queue<Carte*> qdeck2;
                                    qdeck2=jp.getqdeck();
                                    qdeck2.pop();
                                    jp.setqdeck(qdeck2);
                                }
                            }
                            if(cp->getnom()=="Tunnel") /// Rajoute dans deck votre carte placee sur le plateau
                            {
                                Carte* c = new Carte();
                                std::queue<Carte*> d;
                                c=jp.getcarteterrain();
                                d=jp.getqdeck();
                                d.push(c);
                                jp.setqdeck(d);
                                std::queue<Carte*> qdeck2;
                                qdeck2=jp.getqdeck();
                                qdeck2.pop();
                                jp.setqdeck(qdeck2);
                            }
                            if(cp->getnom()=="Banane") /// Supprime les energies de l'adversaire
                            {
                                if(jp.getpseudo()==j1.getpseudo())
                                {
                                    std::vector<Carte*> ene1;
                                    j2.setenergie(ene1);
                                    std::queue<Carte*> qdeck2;
                                    qdeck2=jp.getqdeck();
                                    qdeck2.pop();
                                    jp.setqdeck(qdeck2);
                                }
                                if(jp.getpseudo()==j2.getpseudo())
                                {
                                    std::vector<Carte*> ene2;
                                    j1.setenergie(ene2);
                                    std::queue<Carte*> qdeck2;
                                    qdeck2=jp.getqdeck();
                                    qdeck2.pop();
                                    jp.setqdeck(qdeck2);
                                }
                            }
                            if(cp->getnom()=="Etoile") /// Assure la victoire du joueur
                            {
                                if(jp.getpseudo()==j1.getpseudo())
                                {
                                    j2.setpvJ(jp.getpvJ()-15);
                                    std::queue<Carte*> qdeck2;
                                    qdeck2=jp.getqdeck();
                                    qdeck2.pop();
                                    jp.setqdeck(qdeck2);
                                }
                                if(jp.getpseudo()==j2.getpseudo())
                                {
                                    j1.setpvJ(jp.getpvJ()-15);
                                    std::queue<Carte*> qdeck2;
                                    qdeck2=jp.getqdeck();
                                    qdeck2.pop();
                                    jp.setqdeck(qdeck2);
                                    }
                            }
                        }
                        break;
                    }
                }
            }
            if(jp.getpseudo() == j1.getpseudo()) ///set les joueurs avant de les afficher sur le terrain
            {
                j1=jp;
            }
            if(jp.getpseudo() == j2.getpseudo())
            {
                j2=jp;
            }
            system("cls");

            if(cpt>=2) ///Pas d'attaque ni de visualition du terrain avant le deuxieme tour du premier joueur
            {
                system("cls");
                p.Terrain(j1, j2);
                if(jp.getpseudo()==j1.getpseudo())
                {
                    p.attaque(jp,j2);
                    p.Terrain(jp, j2);
                    Sleep(3500);
                }
                else if (jp.getpseudo()==j2.getpseudo())
                {
                    p.attaque(jp,j1);
                    p.Terrain(jp, j1);
                    Sleep(3500);
                }
                system("cls");
            }

            cpt++; //augmente nombre tour
            if(jp.getpseudo() == j1.getpseudo()) //si le joueur principal etait le 1, c est au tour du 2
            {
                j1=jp;
                jp=j2;
            }
            else
            {
                j2=jp;
                jp=j1;
            }
        }
    }while(fin);
}

void Partie::attaque(Joueur &ja, Joueur &jd)
{
    int a=0;
    int he=0, be=0, bo=0, Sb=0;
    std::vector<Carte*> energie = ja.getenergie();
    Carte* carteAttaque = new Carte();
    carteAttaque = ja.getcarteterrain();
    std::string cartAttaque = carteAttaque->getcategorie();
    bool attaqueFort = false;
    bool attaqueFaible = false;

    //std::cout<<"TAILLE DE LENERGIE"<<energie.size()<<std::endl;
    Sleep(5000);
    system("cls");

    // Compter les energies disponibles
    for(int i = 0 ; i < energie.size() ; i++)
    {
        if(energie[i]->getcategorie() == "Hero")
           {
            he++;
            a++;
            if(cartAttaque == "Hero"){
                attaqueFaible = true;
            }
           }

        if(energie[i]->getcategorie() == "Bebe")
            {
            be++;
            if(cartAttaque == "Bebe"){
                attaqueFaible = true;


            }
        }
        if(energie[i]->getcategorie() == "Boss")
        {
            bo++;
            if(cartAttaque == "Boss")
            {
                attaqueFaible = true;

            }
        }
        if(energie[i]->getcategorie() == "Sbires")
        {


            Sb++;

            if(cartAttaque == "Sbires"){
                attaqueFaible = true;

            }
    }
    }

    int total = Sb + be + bo +he;
    if(attaqueFaible == true && total>=2)
    {
        attaqueFort = true;
                Sleep(2000);
    }


    if(attaqueFaible==true && attaqueFort==false)
    {
        menuattaque(1, ja, jd);

    }
    else if(attaqueFaible==true && attaqueFort==true)
    {
       menuattaque(2, ja, jd);
    }else
    {
        std::cout<<"Vous ne pouvez pas attaquer"<<std::endl;
    }

}

void Partie::menuattaque(int choix, Joueur &ja, Joueur &jd)
{

    int he=0, be=0, bo=0, Sb=0;

    int supp = 0;
    int suppa = 0;
    int degat_fort_a = ja.getcarteterrain()->getdeg_fort();
    std::vector<Carte*> energie = ja.getenergie();
    int degat_fort_d = jd.getcarteterrain()->getdeg_fort();
    int degat;
    std::cout<<"Vous pouvez attaquer"<<std::endl;
    std::cout<<"Voici vos attaques disponibles :"<<std::endl;
    std::cout<<"0 - Ne pas attaquer"<<std::endl;
    std::cout<<" 1 - Attaque faible"<<std::endl;
    if(choix==2){
    std::cout<<" 2 - Attaque forte"<<std::endl;
    }
    std::cout<<"Choissisez votre attaque"<<std::endl;
    std::cin>>choix;

    switch(choix){

        case 0:{
            std::cout<<"Pas d attaque"<<std::endl;
            break;}
        case 1:{
            std::cout<<"Attaque faible"<<std::endl;
            if(degat_fort_d == 0)
            {
                std::cout<<"attaque adversaire"<<std::endl;
                degat = jd.getpvJ() - degat_fort_a;
                jd.setpvJ(degat);
            }else
            {
                std::cout<<"attaque creature "<<jd.getcarteterrain()->getnom()<<std::endl;
                system("cls");
                degat =  jd.getcarteterrain()->getpv() - degat_fort_a;
                jd.getcarteterrain()->setpv(degat);
            }

            do{
            for(int i = 0 ; i < energie.size() ; i++)
            {

                if(energie[i]->getcategorie() == ja.getcarteterrain()->getcategorie())
                {
                    std::cout<<"Suppression energie"<<std::endl;
                    std::cout<<energie[i]->getdescription()<<std::endl;

                    Sleep(2000);


                    std::vector<Carte*> cimetiere1;
                    cimetiere1=ja.getcimetiere();
                    cimetiere1.push_back(energie[i]);
                    std::vector<Carte*> removeEnergie;
                    removeEnergie=ja.getenergie();


                    ja.setcimetiere(removeEnergie);

                    removeEnergie.erase(std::remove(removeEnergie.begin(), removeEnergie.end(), removeEnergie[i]), removeEnergie.end());
                    ja.setenergie(removeEnergie);


                    Sleep(1500);
                    supp = 1;
                }
            }
            }while(supp==0);

        break;}
        case 2:{
            std::cout<<"Attaque forte"<<std::endl;
            if(degat_fort_d == 0)
            {
                std::cout<<"attaque adversaire"<<std::endl;
                degat = jd.getpvJ() - degat_fort_a;
                jd.setpvJ(degat);
            }else
            {
                std::cout<<"attaque creature "<<jd.getcarteterrain()->getnom()<<std::endl;
                degat = jd.getcarteterrain()->getpv() - degat_fort_a;
                jd.getcarteterrain()->setpv(degat);
            }

            do{

            for(int i = 0 ; i < energie.size() ; i++)
            {
                if(energie[i]->getcategorie() == ja.getcarteterrain()->getcategorie())
                {
                    std::cout<<"Suppression energie"<<std::endl;
                    std::vector<Carte*> cimetiere2;
                    cimetiere2=ja.getcimetiere();
                    cimetiere2.push_back(energie[i]);
                    ja.setcimetiere(cimetiere2);

                    std::vector<Carte*> removeEnergie2;
                    removeEnergie2=ja.getenergie();
                    ja.setcimetiere(removeEnergie2);

                    removeEnergie2.erase(std::remove(removeEnergie2.begin(), removeEnergie2.end(), removeEnergie2[i]), removeEnergie2.end());
                    ja.setenergie(removeEnergie2);

                    supp++;
                }else
                {
                    std::cout<<"Suppression energie"<<std::endl;
                    std::vector<Carte*> cimetiere3;
                    cimetiere3=ja.getcimetiere();
                    cimetiere3.push_back(energie[i]);
                    ja.setcimetiere(cimetiere3);

                    std::vector<Carte*> removeEnergie3;
                    removeEnergie3=ja.getenergie();
                    ja.setcimetiere(removeEnergie3);

                    removeEnergie3.erase(std::remove(removeEnergie3.begin(), removeEnergie3.end(), removeEnergie3[i]), removeEnergie3.end());
                    ja.setenergie(removeEnergie3);

                    suppa++;
                }

            }
            }while(supp==0 && suppa ==0);

        break;}
    }
}

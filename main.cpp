#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <mmsystem.h>
#include "Carte_creature.h"
#include "Magasin.h"
#include "Joueur.h"
#include "partie.h"
#include "Affichage.h"

int main()
{
    Affichage a;

    for(int j=0;j<213;j++)
    {
        a.gotoligcol(9,j);
        std::cout<<"-";
        a.gotoligcol(32,j);
        std::cout<<"-";
        Sleep(10);

    }
    a.gotoligcol(10,70);
    std::cout<<"               ************"<<std::endl;
    a.gotoligcol(11,70);
    std::cout<<"               ####....#."<<std::endl;
    a.gotoligcol(12,70);
    std::cout<<"             #..###.....##...."<<std::endl;
    a.gotoligcol(13,70);
    std::cout<<"             ###.......######              ###            ###"<<std::endl;
    a.gotoligcol(14,70);
    std::cout<<"                ...........               #...#          #...#"<<std::endl;
    a.gotoligcol(15,70);
    std::cout<<"               ##*#######                 #.#.#          #.#.#"<<std::endl;
    a.gotoligcol(16,70);
    std::cout<<"            ####*******######             #.#.#          #.#.#"<<std::endl;
    a.gotoligcol(17,70);
    std::cout<<"           ...#***.****.*###....          #...#          #...#"<<std::endl;
    a.gotoligcol(18,70);
    std::cout<<"           ....**********##.....           ###            ###"<<std::endl;
    a.gotoligcol(19,70);
    std::cout<<"           ....****    *****...."<<std::endl;
    a.gotoligcol(20,70);
    std::cout<<"             ####        ####"<<std::endl;
    a.gotoligcol(21,70);
    std::cout<<"           ######        ######"<<std::endl;
    a.gotoligcol(22,70);
    std::cout<<"           ######        ######"<<std::endl;
    a.gotoligcol(23,70);
    std::cout<<"##########################################  ####################"<<std::endl;
    a.gotoligcol(24,70);
    std::cout<<"#...#......#.##...#......#.##...#......#.#  #------------------#"<<std::endl;
    a.gotoligcol(25,70);
    std::cout<<"##########################################  #------------------#"<<std::endl;
    a.gotoligcol(26,70);
    std::cout<<"#..#....#....##..#....#....##..#....#....#  ####################"<<std::endl;
    a.gotoligcol(27,70);
    std::cout<<"##########################################      #----------#"<<std::endl;
    a.gotoligcol(28,70);
    std::cout<<"#.....#......##.....#......##.....#......#      #----------#"<<std::endl;
    a.gotoligcol(29,70);
    std::cout<<"##########################################      #----------#"<<std::endl;
    a.gotoligcol(30,70);
    std::cout<<"#.#..#....#..##.#..#....#..##.#..#....#..#      #----------#"<<std::endl;
    a.gotoligcol(31,70);
    std::cout<<"##########################################      ############"<<std::endl;

    Sleep(2000);
    system("cls");
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

    ///Affichage Partie
    Partie p;
    PlaySound(TEXT("C:\\Users\\Hugo Fougeres\\Desktop\\bruant_klein\\ProjetC--main\\SuperMarioBros.wav") , NULL, SND_ASYNC | SND_FILENAME );
    p.debutPartie();
    return 0;
}

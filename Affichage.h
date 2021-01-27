#ifndef AFFICHAGE_H_INCLUDED
#define AFFICHAGE_H_INCLUDED
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <fstream>

class Affichage
{
    public:
    void Color(int couleurDuTexte, int couleurDeFond);
    void gotoligcol( int lig, int col );
};

#endif // AFFICHAGE_H_INCLUDED

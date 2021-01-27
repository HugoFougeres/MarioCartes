#ifndef CARTE_ENERGIE_H_INCLUDED
#define CARTE_ENERGIE_H_INCLUDED

#include "Carte.h"

class Carte_energie : public Carte
{
    private:

    public:

        /// Constructeurs / Destructeur
        Carte_energie();
        Carte_energie(std::string _description, int multi);
        ~Carte_energie();


        /// Getters / Setters
        int getmulti() const;

        void setmulti(int multi);

        /// Fonctions
        int multiply();
};

#endif // CARTE_ENERGIE_H_INCLUDED

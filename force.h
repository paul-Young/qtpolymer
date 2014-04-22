#ifndef FORCE_H
#define FORCE_H
#include "protein.h"

class Force
{
    double fx, fy, fz;
    double k_repel, k_bond;

public:
    Force();

    double addRepulsion(Protein *,Protein *);
    //double addRandom();
    double addBond(Protein *,Protein *);
    //void apply(Protein*);
};

#endif // FORCE_H

#ifndef GO_H
#define GO_H
#include "protein.h"
#include "force.h"

class GO
{
public:
    double E,E_repel,E_bond;
    Protein protein;
    Protein ref; // initial structure

    Force force;

    GO();
    void applyForce();
};

#endif // GO_H

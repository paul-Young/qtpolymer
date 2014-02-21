#include "go.h"

GO::GO()
{
    double E = 0.0;
    double E_repel = 0.0;
    double E_bond = 0.0;
}

void GO::applyForce(){

    // pile forces into the force object and record the energy contribution of each force component
    E_repel = force.addRepulsion(&protein, &ref);
    E_bond = force.addBond(&protein, &ref);

    E = E_repel + E_bond;
}

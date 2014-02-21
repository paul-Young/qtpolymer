#include "force.h"

Force::Force(){
    fx = 0.0; fy = 0.0; fz = 0.0;
    k_repel = 14.0;
    k_bond = 20.0;
}

double Force::addRepulsion(Protein *current, Protein *reference){
    double E_repel = 0.0;

    for (int i=1;i<=current->size-1;i++){
        for (int j=i+1;j<=current->size;j++){

            E_repel += k_repel * pow( reference->distance(i,j)/current->distance(i,j),6 );
            double F = 6*k_repel * pow( reference->distance(i,j),6 )/pow( current->distance(i,j), 7 );

            double dx,dy,dz;
            dx = current->chain[j].x-current->chain[i].x;
            dy = current->chain[j].y-current->chain[i].y;
            dz = current->chain[j].z-current->chain[i].z;

            fx += F * dx/current->distance(i,j);
            fy += F * dy/current->distance(i,j);
            fz += F * dz/current->distance(i,j);
        }
    }

    return E_repel;
}

double Force::addBond(Protein *current, Protein *reference){
    double E_bond = 0.0;
    for (int i=1;i<=current->size-1;i++){
        E_bond += 1/2.*k_bond* pow( current->distance(i,i+1)-reference->distance(i,i+1),2 );
        double F = -k_bond* (current->distance(i,i+1)-reference->distance(i,i+1));

        double dx,dy,dz;
        dx = current->chain[i+1].x-current->chain[i].x;
        dy = current->chain[i+1].y-current->chain[i].y;
        dz = current->chain[i+1].z-current->chain[i].z;

        fx += F * dx/current->distance(i,i+1);
        fy += F * dy/current->distance(i,i+1);
        fz += F * dz/current->distance(i,i+1);
    }
    return E_bond;
}

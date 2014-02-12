#include "sop.h"

SOP::SOP(){
    temp=   0.6;      /* temperature (in units of (eh/kB)); 0.6 kcal/mol = 300 K */
    h=      0.04;    /* integration step */
}

void SOP::rforce(int mseed){
    double var;
    var = sqrt(2.0 * temp/h);

    for(int i = 1 ; i <= protein->size ; i ++){
        protein->chain[i].fcx = var * gasdev(&mseed) * sqrt(protein->chain[i].zeta1);
        protein->chain[i].fcy = var * gasdev(&mseed) * sqrt(protein->chain[i].zeta1);
        protein->chain[i].fcz = var * gasdev(&mseed) * sqrt(protein->chain[i].zeta1);
    }
}

void SOP::iteration(){
    for(int i = 2 ; i <= protein->size ; i ++){
        protein->chain[i].x+=protein->chain[i].fcx*h/protein->chain[i].zeta1;
        protein->chain[i].y+=protein->chain[i].fcy*h/protein->chain[i].zeta1;
        protein->chain[i].z+=protein->chain[i].fcz*h/protein->chain[i].zeta1;
    }
}

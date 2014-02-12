#ifndef SOP_H
#define SOP_H
#include "protein.h"
#include "gaussian.h"
#include <math.h>

class SOP
{
public:
    Protein *protein;

    double temp,h;

    SOP();
    void force(),rforce(int),bond(),repel(),bend(),bend3(),end_tangent(),pull();
    void iteration();

};

#endif // SOP_H

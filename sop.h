#ifndef SOP_H
#define SOP_H
#include "protein.h"
#include "force.h"

class SOP
{
public:
    Protein *protein;
    Force force;

    SOP();
};

#endif // SOP_H

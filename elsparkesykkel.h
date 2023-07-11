#ifndef __ELSPARKESYKKEL_H
#define __ELSPARKESYKKEL_H

#include "gjenstand.h"


/**
 *  Elsparkesykkel (med watt).
 */

class Elsparkesykkel : public Gjenstand {

    private:
        int watt;

    public:
        // Elsparkesykkel(ifstream & inn);
        Elsparkesykkel() : Gjenstand() { lesData(); type = enumElsparkesykkel; }
        virtual void lesData();
        //virtual void skrivData() const;
        //virtual void skrivTilFil(ofstream & ut) const;
};


#endif


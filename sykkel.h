#ifndef __SYKKEL_H
#define __SYKKEL_H

#include "gjenstand.h"

/**
 *  Sykkel (med tilhenger/uten tilhenger).
 */

class Sykkel : public Gjenstand {

    private:
        bool tilhenger;

    public:
        // Sykkel(ifstream & inn);
        Sykkel() : Gjenstand() { lesData(); type = enumSykkel; }
        virtual void lesData();
        virtual void skrivData() const;
        //virtual void skrivTilFil(ofstream & ut) const;
};


#endif

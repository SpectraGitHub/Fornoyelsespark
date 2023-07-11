#ifndef __TRALLE_H
#define __TRALLE_H
#include "gjenstand.h"


/**
 *  Tralle (med drasele/ uten drasele)
 */

class Tralle : public Gjenstand {

    private:
        bool drasele;

    public:
        // Tralle(ifstream & inn);
        Tralle() : Gjenstand() { lesData(); type = enumTralle; }
        virtual void lesData();
        virtual void skrivData() const;
        //virtual void skrivTilFil(ofstream & ut) const;
};


#endif

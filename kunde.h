#ifndef __KUNDE_H
#define __KUNDE_H

#include <string>
#include <vector>
#include "gjenstand.h"
#include "sted.h"

/**
 *  Kunde (med id, mobnr).
 */

class Kunde {
    private:
        int id;       //kundens unike nummer (sortert på dette)
        int mobnr;
        std::string navn;
        //usortert vector med nåværende leide gjenstander
        std::vector <Gjenstand*> gGjenstander;

    public:
        Kunde(){ }
        ~Kunde();
        int kundeID() { return id; }
        void alleKunder() const;
        void enKunde() const;
        void stedHent(std::vector <Tralle*> gTraller);
        void stedLever();
        void lesData(int sisteNr);
};



#endif

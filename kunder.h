#ifndef __KUNDER_H
#define __KUNDER_H

#include <list>
#include "kunde.h"
#include "sted.h"

/**
 *  Kunder (sisteNr og liste med kunder).
 */

class Kunder {

    private:
        int sisteNr; //fortlpende kende automatisk nummerering av alle nye kunder
        std::list <Kunde*> gKunder; //sortert liste med de unikt nummererte kundene
    public:
        //Kunder(ifstream & inn);
        //~Kunder();
        Kunder() { sisteNr = 0; }
        //int hentID() { return sisteNr; }
        void nyKunde();
        void hentGjenstand(std::vector <Tralle*> gTraller);
        void skrivAlleKunder();
        void skrivEnKunde();
        void slettKunde();
        void skrivData();
        //virtual void skrivTilFil(ofstream & ut) const;

};


#endif

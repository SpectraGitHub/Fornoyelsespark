#ifndef __UTLEIESTEDER_H
#define __UTLEIESTEDER_H

#include <string>
#include <map>
#include "sted.h"

/**
 *  Utleie (med sisteNr og mappen gSteder).
 */

class Utleie {
    private:
        int sisteNr;
        std::map <std::string, Sted*> gSteder;
    public:
        void nyttSted();
        void nyGjenstand();
        void skrivAlleSteder();
        void skrivEtSted();
        void skrivInntekter();
        void skrivHarIgjen();
        void hentGjenstand();
        void overforGjenstand();
        void finnGjenstand(int id);
        void slettGjenstand();
        void slettSted();
        void lesData();
        void skrivData() const;
};

#endif

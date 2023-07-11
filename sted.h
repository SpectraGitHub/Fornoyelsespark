#ifndef __STED_H
#define __STED_H

#include <string>
#include <vector>
#include "tralle.h"
#include "sykkel.h"
#include "elsparkesykkel.h"

/**
 *  Sted (med id, beskrivelse, tlfnr, inntekter 
 *  og de 3 vectorene gTraller, gSykler og gElsparkesykler.
 */

class Sted {
    private:
        std::string id;
        std::string beskrivelse;
        int tlfnr;
        int inntekter;
        std::vector <Tralle*> gTraller;
        std::vector <Sykkel*> gSykler;
        std::vector <Elsparkesykkel*> gElsparkesykler;
    public:
        Sted(std::string stedID)
        {
            lesData(stedID); inntekter = 0; gTraller.clear();
            gSykler.clear(); gElsparkesykler.clear();
        }
        ~Sted();
        void stedGjenstand();
        void stedInntekter();
        void stedHarIgjen();
        void stedHent();
        void stedLever();
        void stedOverfor();
        void stedFinn(int finnID);
        void lesData(std::string stedID);
        void skrivData() const;
};


#endif

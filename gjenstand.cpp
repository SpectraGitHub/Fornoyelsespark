#include <iostream>
#include "gjenstand.h"
#include "LesData3.h"
using namespace std;

int sisteNr = 0;

/**
*   lager id til gjenstanden
*   @param sisteNr - siste nummeret 
*
*/
void Gjenstand::lagID(){
    ++sisteNr;
}

/**
*   leser gjenstandens data
*   @param sisteNr - siste nummeret/id 
*
*/
void Gjenstand::lesData() {
    Gjenstand::lagID();
    id = sisteNr;
}

/**
*   skriver ut dataen til gjenstand og du kan velge hvilken type
*   @param type - type gjenstand
*   @param enumSykkel - sykkelens enum
*   @param enumTralle - trallens enum
*   @param enumElsparkesykkel - elsparkesykkelens enum
*
*/
void Gjenstand::skrivData() const {
    cout << "Gjenstandsnummer: " << id << "\n";
    cout << "Type: ";

    switch(type) {
        case enumSykkel:         cout << "Sykkel";              break;
        case enumTralle:         cout << "Tralle";              break;
        case enumElsparkesykkel: cout << "Elsparkesykkel";      break;
    }
}

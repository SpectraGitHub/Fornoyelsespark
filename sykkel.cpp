#include <iostream>
#include "LesData3.h"
#include "sykkel.h"
using namespace std;

/**
*   Leser inn info om tralle
*   @see Gjenstand::lesData();
*   @param tilhenger - om tilhenger eller ikke
*
*/
void Sykkel::lesData() {
    Gjenstand::lesData();
}


/**
*   Skriver om sykkelen har tilhenger eller ikke
*   @see Gjenstand::lesData();
*   @param tilhenger - om tilhenger eller ikke
*
*/
void Sykkel::skrivData() const {
    cout << "Sykkelen har " << ((!tilhenger) ? "ikke ": "")
         << "en tilhenger.\n\n";
}

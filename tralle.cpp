#include <iostream>
#include "LesData3.h"
#include "tralle.h"
using namespace std;

/**
*   leser inn info om tralle
*   @see Gjenstand::lesData();
*   @param drasele - om drasele eller ikke
*
*/
void Tralle::lesData() {
    Gjenstand::lesData();
}

/**
*   skriver om trallen har drasele eller ikke
*   @see Gjenstand::lesData();
*   @param drasele - om drasele eller ikke
*
*/
void Tralle::skrivData() const{
    cout << "Trallen har " << ((!drasele) ? "ikke ": "")
         << "med en drasele.\n\n";
}




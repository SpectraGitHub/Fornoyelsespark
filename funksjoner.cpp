/**
*
*
*
*
*/


#include <iostream>
#include <string>
#include "funksjoner.h"

using namespace std;


/**
*   Skriver menyen.
*
*/

void skrivMeny()  {
 cout << "\nFlgende kommandoer er tilgjengelige (et tegn om gangen):\n"
         << "\tK N\n"
         << "\tK A\n"
         << "\tK 1 <knr>\n"
         << "\tK H <knr>\n"
         << "\tK L <knr>\n"
         << "\tK S <knr>\n"
         << "\tS N\n"
         << "\tS A\n"
         << "\tS 1 <stedID>\n"
         << "\tS T\n"
         << "\tS I\n"
         << "\tS O\n"
         << "\tS S <stedID>\n"
         << "\tG N\n"
         << "\tG F <gjenstander>\n"
         << "\tG S <gjenstander>\n"
         << "\tQ - Quit / avslutt\n\n";
}

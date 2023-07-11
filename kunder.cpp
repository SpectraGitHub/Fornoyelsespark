#include <iostream>
#include <iterator>
#include <algorithm>
#include "kunder.h"
#include "LesData3.h"
using namespace std;



/**
 *  Skriver automatisk nytt nr til kunde.
 *
 */

void Kunder::skrivData()  {
    cout << "\n\tNy kunde har nr." << ++sisteNr << ":\n";
}



/**
 *  Lager en ny Kunde og pusher den inn i listen gKunder
 *
 *  @param   sisteNr  - fortlpende okende automatisk nummerering av alle nye kunder
 *  @param   gKunder  - sortert liste med de unikt nummererte kundene
 *  @see     Kunder::Kunder()
 *  @see     Kunder::skrivData()
 *  @see     Kunder::lesData(...)
 */
void Kunder::nyKunde() {
    Kunder::skrivData();   //Får en unik ID
    Kunde* nyKunde = new Kunde;  //lager ny kunde

    nyKunde->lesData(sisteNr); //leser kundens datamedlemmer
    gKunder.push_back(nyKunde); // legger inn den nye kunden
    gKunder.sort(); //sorterer kunden
}


/**
 *  Går gjennom hele lista og skriver ut alle kundene.
 *
 *  @param   gKunder  - sortert liste med de unikt nummererte kundene
 *  @see     Kunder::Kunder()
 *  @see     Kunde::alleKunder()
 */

void Kunder::skrivAlleKunder() {
    if(gKunder.size() < 1){           //Sjekker om noen kunder finnes.
        cout << "\n\t--Ingen kunder finnes--\n\n";
    }
    else {                              //Skriver ut hvis kunder finnes.
        cout << "\n\t--All data om kundene--\n\n";
        for (const auto & val : gKunder){   //Går gjennom alle kunder
            val->alleKunder();            //Skriver ut data om kundene.
        }
    }
}


/**
 *  Finner fram til en kunde basert på id og skriver ut all info om den kunden.
 *
 *  @param   sisteNr  - fortlpende okende automatisk nummerering av alle nye kunder
 *  @param   gKunder  - sortert liste med de unikt nummererte kundene
 *  @see     Kunder::Kunder()
 *  @see     Kunde::enKunde()
 */
void Kunder::skrivEnKunde() {
    int id;

    if(gKunder.size() < 1){           //Sjekker om noen kunder finnes.
        cout << "\n\t--Ingen kunder finnes--\n\n";
    } else {                          //Skriver ut hvis kunder finnes.
        id = lesInt("\tKundens ID: ", 1,sisteNr);
        auto it = gKunder.begin();    //Finner fram til IDen som ble innskrevet
        advance(it,--id);             //Velger kunden som har denne IDen
        (*it)->enKunde();             //Skriver ut data om den kunden
    }
}


/**
 *  Henter gjenstand og skriver ut
 *
 *  @param   sisteNr  - fortlpende okende automatisk nummerering av alle nye kunder
 *  @param   gKunder  - sortert liste med de unikt nummererte kundene
 *  @see     Kunder::Kunder()
 *  @see     Kunde::stedHent()
 */

void Kunder::hentGjenstand(vector <Tralle*> gTraller) {
    int id;

    if(gKunder.size() < 1){           //Sjekker om noen kunder finnes.
        cout << "\n\t--Ingen kunder finnes--\n\n";
    } else {
        id = lesInt("\tKundens ID: ", 1,sisteNr);
        auto it = gKunder.begin();    //Finner fram til IDen som ble innskrevet
        advance(it,--id);             //Skriver ut data om den kunden
        (*it)->stedHent(gTraller);
    }
}



/**
 *  Sletter kunde
 *
 *  @param   sisteNr  - fortlpende okende automatisk nummerering av alle nye kunder
 *  @param   gKunder  - sortert liste med de unikt nummererte kundene
 *  @see     Kunder::Kunder()
 */



void Kunder::slettKunde() {
    Kunder* kunder = nullptr; // //  Peker til kunde.
    int id;
    if(gKunder.size() < 1) { // hvis det ikke er kunder
        cout << "\n\tIngen kunder registrert!\n";
    }
    else {
    // spør om du er sikker på at du vil endre
    if (lesChar("Sikker på at du ønsker å endre? (j/N)") == 'J'){
    // nr du ønsker å slette
        id = lesInt("\tNr du ønsker å slette", 1, sisteNr); //  Ønsket nr. å flytte.
        //går gjennom for å finne ønsket nr å slette
        auto it = find_if(gKunder.begin(), gKunder.end(),
                [id] (const auto & val) { return(val->kundeID()); });
         if (it != gKunder.end()) {          //  Funn: sletter kunden
                  gKunder.erase(it);
                  delete kunder;
         }
        }
    }

}




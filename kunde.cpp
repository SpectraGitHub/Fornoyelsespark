#include <iostream>
#include "kunde.h"
#include "LesData3.h"
#include "utleiesteder.h"
using namespace std;

extern Utleie s; //Lar hente funksjoner fra klassen Utleiesteder


/**
 *  Lager en ny Kunde og pusher den inn i listen gKunder
 *
 *  @param   sisteNr  - fortlpende okende automatisk nummerering av alle nye kunder
 *  @see     Kunde::Kunde()
 */


void Kunde::lesData(int sisteNr) {
    id = sisteNr;   //skriver automatisk siste nr
    cout << "Navn: "; getline(cin, navn);  //leser inn navn
    mobnr = lesInt("Mobilnummer", 10000000,99999999); //leser inn mobNr

}

/**
 *  Skriver ut alle kunder
 *
 *  @param   id    - kundens unike id
 *  @param   mobnr - kundens mobilnummer
 *  @param   navn  - kundens navn
 *  @param   pGjenstander - usortert vector med nåværende leide gjenstander
 *  @see     Kunde::Kunde()
 */


void Kunde::alleKunder() const {
    cout << "Kundens ID: " << id << " | ";
    cout << "Navn: " << navn << " | ";
    cout << "Mobilnummer: " << mobnr << " | ";
    cout << "Antall gjenstander lnt: " << (gGjenstander.size()) << "\n";
}

/**
 *  Skriver ut info om kun en kunde
 *
 *  @param   id    - kundens unike id
 *  @param   mobnr - kundens mobilnummer
 *  @param   navn  - kundens navn
 *  @param   pGjenstander - usortert vector med nåværende leide gjenstander
 *  @see     Kunde::Kunde()
 */

void Kunde::enKunde() const {
    cout << "\n\t--Om kunden med ID " << id << "--\n\n";
    cout << "Navn: " << navn << " | ";
    cout << "Mobilnummer: " << mobnr << " | ";
    cout << "Antall gjenstander lnt: " << (gGjenstander.size()) << "\n";


    if(gGjenstander.size() < 1) {
        //skriver ut alt om gjenstander som er laant av kunden
    }
}

/**
 *  Starter hent gjenstand i utleie
 *
 *  @see     Utleie::hentGjenstand
 */

void Kunde::stedHent(vector <Tralle*> gTraller) {
    //Gjenstand* gGjenstander;
    gGjenstander.insert(gGjenstander.begin(), gTraller.begin(),gTraller.end());
    //gGjenstander.push_back(gSykler.front());
}

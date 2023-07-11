#include <iostream>
#include <string>
#include <algorithm>
#include "LesData3.h"
#include "sted.h"
#include "kunder.h"
#include "const.h"
using namespace std;

extern Kunder k; //Lar hente funksjoner fra klassen Kunder

/**
*   Leser inn relevant data for sted
*   @param id - stedets id
*   @param beskrivelse - liten beskrivelse om stedet
*   @param tlfnr - telefonnummeret til stedet
*   @see   Utleie::nyttSted()
*
*/

void Sted::lesData(string stedID) {
    id = stedID;    // Henter stedID som blir lest inn i Utleie::nyttSted();
    cout << "Beskrivelse: "; getline(cin, beskrivelse);
    tlfnr = lesInt("Telefonnummer: ", 10000000,99999999);
}

/**
*   Skriver ut relevant data for sted(inkludert gjenstander)
*   @param stedID - stedets id
*   @param beskrivelse -  liten beskrivelse om stedet
*   @param tlfnr - telefonnummeret til stedet
*   @param gSykler - antall sykler
*   @param gTraller - antall traller
*   @param gElsparkesykler - antall elsparkesykler
*   @see   Utleie::nyttSted()
*
*/

void Sted::skrivData() const {
    // IDen skrives ut som val.first
    cout << "Beskrivelse: " << beskrivelse << " | ";
    cout << "Telefonnummer: " << tlfnr << " | ";
    cout << "Sykler: " << (gSykler.size()) << " | ";
    cout << "Traller: " << (gTraller.size()) << " | ";
    cout << "Elsparkesykler: " << (gElsparkesykler.size()) << "\n\n";
}

/**
*   Skriver stedets inntekter
*   @param inntekter - stedets inntekter
*   @see   Utleie::skrivInntekter()
*
*/

void Sted::stedInntekter() {
    cout << "Stedets inntekter: " << inntekter << " kr.\n";
}

/**
*   Skriver ut hvor mange gjenstander stedet har igjen
*   @param gSykler - stedets sykler
*   @param gTraller - stedets traller
*   @param gElsparkesykler - stedets elsparkesykler
*   @see   Utleie::skrivInntekter()
*
*/
void Sted::stedHarIgjen() {
    cout << "Sykler: "<< (gSykler.size()) << ", ";
    cout << "Traller: "<< (gTraller.size()) << ", ";
    cout << "Elsparkesykler: " << (gElsparkesykler.size()) << "\n";
}

/**
*   Overfører gjenstander
*   @param gSykler - stedets sykler
*   @param gTraller - stedets traller
*   @param gElsparkesykler - stedets elsparkesykler
*   @see   Utleie::overforGjenstand()
*
*/
void Sted::stedOverfor() {
    Gjenstand * gTraller = nullptr;
    Gjenstand * gSykler = nullptr;
    Gjenstand * gElsparkesykler = nullptr;


}

/**
*   Overfører gjenstander
*   @param gSykler - stedets sykler
*   @param gTraller - stedets traller
*   @param gElsparkesykler - stedets elsparkesykler
*   @see   Gjenstand::Gjentand()
*   @see   Utleie::hentGjenstand()
*
*/

void Sted::stedHent() {
    char type;

    do {
        type = lesChar("[S]ykkel / [E]lsparkesykkel / [T]ralle");
    } while (type != 'S' && type != 'E'
            && type != 'T' );

    switch (type) {
//////////////////////////////////////////////////////////////////////////////
        case 'S': {
                  int antall = (gSykler.size());
                  if(gSykler.size() < 1) {
                    cout << "Det finnes ingen sykler som kan hentes.";
                  }
                  else {
                    int ant = lesInt("\tHvor mange sykler?: ", 1,antall);
                    for (int i = 0; i < ant; i++) {
                        auto it = gSykler.back();
                        inntekter += prisSykkel;
                        //it->(k.hentGjenstand());
                    }
                  }
                  break;
                  }
//////////////////////////////////////////////////////////////////////////////
        case 'E': {
                  int antall = (gElsparkesykler.size());
                  if(gElsparkesykler.size() < 1) {
                    cout << "Det finnes ingen elsparkesykler som kan hentes.";
                  }
                  else {
                    int ant = lesInt("\tHvor mange elsparkesykler?: ", 1,antall);
                    for (int i = 0; i < ant; i++) {
                        auto it = gElsparkesykler.back();
                        inntekter += prisWatt1;
                        //it->(k.hentGjenstand());
                    }
                  }
                  break;
                  }
//////////////////////////////////////////////////////////////////////////////
        case 'T': {
                  int antall = (gTraller.size());
                  if(gTraller.size() < 1) {
                    cout << "\nDet finnes ingen traller som kan hentes.";
                  }
                  else {
                    int ant =lesInt("\tHvor mange traller?: ", 1,antall);
                    for (int i = 0; i < ant; i++) {
                        auto it = gTraller.back();
                        inntekter += prisTralle;
                        k.hentGjenstand(gTraller);
                        gTraller.pop_back();
                    }
                  }
                  break;
                  }
//////////////////////////////////////////////////////////////////////////////
    }
}


void Sted::stedFinn(int finnID) {
    /*
    Gjenstand *id;
    cout << finnID;
    auto it1 = find(gSykler.begin(), gSykler.end(), id);
    auto it2 = find(gTraller.begin(), gTraller.end(), id);
    auto it3 = find(gElsparkesykler.begin(), gElsparkesykler.end(), id);

    cout << id;
    if (it1 !=gSykler.end()) {
        cout << "test 1\n";
    }
    if (it2 !=gTraller.end()) {
        cout << "test 2\n";
    }
    if (it3 !=gElsparkesykler.end()) {
        cout << "test 3\n";
    }
    */
    auto it = find_if(gSykler.begin(), gSykler.end(),
            [finnID] (const auto & val) { return(val->hentID() == finnID); } );
    if (it != gSykler.end()) {      //  Funn i GRNN lype (<map>):
                          //  Setter om hvor funnet.
        cout << id;       //  Returnerer peker til 'Kjorer'.
    }

}

/**
*   Flytter gjenstander (velge hvilken type)
*   @param gSykler - stedets sykler
*   @param gTraller - stedets traller
*   @param gElsparkesykler - stedets elsparkesykler
*   @see   Utleiesteder::nyGjenstand()
*
*/
void Sted::stedGjenstand() {
    char type;
    int antall = lesInt("\Hvor mange gjenstander?: ", 1,20);

    do {
        type = lesChar("[S]ykkel / [E]lsparkesykkel / [T]ralle");
    } while (type != 'S' && type != 'E'
            && type != 'T' );

    switch (type) {
        case 'S': {
                  for (int i = 0; i < antall; i++) {
                      Sykkel* nyGjenstand;
                      new Sykkel();
                      gSykler.push_back(nyGjenstand);
                  } break;
                  }
        case 'E': {
                  for (int i = 0; i < antall; i++) {
                      Elsparkesykkel* nyGjenstand;
                      new Elsparkesykkel();
                      gElsparkesykler.push_back(nyGjenstand);
                  } break;
                  }
        case 'T': {
                  for (int i = 0; i < antall; i++) {
                      Tralle* nyGjenstand;
                      new Tralle();
                      gTraller.push_back(nyGjenstand);
                  } break;
                  }
    }
}

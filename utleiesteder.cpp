#include <iostream>
#include "utleiesteder.h"
#include "LesData3.h"
using namespace std;


/**
*   Skriver ut siste nummeret
*   @param sisteNr - siste nummeret
*   @see   Utleie::Utleie()
*
*/
void Utleie::skrivData() const {
    cout << "Siste nr: " << sisteNr << "\n";
}

/**
*   Lager nytt sted som legges inni mappen
*
*   @param gSteder - mappen med steder
*   @see   Utleie::Utleie()
*   @see   Sted::Sted()
*
*/

void Utleie::nyttSted() {
    Sted* nyttSted = nullptr;     // Peker til et Sted inni et container.
    string stedID;                // Stedets ID.

    cout << "Stedets ID: "; getline(cin, stedID);
    if (gSteder.count(stedID) < 1) {        //Sjekker om samme ID finnes.
        nyttSted = new Sted(stedID);        //Lar brukeren skrive inn verdier.
        gSteder.insert({stedID,nyttSted});  //Legger inni map
    } else {
        cout << "Stedet med samme ID finnes allerede.\n\n";
    }
}

/**
*   Skriver alle stedene med info
*
*   @param gSteder - mappen med steder
*   @see   Utleie::Utleie()
*   @see   Sted::skrivData()
*
*/
void Utleie::skrivAlleSteder() {
    if(gSteder.size() < 1){           //Sjekker om noen steder finnes.
        cout << "\n\t--Ingen steder finnes--\n\n";
    }
    else {                              //Skriver ut hvis steder finnes.
        cout << "\n\t--All data om stedene--\n\n";
        for (const auto & val : gSteder) {
             cout << "Stedets ID: " << val.first << " | "; //Skriver ut id.
             (val.second)->skrivData();          //Skriver ut resten av data.
        }
    }
}

/**
*   Skriver ut et valgt sted basert på id
*
*   @param gSteder - mappen med steder
*   @see   Utleie::Utleie()
*   @see   Sted::skrivData()
*
*/
void Utleie::skrivEtSted() {
    string stedID;

    if(gSteder.size() < 1){           //Sjekker om noen steder finnes.
        cout << "\n\t--Ingen utleiesteder finnes--\n\n";
    }
    else {                            //Stedet finnes
        cout << "Velg sted-ID: "; getline(cin, stedID);

        auto it = gSteder.find(stedID);     //Leter etter stedet vha. ID
        for ( ; it != gSteder.end(); it++) {
            cout << "\n\t--Informasjon om stedet " << it->first << "--\n\n";
            //Skriver ut informasjonen om stedet
            (it->second)->skrivData();
        }
    }
//    if (!it) { cout << "Stedet finnes ikke."; }
}

/**
*   Skriver inntektene til stedet
*
*   @param gSteder - mappen med steder
*   @see   Utleie::Utleie()
*   @see   Sted::stedInntekter()
*
*/

void Utleie::skrivInntekter() {
    if(gSteder.size() < 1){           //Sjekker om noen steder finnes.
        cout << "\n\t--Ingen utleiesteder finnes--\n\n";
    }
    else {
        cout << "\n\t--Utleiestedenes inntekter--\n\n";
        for (const auto & val : gSteder) {
            cout << "Stedets ID: " << val.first << " | "; //Skriver ut id.
            (val.second)->stedInntekter();          //Skriver ut resten av data.
        }
    }
}


/**
*   Skriver ut hvor mange gjenstander som stedet har igjen
*
*   @param gSteder - mappen med steder
*   @see   Utleie::Utleie()
*   @see   Sted::stedHarIgjen()
*
*/
void Utleie::skrivHarIgjen() {
    if(gSteder.size() < 1){           //Sjekker om noen steder finnes.
        cout << "\n\t--Ingen utleiesteder finnes--\n\n";
    }
    else {
        cout << "\n\n\t--Gjenstander som ligger hos uteiestedene--\n\n";
        for (const auto & val : gSteder) {
            cout << val.first << " | ";       //Skriver ut id.
            (val.second)->stedHarIgjen();     //Skriver ut gjenstandene.
        }
    }
}

/**
*   Henter en gjenstand fra stedet
*
*   @param gSteder - mappen med steder
*   @see   Utleie::Utleie()
*   @see   Sted::stedHent()
*
*/

void Utleie::hentGjenstand() {
    if(gSteder.size() < 1){           //Sjekker om noen steder finnes.
        cout << "\n\t--Ingen utleiesteder finnes--\n\n";
    }
    else {
        string stedID;
        cout << "Velg sted-ID å hente fra: "; getline(cin, stedID);

        auto it = gSteder.find(stedID);     //Leter etter stedet vha. ID
        for ( ; it != gSteder.end(); it++) {
            cout << "\n\t--Hent fra stedet " << it->first << "--\n\n";
            //Skriver ut informasjonen om stedet
            (it->second)->stedHent();
        }
    }
}

/**
*   Overforer gjenstand
*
*   @param gSteder - mappen med steder
*   @see   Utleie::Utleie()
*   @see   Sted::stedOverfor()
*
*/

void Utleie::overforGjenstand() {
    if(gSteder.size() < 2){           //Sjekker om noen steder finnes.
        cout << "\n\t--Det finnes ikke nok steder å overføre mellom--\n\n";
    }
    else {
        Gjenstand* overfGjen;
        string stedID;
        string stedID2;

        cout << "Velg sted-ID å overføre fra: "; getline(cin, stedID);
        cout << "Velg sted-ID å overføre til: "; getline(cin, stedID2);
        //auto it = gSteder.find(stedID);     //Finner IDen
        //auto it2 = gSteder.find(stedID2);
        //(it->second)->stedOverfor();

        gSteder[stedID]->stedOverfor();
    }
}

/**
*   Lager ny gjenstand
*
*   @param gSteder - mappen med steder
*   @see   Utleie::Utleie()
*   @see   Sted::stedGjenstand()
*
*/

void Utleie::nyGjenstand() {
    if(gSteder.size() < 1){           //Sjekker om noen steder finnes.
        cout << "\n\t--Ingen utleiesteder finnes--\n\n";
    }
    else {
        string stedID;

        cout << "Velg sted-ID: "; getline(cin, stedID);

        auto it = gSteder.find(stedID);     //Finner IDen
        (it->second)->stedGjenstand();      //Lager gjenstand for denne IDen
        cout << "\n\t--Gjenstand(er) lagt til.--\n\n";
    }
}

void Utleie::finnGjenstand(int finnID) {
    if(gSteder.size() < 1){           //Sjekker om noen steder finnes.
        cout << "\n\t--Ingen steder finnes--\n\n";
    }
    else {                              //Skriver ut hvis steder finnes.
        for (const auto & val : gSteder) {
             (val.second)->stedFinn(finnID);       //Leter etter gjenstanden
        }
    }
}

/**
*   Sletter ett sted
*
*   @param gSteder - mappen med steder
*   @see   Utleie::Utleie()
*
*/
void Utleie::slettSted() {
    if(gSteder.size() < 1) {
        cout << "\n\tIngen steder registrert!\n";
    }
    else {
        string stedID;
        if (lesChar("Sikker på at du ønsker å slette? (j/N)") == 'J'){
            cout << "Velg sted-ID: "; getline(cin, stedID); //  Ønsket nr. å flytte.
            auto it = gSteder.find(stedID);
            if (it != gSteder.end()) {      //  Funn: sletter
                  gSteder.erase(it);
            }
        }
    }
}

/**
*   Sletter gjenstand
*
*
*
*/

void Utleie::slettGjenstand() {

}

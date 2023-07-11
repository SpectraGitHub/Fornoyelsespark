#include <iostream>
#include "kunder.h"
#include "utleiesteder.h"
#include "funksjoner.h"
#include "LesData3.h"
using namespace std;

Kunder k;             //Lar hente funksjoner fra klassen Kunder
Utleie s;             //Lar hente funksjoner fra klassen Utleiesteder



int main()  {
  char  valg,
       kValg,
       sValg,
       gValg;

  //k.lesFraFil();
  //s.lesFraFil();

  skrivMeny();
  valg = lesChar("\n Kommando");

  while (valg != 'Q')  {
    switch(valg)  {
    case 'K' : do {
          kValg = lesChar("\n K Kommando");
      } while (kValg != 'N' && kValg != 'A' && kValg != '1'
               && kValg != 'H' && kValg != 'L' && kValg != 'S');
                switch(kValg) {
                     case 'N': k.nyKunde();                     break;
                     case 'A': k.skrivAlleKunder();             break;
                     case '1': k.skrivEnKunde();                break;
                     case 'H': s.hentGjenstand();               break;
                     //case 'L': k.leverGjenstand();              break;
                     case 'S': k.slettKunde();                  break;
                 }
                break;
      case 'S': do {
              sValg = lesChar("\n S Kommando");
          } while (sValg != 'N' && sValg != 'A' && sValg != '1'
               && sValg != 'T' && sValg != 'I' && sValg != 'O'
               && sValg != 'S');
                switch(sValg) {
                     case 'N': s.nyttSted();                    break;
                     case 'A': s.skrivAlleSteder();             break;
                     case '1': s.skrivEtSted();                 break;
                     case 'T': s.skrivInntekter();              break;
                     case 'I': s.skrivHarIgjen();               break;
                     case 'O': s.overforGjenstand();            break;
                     case 'S': s.slettSted();                   break;
                 }
                break;
      case 'G': do {
          gValg = lesChar("\n G Kommando");
      } while (gValg != 'N' && gValg != 'F' && gValg != 'S');
                switch(gValg) {
                     case 'N': s.nyGjenstand();                 break;
                     case 'F': int finnID;
                               finnID = lesInt("\tGjenstandnummer: ", 1,999999);
                               s.finnGjenstand(finnID);               break;
                     case 'S': s.slettGjenstand();              break;
                 }
                 break;

      default:   skrivMeny();                break;
    }
    valg = lesChar("\n Kommando");
  }

  //k.skrivTilFil();
  //s.skrivTilFil();

  cout << "\n\n";
  return 0;
}

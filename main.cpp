#include <iostream>
#include "tili.h"
#include <string>

using namespace std;

// C++ ei dynaamisesti muuta taulukon kokoa ajon aikana
// Demon tilien määrä max 10

#define MAX_TILEJA 10

#define EI_LOYTYNYT (-1)

bool valmis = true;

int lisaaTiliListaan(Tili tiliLista[], Tili tiliOlio, int size){

    // Verratavan str alustus
    std::string empty = "";

    // Taulukon läpikäynti
    for (int i = 0; i <= size ; i++ ) {

        if (i == size) {
            cout << "Tila on taynna, poista tileja" << endl;
            cout << endl;
            return size;
        } else if (tiliLista[i].getOmistaja().compare(empty) == 0) {
            tiliLista[i] = tiliOlio;
            cout << "Lisatty!" << endl;
            cout << endl;
            return i;
        }
    }
    return 0;
}

void luoTili(Tili tiliLista[], int size){

    double summa;

    string tyyppi;
    string omistaja;

    cout << endl;
    cout << "Tilin luonti" << endl;

    // Käyttäjäsyötteen käsittely

    do {
        cout << endl;
        cout << "Nimi: " << endl;
        getline(cin, omistaja);

        if(omistaja.compare("") != 0 || !omistaja.empty()){
            break;
        }

    } while (valmis);


    do {
        cout << endl;
        cout << "Tilin tyyppi (Saasto, Kaytto tai Sijoitus). Kirjoita valinta tarkasti isolla alkukirjaimella." << endl;
        getline(cin, tyyppi);

        if (tyyppi.compare("Saasto") == 0 || tyyppi.compare("Kaytto") == 0 || tyyppi.compare("Sijoitus") == 0) {
            break;
        }

        cout << "Vaara syote, yrita uudestaan" << endl;

    } while (valmis);


    cout << "Lisaa alkupaaoma: ";
    cin >> summa;
    cout << endl;

    Tili uusiTili = Tili(summa, tyyppi, omistaja);

    int paalistaIndeksi;

    paalistaIndeksi = lisaaTiliListaan(tiliLista, uusiTili, size); // Lisätään käyttäjän luoma tili päätili taulukkoon


    if (paalistaIndeksi < size){

        cout << endl;
        cout << "Tili lisatty onnistuneesti, kiitos asiakkuudestasi! " << endl;
        cout << endl;
        cout << "Omistaja: " << tiliLista[paalistaIndeksi].getOmistaja() << endl;
        cout << endl;
        cout << "Tyyppi: " << tiliLista[paalistaIndeksi].getTyyppi() << endl;
        cout << endl;
        cout << "Varat: " << tiliLista[paalistaIndeksi].getSumma() << "$" << endl;
        cout << endl;
        cout << "Korko: " << tiliLista[paalistaIndeksi].getKorko() << "%" << endl;

    }

    else{

        cout << endl;
        cout << "Tilin lisays epaonnistui. " << endl;
    }

    // <------- PÄÄTTYY ------->
}

void siirto(Tili tiliLista[], int size){

    string siirtava;
    int siirtavaIndeksi = EI_LOYTYNYT;

    string vastaanottaja;
    int vastaanottavaIndeksi = EI_LOYTYNYT;

    double siirtoSumma = 0;

    cout << endl;
    cout << "Siirto" << endl;

    do {
        cout << endl;
        cout << "Siirtava omistaja? (nimi) ";
        getline(cin, siirtava);

        if(siirtava.compare("") != 0 || !siirtava.empty()){
            break;
        }

    } while (valmis);

    cout << endl;
    cout << "Annettiin nimi: " << siirtava << endl;

    for (int i = 0; i <= size; i++ ) {

        if (i == size) {
            cout << endl;
            cout << "Siirtavaa omistajaa ei loytynyt." << endl;
            break;
        }
        if (tiliLista[i].getOmistaja().compare(siirtava) == 0) {
            cout << endl;
            cout << "Omistaja " << tiliLista[i].getOmistaja() << " Loytyi!" << endl;

            siirtavaIndeksi = i;

            cout << endl;
            cout << "Tilin saldo: " << tiliLista[siirtavaIndeksi].getSumma() << "$" << endl;

            break;
        }
    }

    if (siirtavaIndeksi != EI_LOYTYNYT) {

        cout << endl;
        cout << "Vastaanottava omistaja? (nimi) ";
        getline(cin, vastaanottaja);
        cout << endl;
        cout << "Annettiin nimi: " << vastaanottaja << endl;

        for (int i = 0; i <= size; i++ ) {

            if(i == size){
                cout << endl;
                cout << "Vastaanottavaa omistajaa ei loytynyt." << endl;
                break;
            }

            if (tiliLista[i].getOmistaja().compare(vastaanottaja) == 0) {
                cout << endl;
                cout << "Omistaja " << tiliLista[i].getOmistaja() << " Loytyi!" << endl;
                vastaanottavaIndeksi = i;
                break;
            }
        }

        if (vastaanottavaIndeksi != EI_LOYTYNYT) {

            cout << endl;
            cout << "Tilin saldo: " << tiliLista[siirtavaIndeksi].getSumma() << "$" << endl;

            cout << endl;
            cout << "Siirrettava summa: ";
            cin >> siirtoSumma;

            if (siirtoSumma > tiliLista[siirtavaIndeksi].getSumma()){
                cout << endl;
                cout << "Tilin saldo ei riita. ";
            }

            else {

               double nykySumma = tiliLista[siirtavaIndeksi].getSumma();
               double uusiSumma = (nykySumma - siirtoSumma);
               tiliLista[siirtavaIndeksi].setSumma(uusiSumma);
               cout << endl;
               cout << "Siirto suoritettu.";

               cout << endl;
               cout << "Tilin uusi saldo: " << tiliLista[siirtavaIndeksi].getSumma() << "$" << endl;
            }
        }

        return;
    }

    return;
}

void talletus(Tili tiliLista[], int size){

    string omistaja;
    int omistajaIndeksi = EI_LOYTYNYT;

    cout << endl;
    cout << "Talletus" << endl;

    do {
        cout << endl;
        cout << "Omistaja nimi: ";
        getline(cin, omistaja);

        if(omistaja.compare("") != 0 || !omistaja.empty()){
            break;
        }

    } while (valmis);

    for (int i = 0; i <= size; i++ ) {

        if (i == size) {
            cout << endl;
            cout << "Omistajaa ei loytynyt." << endl;
            break;
        }
        if (tiliLista[i].getOmistaja().compare(omistaja) == 0) {
            cout << endl;
            cout << "Omistaja " << tiliLista[i].getOmistaja() << " Loytyi!" << endl;

            omistajaIndeksi = i;

            cout << endl;
            cout << "Tilin saldo: " << tiliLista[omistajaIndeksi].getSumma() << "$" << endl;

            break;
        }
    }
    if (omistajaIndeksi != EI_LOYTYNYT) {

        double talletusSum;

        cout << endl;
        cout << "Talletettava summa: ";
        cin >> talletusSum;

        if (talletusSum >= 0) {

            double nykySumma = tiliLista[omistajaIndeksi].getSumma();
            double uusiSumma = (nykySumma + talletusSum);

            tiliLista[omistajaIndeksi].setSumma(uusiSumma);

            cout << endl;
            cout << "Talletus onnistui!" << endl;

            cout << endl;
            cout << "Tilin uusi saldo: " << tiliLista[omistajaIndeksi].getSumma() << "$" << endl;

            return;
        }

        else{
            cout << "Epakelvollinen syote" << endl;
            return;
        }


    }
    return;
}

void nosto(Tili tiliLista[], int size){

    string omistaja;
    int omistajaIndeksi = EI_LOYTYNYT;

    cout << endl;
    cout << "Nosto" << endl;

    do {
        cout << endl;
        cout << "Omistaja nimi: ";
        getline(cin, omistaja);

        if(omistaja.compare("") != 0 || !omistaja.empty()){
            break;
        }

    } while (valmis);


    for (int i = 0; i <= size; i++ ) {

        if (i == size) {
            cout << endl;
            cout << "Omistajaa ei loytynyt." << endl;
            break;
        }
        if (tiliLista[i].getOmistaja().compare(omistaja) == 0) {
            cout << endl;
            cout << "Omistaja " << tiliLista[i].getOmistaja() << " Loytyi!" << endl;

            omistajaIndeksi = i;

            cout << endl;
            cout << "Tilin saldo: " << tiliLista[omistajaIndeksi].getSumma() << "$" << endl;

            break;
        }
    }
    if (omistajaIndeksi != EI_LOYTYNYT) {

        double nostoSumma;

        cout << endl;
        cout << "Nosto summa: ";
        cin >> nostoSumma;

        if (nostoSumma >= 0) {

            double nykySumma = tiliLista[omistajaIndeksi].getSumma();
            double uusiSumma = (nykySumma - nostoSumma);

            tiliLista[omistajaIndeksi].setSumma(uusiSumma);

            cout << endl;
            cout << "Nosto onnistui!" << endl;

            cout << endl;
            cout << "Tilin uusi saldo: " << tiliLista[omistajaIndeksi].getSumma() << "$" << endl;

            return;
        }

        else{
            cout << "Epakelvollinen syote" << endl;
            return;
        }

    }
    return;
}

void poistaTili(Tili tiliLista[], int size){

    string omistaja;
    int omistajaIndeksi = EI_LOYTYNYT;
    string valinta;

    cout << endl;
    cout << "Tilin poisto" << endl;

    do {
        cout << endl;
        cout << "Omistaja nimi: ";
        getline(cin, omistaja);

        if(omistaja.compare("") != 0 || !omistaja.empty()){
            break;
        }

    } while (valmis);



    for (int i = 0; i <= size; i++ ) {

        if (i == size) {
            cout << endl;
            cout << "Omistajaa ei loytynyt." << endl;
            return;
        }
        if (tiliLista[i].getOmistaja().compare(omistaja) == 0) {
            cout << endl;
            cout << "Omistaja " << tiliLista[i].getOmistaja() << " Loytyi!" << endl;

            omistajaIndeksi = i;

            cout << endl;
            cout << "Tilin saldo: " << tiliLista[omistajaIndeksi].getSumma() << "$" << endl;

            break;
        }
    }


    do {
        cout << "Poista tili? (Kylla/Ei)" << endl;
        getline(cin, valinta);

        if(valinta.compare("Kylla") == 0){
            tiliLista[omistajaIndeksi].setOmistaja("");
            tiliLista[omistajaIndeksi].setSumma(0);
            tiliLista[omistajaIndeksi].setTyyppi("");
            cout << endl;
            cout << "Tili poistettu onnistuneesti, kiitos asiakkuudestasi!";
            break;
        } else if( valinta.compare("Ei") == 0){
            cout << endl;
            cout << "Poisto keskeytetty, palataan paavalikkoon...";
            break;
        }

    } while (valmis);
    return;
}

int main()
{

    int valinta = 0;

    Tili paaTiliLista[MAX_TILEJA];

    Tili uusiTili = Tili(42, "Kaytto", "Jarmo Koskinen"); // Luodaan testi tili
    Tili uusiTili2 = Tili(24, "Kaytto", "Irja Kukka"); // Luodaan testi2 tili

    lisaaTiliListaan(paaTiliLista, uusiTili, MAX_TILEJA); // Lisätään testi päätili taulukkoon
    lisaaTiliListaan(paaTiliLista, uusiTili2, MAX_TILEJA); // Lisätään testi2 päätili taulukkoon

    do {

        cout << endl;
        cout << "Tervetuloa Pikapankkiin!" << endl;
        cout << endl;
        cout << endl;
        cout << "Valitse 1, luodaksesi tilin" << endl;
        cout << endl;
        cout << "Valitse 2, siirtaaksesi rahaa toiselle tilille" << endl;
        cout << endl;
        cout << "Valitse 3, tallettaaksesi rahaa tilille" << endl;
        cout << endl;
        cout << "Valitse 4, nostaaksesi rahaa tililta" << endl;
        cout << endl;
        cout << "Valitse 5, poistaaksesi tilin" << endl;
        cout << endl;
        cout << "Valitse 6, lopettaaksesi ohjelman" << endl;

        cin >> valinta;

        if(valinta == 1){

            luoTili(paaTiliLista, MAX_TILEJA);

        } else if(valinta == 2){

            siirto(paaTiliLista, MAX_TILEJA);

        } else if(valinta == 3){

            talletus(paaTiliLista, MAX_TILEJA);

        } else if(valinta == 4){

            nosto(paaTiliLista, MAX_TILEJA);

        } else if(valinta == 5){

            poistaTili(paaTiliLista, MAX_TILEJA);

        } else if(valinta == 6){

            cout << endl;
            cout << "Kiitos ja nakemiin!" << endl;
            break;
        }

    } while (valmis);

    // luoTili(paaTiliLista, MAX_TILEJA);

    // siirto(paaTiliLista, MAX_TILEJA);

    // talletus(paaTiliLista, MAX_TILEJA);

    // nosto(paaTiliLista, MAX_TILEJA);

    // poistaTili(paaTiliLista, MAX_TILEJA);

    return 0;
}

//    cout << "1. It's a: " << paaTiliLista[0].getOmistaja() << endl;
//    cout << endl;
//    cout << "2. It's a: " << paaTiliLista[9].getOmistaja() << endl;
//    cout << endl;
//    cout << "3. It's a: " << paaTiliLista[9].getKorko() << endl;
//    cout << endl;
//    cout << "4. It's a: " << paaTiliLista[9].getNimi() << endl;
//    cout << endl;
//    cout << "5. It's a: " << paaTiliLista[9].getSumma() << endl;
//    cout << endl;
//    cout << "6. It's a: " << paaTiliLista[9].getTyyppi() << endl;
//    cout << endl;

//    string str1;

//    cout << "Eka: ";
//    getline(cin, str1);
//    cout << endl;

//    if (str1.compare(paaTiliLista[1].getOmistaja()) == 0) {
//        cout << endl;
//        cout << "Its a match!" << endl;
//    }

//    else {
//        cout << endl;
//        cout << "NO" << endl;
//    }

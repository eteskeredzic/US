/*
Zadatak 4 - LPC1114ETF
Koristenjem digitalnog porta, realizovati "trcece svjetlo" na LED diodama. Dakle, prvo se ukljuci prva dioda,
zatim druga dioda (a prva se iskljuci) i tako redom. Dolaskom na kraj (do 8. diode), ukljuci se opet prva dioda
i proces pocinje ispocetka.

#include "mbed.h"
#define dp23 P0_0
DigitalOut e(dp14); // enable

DigitalIn taster(dp1);

BusOut b((dp23), (dp24),(dp25), (dp26), (dp27), (dp5), (dp6), (dp28)); // 8 LED dioda

int main() {
    e = 0; // LED mode
    b = 0; // na pocetku nula
    unsigned int x = 1; // pocetna vrijednost
    while(1){
        for(int i = 0; i < 8; ++i){ // idi kroz 8 dioda
            b = x; // dodijeli
            x = x << 1; // mnozi sa 2
            wait(0.1); // cekaj malo
        }
        x = 1; // restart
    }
}


*/

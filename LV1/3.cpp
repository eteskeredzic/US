/*
Zadatak 3 - LPC1114ETF
Koristenjem 8 LED dioda na razvojnom sistemu, realizovati binarni brojac, koji se uvecava za jedan svake
sekunde. Ukoliko je Taster 1 pritisnut, brojanje treba da ide unazad.

#include "mbed.h"
#define dp23 P0_0
DigitalOut e(dp14); // enable

DigitalIn taster(dp1);

BusOut b((dp23), (dp24),(dp25), (dp26), (dp27), (dp5), (dp6), (dp28)); // 8 LED dioda

int main() {
    e = 0; // kad je enable na 0, onda je u modusu za LED diode
    unsigned int i = 0;
    while(1){
        b = i; // BusOut ce se pobrinuti da ovo bude binarno
        if(taster) --i;
        else ++i;
        wait(1);
    }
}

*/

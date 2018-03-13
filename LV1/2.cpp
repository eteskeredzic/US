/*
Zadatak 2 - Freescale FRDM-25KLZ
Napisati program koji omogucava da se crvena, zelena i plava LED dioda ukljucuju u sljedecem redoslijedu:
R-G-B-R-G-B-... itd. pri cemu su u prvoj iteraciji diode ukljucene po 1 sekundu, u iducoj iteraciji po 0.9
sekundi itd. sve dok ne dostignu vrijeme od 0.1 sekunde. Kada dostignu to vrijeme, onda trebaju tako da
nastave, a interval se vise ne treba smanjivati (ostaje 0.1 sekunda).

#include "mbed.h"

DigitalOut myled1(LED1); // definisanje LED dioda
DigitalOut myled2(LED2);
DigitalOut myled3(LED3);

int main() {
    double t = 10; // koliko traje
    myled1 = 1;
    myled2 = 1;
    myled3 = 1;
    while(t > 1){
        myled1 = 0; // pali crvenu
        wait(t/10); // cekaj
        myled1 = 1; // gasi crvenu
        myled2 = 0; // pali zelenu
        wait(t/10); // itd..
        myled2 = 1;
        myled3 = 0;
        wait(t/10);
        myled3 = 1;
        --t;
    }
    while(1) { // dostigli 0.1, vrti vjecno
        myled1 = 0;
        wait(0.1);
        myled1 = 1;
        myled2 = 0;
        wait(0.1);
        myled2 = 1;
        myled3 = 0;
        wait(0.1);
        myled3 = 1;
    }
}

*/

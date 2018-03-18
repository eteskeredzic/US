#include "mbed.h"
#define dp23 P0_0
DigitalOut enable(dp14);

DigitalOut displej[] = {dp25, dp24, dp23}; // oznacava koju od 3 cifre radimo
BusOut broj (dp26, dp27, dp5, dp6, dp28, dp4, dp18); // upisuje cifru na 7 segmentni
DigitalIn taster1(dp1);
DigitalIn taster2(dp2);

short int brojevi[] = {64, 121, 36, 48, 25, 18, 2, 120, 0, 16, 8, 3, 70, 33, 9, 1};

void prikaz(int brojac){
    displej[0] = 1;
    displej[1] = 1;
    displej[2] = 1;
    displej[0] = 0;
    broj = brojevi[brojac%10];
    wait(0.001);
    brojac/=10;
    displej[0] = 1;
    displej[1] = 0;
    broj = brojevi[brojac%10];
    wait(0.001);
    brojac/=10;
    displej[1] = 1;
    displej[2] = 0;
    broj = brojevi[brojac];
    wait(0.001);
    displej[2] = 1;
}

int main() {
    enable = 1;
    short int brojac = 0;
    while(1){
        if(taster1){
            ++brojac;
            if(brojac>999)
                brojac = 0;
                wait(0.001);
            prikaz(brojac);
            while(taster1) // dok je pritisnuto ne idi dalje (ivica)
                prikaz(brojac);
        }
        else if(taster2){
            --brojac;
            if(brojac<0)
                brojac = 999;
            prikaz(brojac);
            wait(0.001);
            while(taster2)
                prikaz(brojac);
        }
        prikaz(brojac);
        wait(0.001);
    }
}

/*
VERZIJA SA KOMPLEMENTOM
#include "mbed.h"
#define dp23 P0_0
DigitalOut enable(dp14);

DigitalOut displej[] = {dp25, dp24, dp23};
BusOut broj (dp26, dp27, dp5, dp6, dp28, dp4, dp18);
DigitalIn taster1(dp1);
DigitalIn taster2(dp2);
short int brojevi[] = {63, 6, 91, 79, 102, 109, 125, 7, 127, 111, 95, 62, 88, 94, 64, 92};

void prikaz(int broj);

int main() {
    enable = 1;
    int brojac = 0;
    while(1) {
        if(taster1){
            ++brojac;
            if(brojac>999)
                brojac = 0;
                wait(0.001);
            prikaz(brojac);
            while(taster1)
                prikaz(brojac);
        }
        else if(taster2){
            --brojac;
            if(brojac<0)
                brojac = 999;
            prikaz(brojac);
            wait(0.001);
            while(taster2)
                prikaz(brojac);
        }
        prikaz(brojac);
        wait(0.001);
    }
}

void prikaz(int brojac){
    displej[0] = 1;
    displej[1] = 1;
    displej[2] = 1;
    displej[0] = 0;
    broj = 127-brojevi[brojac%10];
    wait(0.001);
    brojac/=10;
    displej[0] = 1;
    displej[1] = 0;
    broj = 127-brojevi[brojac%10];
    wait(0.001);
    brojac/=10;
    displej[1] = 1;
    displej[2] = 0;
    broj = 127-brojevi[brojac];
    wait(0.001);
    displej[2] = 1;
}
*/

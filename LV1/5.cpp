/*

#include "mbed.h"

DigitalOut myled(LED1);

int main() {
    double  T = 0.1;
    double  ukupno = 2*T;
    int x = 0;
    bool pozitivan = false;
    // prvi run
    while(1){
        myled = 0;
        wait(T + 0.1 * x);
        myled = 1;
        wait(T - 0.1 * x);
        ++x;
        if(x > 9) break;
    }
    x = 9;
    while(1){
        myled = 0;
        wait(T + 0.1 * x);
        myled = 1;
        wait(T - 0.1 * x);
        if(pozitivan) ++x;
        else --x;
        if(x > 18) {
            pozitivan = false;
            x ^= x;
        }
        else if(x < -18){
        pozitivan = true;
            x ^= x;
        }
    }




    bool rast = true;

    while(1) {
        if(T>=ukupno)
            T = 1.9 * ukupno;
        if(T<=0)
            T = 0.1 * ukupno;

        myled = 1;
        wait(ukupno-T+0.1);
        myled = 0;
        wait(T+0.1);

        if(rast && T >= 1.9 * ukupno)
            rast = false;
        if (rast == false && T <= 0.1 * ukupno)
            rast = true;

        if(rast)
            T += ukupno/60;
        if(rast == false)
            T -= ukupno/60;


    }
}

*/

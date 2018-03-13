#include "mbed.h"

DigitalOut myled(LED1);

    int main() {
    myled=1;
    double T = 1,b=0.06 * T;
    for(int i=T;1;i+=b)
    {
        myled=0;
        wait(i);
        myled=1;
        wait(2*T-i);
        if(i>=1.9*T || i<=0.1*T) b*=-1;
    }
}

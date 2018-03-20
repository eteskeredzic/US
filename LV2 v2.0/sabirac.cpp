#include "mbed.h"
#define dp23 P0_0
DigitalOut enable(dp14);

DigitalOut displej[] = {dp25, dp24, dp23};
BusOut broj (dp26, dp27, dp5, dp6, dp28, dp1, dp2);
short int brojevi[] = {0, 64, 121, 36, 48, 25, 18, 2, 120, 0, 16, 8, 3, 70, 33, 9, 1};
DigitalOut rows[] = {dp16, dp15, dp17, dp18};
DigitalIn cols[] = {dp9, dp10, dp11, dp13};

void prikaz(int brojac);

int PopraviBrojac(int brojac){
    int novi = 0;
    novi += brojac % 10;
    brojac /= 10;
    novi += (brojac%10)*10;
    brojac/=10;
    novi += (brojac%10)*100;
    return novi;
}


int main() {
    int sabirak1 = 0;
    enable = 1;
    displej[0] = 1;
    displej[1] = 1;
    displej[2] = 1;
    int brojac = 0;
    while(1) {
        rows[0] = 1;
        for(int i = 0; i < 3 ; ++i)
            if(cols[i]){
            brojac*=10;
            brojac+=i+1;
            prikaz(brojac);
            while(cols[i]) prikaz(brojac);
            }
        rows[0] = 0;
        rows[1] = 1;
        wait(0.001);
        for(int i = 0; i < 3; ++i)
            if(cols[i]){
            brojac*=10;
            brojac+=i+4;
            prikaz(brojac); while(cols[i]) prikaz(brojac);
            }
        rows[1] = 0;
        rows[2] = 1;
        wait(0.001);
        for(int i = 0; i < 3; ++i)
            if(cols[i]){
            brojac*=10;
            brojac+=i+7;
            prikaz(brojac); while(cols[i]) prikaz(brojac);
            }
        if(cols[3]){
            sabirak1 =0; brojac = 0; prikaz(brojac); while(cols[3]) prikaz(brojac);
}
        rows[2] = 0;
       // if(brojac > 999) brojac = brojac % 1000;
        prikaz(brojac);
        rows[3] = 1;
        wait(0.001);
        if(cols[0]){
            sabirak1 += brojac;
            brojac = 0;
            prikaz(brojac);
            while(cols[0]) prikaz(brojac);
            }
            if(cols[2]){ brojac = sabirak1; prikaz(brojac); while(cols[2]) prikaz(brojac); }
            rows[3] = 0;
    }
    
}

void prikaz(int brojac){
    displej[0] = 1;
    displej[1] = 1;
    displej[2] = 1;
    if(brojac > 999){
        broj = 6;
        displej[0] = displej[1] = displej[2] = 0;
        wait(0.001);
        return;
        }
    broj = brojevi[brojac%10+1];
    displej[0] = 0;
    wait(0.001);
    brojac/=10;
    displej[0] = 1;
    broj = brojevi[brojac%10+1];
    displej[1] = 0;
    wait(0.001);
    brojac/=10;
    displej[1] = 1;
    broj = brojevi[brojac%10+1];    
    displej[2] = 0;
    wait(0.001);
    displej[2] = 1;
}

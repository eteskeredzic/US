#include "mbed.h"
#define dp23 P0_0
DigitalOut enable(dp14);

DigitalOut displej[] = {dp25, dp24, dp23};
BusOut broj (dp26, dp27, dp5, dp6, dp1, dp2, dp4);
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
            }
        rows[0] = 0;
        rows[1] = 1;
        wait(0.001);
        for(int i = 0; i < 3; ++i)
            if(cols[i]){
            brojac*=10;
            brojac+=i+4;
            prikaz(brojac);
            }
        rows[1] = 0;
        rows[2] = 1;
        wait(0.001);
        for(int i = 0; i < 3; ++i)
            if(cols[i]){
            brojac*=10;
            brojac+=i+7;
            prikaz(brojac);
            }
        if(cols[3])
            broj = 0;

        rows[2] = 0;
		if(brojac > 999) brojac = PopraviBrojac(brojac);
        prikaz(brojac);
    }
}

void prikaz(int brojac){
    displej[0] = 1;
    displej[1] = 1;
    displej[2] = 1;
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

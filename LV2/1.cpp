#include "mbed.h"
#define dp23 P0_0
DigitalOut enable(dp14);

DigitalOut leds[] = {(dp23), (dp24),(dp25), (dp26), (dp27), (dp5), (dp6), (dp28)};
DigitalOut rows[] = {dp16, dp15, dp17, dp18};
DigitalIn cols[] = {dp9, dp10, dp11, dp13};

int main() {
    enable = 0;
    while(1) {
        rows[0] = 1; // pali prvi red
        wait(0.001);
        for(int i = 0; i < 3; ++i)
            leds[i] = cols[i];

        rows[0] = 0;
        rows[1] = 1;
        wait(0.001);
        for(int i = 0; i < 3; ++i)
            leds[i+3] = cols[i];

        rows[1] = 0;
        rows[2] = 1;
        wait(0.001);
        for(int i = 0; i < 3; ++i)
            leds[i+6] = cols[i];

        rows[2]  = 0;
    }
}

/*
VARIJANTA SA IF-ovima:
#include "mbed.h"
#define dp23 P0_0
DigitalOut enable(dp14);

DigitalOut leds[] = {(dp23), (dp24),(dp25), (dp26), (dp27), (dp5), (dp6), (dp28)};
DigitalOut rows[] = {dp16, dp15, dp17, dp18};
DigitalIn cols[] = {dp9, dp10, dp11, dp13};

int main() {
    enable = 0;
    while(1) {
        rows[0] = 1;
        wait(0.001);
        if(cols[0])
            leds[0] = 1;
        else
            leds[0] = 0;

        if(cols[1])
            leds[1] = 1;
        else
            leds[1] = 0;

        if(cols[2])
            leds[2] = 1;
        else
            leds[2] = 0;

        rows[0] = 0;
        rows[1] = 1;
        wait(0.001);
        if(cols[0])
            leds[3] = 1;
        else
            leds[3] = 0;

        if(cols[1])
            leds[4] = 1;
        else
            leds[4] = 0;

        if(cols[2])
            leds[5] = 1;
        else
            leds[5] = 0;

        rows[1] = 0;
        rows[2] = 1;
        wait(0.001);
        if(cols[0])
            leds[6] = 1;
        else
            leds[6] = 0;

        if(cols[1])
            leds[7] = 1;
        else
            leds[7] = 0;

        if(cols[2])
            leds[8] = 1;
        else
            leds[8] = 0;

        rows[2] = 0;
    }
}
*/




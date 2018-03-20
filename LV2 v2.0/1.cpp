#include "mbed.h"
#define dp23 P0_0
DigitalOut enable(dp14);

DigitalOut leds[] = {dp23, dp24,dp25, dp26, dp27, dp5, dp6, dp28};
DigitalOut rows[] = {dp16, dp15, dp17, dp18};
DigitalIn cols[] = {dp9, dp10, dp11, dp13};

int main() {
    enable = 0;
    while(1) {
        rows[0] = 1; // pali prvi red
        wait(0.001); // cekaj da struja dodje
        for(int i = 0; i < 3; ++i) // vrti kroz kolone
            leds[i] = !cols[i]; // ako je 1, upalis diodu

        rows[0] = 0; // gasi prvi red
        rows[1] = 1; // pali drugi red
        wait(0.001); // cekaj
        for(int i = 0; i < 3; ++i) // vrti kroz kolone
            leds[i+3] = !cols[i]; // pali odgovarajuci LED

        rows[1] = 0; // gasi drugi
        rows[2] = 1; // pali treci
        wait(0.001); // cekaj
        for(int i = 0; i < 3; ++i) // vrti kroz kolone
            leds[i+6] = !cols[i]; // pali odgovarajuci LED

        rows[2]  = 0; // gasi treci red
    }
}



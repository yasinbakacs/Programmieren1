#include <stdio.h>

int main() {
    unsigned char status = 0xA7;
    unsigned char MaskeFehler = 0b10000000;
    unsigned char MaskeTemp = 0b01000000;
    unsigned char MaskeSpannung = 0b00100000;
    unsigned char MaskeWert = 0b00001111;

    printf("Statusbyte: 0x%02X\n", status);
    if (status & MaskeFehler) {
        printf("Fehler erkannt\n");
    } else {
        printf("Kein Fehler\n");
    }
    if (status & MaskeTemp) {
        printf("Übertemperatur erkannt\n");
    }else{
        printf("Temperatur in Ordnung\n");
    }
    if (status & MaskeSpannung) {
        printf("Unterspannung erkannt\n");
    }else{
        printf("Spannung in Ordnung\n");
    }
    printf("Sensorwert: %x \n", (status & MaskeWert));
    return 0;
}
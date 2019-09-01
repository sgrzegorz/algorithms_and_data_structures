
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

//Wielomian dla CRC-32 zgodny ze standardem Ethernet, ZIP i RAR
#define P 0x04c11db7


unsigned long tablica[256];

//Funkcja zamienia miejscami bity starsze z mlodszymi
unsigned long Zamien_bity(unsigned long liczba, char l_bitow) {
    unsigned long wynik = 0;
    for (int i = 1; i < (l_bitow + 1); i++) {
        if (liczba & 1)
            wynik |= 1 << (l_bitow - i);
        liczba >>= 1;
    }
    return wynik;
}

//Wypelnia tablice odpowiednimi wartosciami
void Inicjuj_tablice(void) {
//Dla kazdego znaku ASCII
    for (int ASCII = 0; ASCII < 256; ASCII++) {
        tablica[ASCII] = Zamien_bity(ASCII, 8) << 24;
        for (int j = 0; j < 8; j++) {
            if ((tablica[ASCII] & (1 << 31)) != 0)
                tablica[ASCII] = (tablica[ASCII] << 1) ^ P;
            else
                tablica[ASCII] = (tablica[ASCII] << 1);
        }
        tablica[ASCII] = Zamien_bity(tablica[ASCII], 32);
    }
    return;
}

void Oblicz_CRC(char *txt) {
//Wartosc poczatkowa to (2^32)-1
    unsigned long crc32 = 0xffffffff;

    int wynik;
    char kod[20];

//Liczba bajtow do przetworzenia
    int dlugosc;

//Tekst, dla ktorego obliczymy crc32
    unsigned char *tekst;
//------------------------------------------------------------

//Przykladowy tekst
    tekst = (unsigned char *) txt;
    dlugosc = strlen(tekst);

//Obliczaj crc przesuwajac kolejne znaki tekstu wejsciowego
    while (dlugosc--)
        crc32 = (crc32 >> 8) ^ tablica[(crc32 & 255) ^ *tekst++];
//Wykonaj operacje XOR z wartoscia poczatkowa
    wynik = crc32 ^ 0xffffffff;

//Zamien wynik na hex
    itoa(wynik, kod, 16);
    printf("Tekst wejsciowy: %s\n", txt);
    printf("Suma CRC32: %s\n", kod);
    printf("Dowolny klawisz...");


    return;
}

void main(void) {
//Funkcja tworzy tablice kodow dla wszystkich znakow ASCII
    Inicjuj_tablice();

    Oblicz_CRC("algorytmy i struktury danych");
    getch();
    return;
}

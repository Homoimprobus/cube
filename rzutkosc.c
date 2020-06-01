/* rzutkosc.c -- symulacja rzutu kostk¹ */
/* komilowaæ z wielorzut.c */
#include <stdio.h>
#include <stdlib.h>		// potzebna dla funkcji rand()
#include "rzutkosc.h"

int liczba_rzutow = 0;	//³¹cznoœæ zewnêtrzna
static int rzucaj(int scianki)
{
	int oczka;
	oczka = rand() % scianki + 1;
	++liczba_rzutow;
}

int rzucaj_n_razy(int rzuty, int scianki)
{
	int k;
	int suma = 0;
	if (scianki < 2)
	{
		puts("Wymagane sa conajmniej 2 scianki");
		return -2;
	}
	if (rzuty < 1)
	{
		puts("Wymagany co najmniej 1 rzut");
		return -1;
	}
	for (k = 0; k < rzuty; k++)
		suma += rzucaj(scianki);
	return suma;
}


/* wielorzut.c -- wilokrotny rzut koœcmi */
/* kompilowaæ z rzutkosc.c */
#include <stdio.h>
#include <stdlib.h>		// potrzebna funkcja srand()
#include <time.h>		// potrzeba funkcji time()
#include "rzutkosc.h"	// potrzebna funkcja rzucaj_n_razy()

int main(void)
{
	int rzuty, wynik;
	int scianki, status;

	srand((unsigned int)time(0));	//losowe ziarno
	puts("Podaj liczbe scianek, 0 oznacza koniec.");
	while (scanf_s("%d", &scianki) == 1 && scianki > 0)
	{
		puts("Ile rzutow?");
		if ((status = scanf_s("%d", &rzuty)) != 1)
		{
			if (status == EOF)
				break;
			else
			{
				puts("Nalezy podac liczbe calkowita. Sprubujmy jeszcze raz");
				while (getchar() != '\n')
					continue; // odrzucenie niepoprawnego wejscia
				puts("Ile scianek?, 0 oznacza koniec");
				continue;
			}
		}
		wynik = rzucaj_n_razy(rzuty, scianki);
		printf("Wyrucono razem %d uzywajac %d %d-sciennych kosci.\n",
			wynik, rzuty, scianki);
		puts("Podaj liczbe scianek, 0 oznacza koniec");
	}
	printf("Funkcja rzucaj() zostala wywolana %d razy\n", liczba_rzutow); // zmienna zewnetrzna
	puts("Zycze duzo sczescia.");
}
#include <stdio.h>
#include <stdlib.h>

#include "libreria.h"

void main ()
{
    //elenco di prodotti di tipo Prodotti
    Prodotti prodotto[5]=
    {
        {"Vetro", 1, 1.50F, 20},
        {"Plastica", 2, 1.0F, 20},
        {"Carta", 3,  0.50F, 20},
        {"Alluminio", 4.50, 3.50F, 20},
        {"Olio", 5, 5.0F, 20}
    };

    float budget_inserito;
    int codice, giorni;

    printf("      LISTA DI PRODOTTI DA RICICLARE:\n\n");
    //chiamata di "stampa_prodotti" per stampare l'elenco dei prodotti
    stampa_prodotti(prodotto);

    //chiamata di "inserisci_inserisci" che permette al'utente di inserire il budget iniziale
    budget_inserito=inserisci_budget();



    do
    {
        //chiamata di "scelta_prodotto" per la scelta del prodotto in base al codice
        codice=scelta_prodotto(prodotto);

        //chiamata di "ricicla" che permette di riciclare il prodotto inbase al suo codice e costo
        ricicla(prodotto, budget_inserito, codice);

        giorni++;
    }

    //l'idea e' di stampare a fine settimana, cioè al settimo giorno le rimanenze dei prodotti
    while(giorni<7);

    printf("\n\n REPORT SETTIMANALE: \n\n");
    stampa_prodotti(prodotto);

    /*chiamata dei "controllo_spazio" per controllare gli spazi dei prodotti
     ed eventualmente liberare lo spazio occupato*/
    controllo_spazio(prodotto, budget_inserito, codice);
}


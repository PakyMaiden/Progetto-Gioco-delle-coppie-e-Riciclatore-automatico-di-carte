#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "libreria.h"

/*Nel gioco delle coppie di carte, inizialmente consiste nell' osservare  le carte mischiate, scoperte,
e di ricordare le esatte posizioni per indovinare dove sono.
Se si pescano due carte diverse, tocca all'altro giocatore pescare, vince chi totalizza piu punti,
cioe' chi pesca piu' coppie di carte uguali fino a totalizzare 11 punti*/

void main()
{
    //dichiarazione e inizializzazione delle variabili:
    int inizio, i, j, punti_giocatore_1=0, punti_giocatore_2=0, k=0, punti_totali, mix, n_carte=40;
    char giocatore_1[11], giocatore_2[11];

    //ci servira' per effettuare i cast sui semi in stringhe, altrimenti vedremo numeri
    char *Semi[]= {"coppe", "bastoni", "spade", "denari"};

    //array di tipo Carta_Nap di 40 carte del mazzo napoletano
    Carta_Nap mazzo[40]=
    {
        {1,coppe}, {2,coppe}, {3,coppe}, {4,coppe}, {5,coppe}, {6,coppe}, {7,coppe}, {8,coppe}, {9,coppe}, {10,coppe},
        {1,bastoni}, {2,bastoni}, {3,bastoni}, {4,bastoni}, {5,bastoni}, {6,bastoni}, {7,bastoni}, {8,bastoni}, {9,bastoni}, {10,bastoni},
        {1,spade}, {2,spade}, {3,spade}, {4,spade}, {5,spade}, {6,spade}, {7,spade}, {8,spade}, {9,spade}, {10,spade},
        {1,denari}, {2,denari}, {3,denari}, {4,denari}, {5,denari}, {6,denari}, {7,denari}, {8,denari}, {9,denari}, {10,denari}
    };

    srand(time(NULL));

    //qui si dichiarano i giocatori(chiaramente va usato gets() per gestire l'input di stringhe
    printf(" Inserire il nome del primo giocatore: ");
    gets(giocatore_1);

    printf(" Inserire il nome del secondo giocatore: ");
    gets(giocatore_2);

    //L'utente sceglie quante volte mischiare il mazzo
    printf(" Quante volte vuoi mischiare il mazzo?: ");
    scanf("%d", &mix);
    printf(" \n");

    /*chiamata della procedura per mischiare il mazzo Carta_Nap
    chiaramente composta da 40 carte (n_carte) e quante volte mischiare (mix)*/
    mischia_carte(mazzo, n_carte, mix);

    //temporeggia 2 secondi per mischiare le carte
    sleep(2);

    /*Stampa le carte scoperte
    e utilizziamo il cast sui semi in stringa per capire che tipo di seme e' ed il valore(numero) associato */
    for(k=0; k<n_carte; k++)
        printf("%d  %-15s\t", mazzo[k].valore, Semi[(int)mazzo[k].seme]);

    //appare un messaggio e avverte che ci sono 10 secondi a disposizione per osservare le carte scoperta
    printf("\n\n !!!Avete 5 secondi per osservare le carte scoperte, poi il primo giocatore sceglie la carta!!!");
    sleep(5); //temporeggia 5 secondi

    /*pulisce il terminale, potrebbe dare problemi su altri sistemi
    per i sistemi sotto Linux una buona alternativa e' system("clear");*/
    //system("cls"); //per sistemi Windows
    system("clear"); // per sistemi sotto Linux

    //operazione random da 0(inizia il giocatore 1) a 1(inizia il giocatore 2)
    inizio = rand()%2;

    if(inizio==0)
        printf("\n\n Il primo a giocare sara': %s\n\n", &giocatore_1);
    else
        printf("\n\n Il primo giocatore sara': %s\n\n", &giocatore_2);

    //Inizio della partita:
      do
    {
        printf(" LE POSIZIONI DELLE CARTE SONO MISCHIATE E COPERTE:\n\n");

        /*stampa le posizioni delle carte coperte(non mostra i semi),
         quando un giocatore ottiene il punto le carte diminuiscono */
        for(k=1; k<=n_carte; k++)
        {
            if(mazzo[k].valore==0)
                continue;
            else
                printf(" %d\t", k);
            if (k==40)
                printf("\n");
        }

        /*qui sara' gestito il gioco, quando i giocatori scelgono carte uguali ottengono un punto e continua a giocare
          se pescano una carta diversa perdono il proprio turno
          e se pescano una carta gia' scelta deve scegliere un'altra.
          Chi accumula 11 punti per primo vince, e il gioco termina*/
        if(inizio==0)
        {

            printf("\n\n %s: scegli la posizione della prima carta: ", &giocatore_1);
            scanf("%d",&i);
            while(mazzo[i].valore==0)
            {
                printf(" LA CARTA E' GIA' STATA SCELTA! SCEGLI UN'ALTRA CARTA: ");
                scanf("%d",&i);
            }
            printf(" La carta scelta e': %d %s !\n", mazzo[i].valore, Semi[(int)mazzo[i].seme]);

            printf(" %s: ora scegli la posizione della seconda carta: ", &giocatore_1);
            scanf("%d", &j);
            while(mazzo[j].valore==0)
            {
                printf(" LA CARTA E' GIA' STATA SCELTA! SCEGLI UN'ALTRA CARTA: ");
                scanf("%d", &j);
            }
        }
        else
        {
            printf("\n\n %s: scegli la posizione della prima carta: ", &giocatore_2);
            scanf("%d",&i);

            while(mazzo[i].valore==0)
            {
                printf(" LA CARTA E' GIA' STATA SCELTA! SCEGLI UN'ALTRA CARTA: ");
                scanf("%d",&i);
            }
            printf(" La carta scelta e': %d %s !", mazzo[i].valore, Semi[(int)mazzo[i].seme]);

            printf("\n %s: ora scegli la posizione seconda carta: ", &giocatore_2);
            scanf("%d",&j);

            while(mazzo[j].valore==0)
            {
                printf(" LA CARTA E' GIA' STATA SCELTA! SCEGLI UN'ALTRA CARTA: ");
                scanf("%d",&j);
            }
            printf(" La carta scelta e': %d %s !", mazzo[j].valore, Semi[(int)mazzo[j].seme]);
        }
        if(mazzo[i].valore==mazzo[j].valore)
        {

            printf("\n\n LE DUE CARTE SONO UGUALI! RICEVI UN PUNTO !\n\n " );
            if(inizio==0)
                punti_giocatore_1++;
            else
                punti_giocatore_2++;
            mazzo[i].valore=0;
            mazzo[j].valore=0;
        }
        else
        {
            system("cls");
            printf("\n LE DUE CARTE NON SONO UGUALI! IL TUO TURNO FINISCE.\n\n");
            if(inizio==0)
                inizio=1;
            else
                inizio=0;
        }
        punti_totali=punti_giocatore_1+punti_giocatore_2;
    }

    while(punti_totali<11);
    printf("\n HAI TOTALIZZATO 11 PUNTI! HAI VINTO!!\n" );
    scanf("%d", &inizio);
}


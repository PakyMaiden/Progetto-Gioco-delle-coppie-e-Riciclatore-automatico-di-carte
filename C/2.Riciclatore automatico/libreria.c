#include <stdio.h>

/*si crea una struct di elenco di prodotti e un nuovo tipo Prodotti.
In questo modo un prodotto di tipo Prodotti avrà queste caratteristiche: */
struct elenco_prod
{
    char tipo[10];
    int codice;
    float costo;
    int spazio;
};
typedef struct elenco_prod Prodotti;


/*Implementazione della procedura per stampare i prodotti di tipo Prodotti*/
void stampa_prodotti(Prodotti *prodotto)
{
    int i;

    printf(" TIPO\t\tCODICE\tPREZZO PER RICICLARE\tSPAZIO DISPONIBILE\n");
    for (i=0; i<5; i++)
        printf(" %-10s\t%4d\t%10.2f\t%17d\n", prodotto[i].tipo, prodotto[i].codice, prodotto[i].costo, prodotto[i].spazio);
    printf("\n\n");
}

/*implementazione che permette all'utente di inserire il budget iniziale,
chiaramente il budget non puo' essere 0 o inferiore a 0*/
float inserisci_budget()
{
    float budget_inserito;

    printf("\n Inserire budget iniziale: ");
    scanf("%f",&budget_inserito);

    while(budget_inserito==0 || budget_inserito<0)
    {
        printf(" Il budget non puo' essere 0 o negativo!");
        printf("\n Inserire budget iniziale: ");
        scanf("%f",&budget_inserito);
    }

    printf(" Budget iniziale del sistema e': %2.2f euro !\n\n", budget_inserito);

    return budget_inserito;
}


/*Function che consente di scegliere il codice del prodotto da smaltire,
 e stampa il nome del prodotto ed il suo costo*/
int scelta_prodotto(Prodotti *prodotto)
{
    int codice=0;

    printf("\n Inserire il codice del prodotto che si vuole smaltire: ");
    while (codice<1 || codice>5)
    {
        scanf(" %d", &codice);
        if (codice<1 || codice>5) //il codice da inserire deve essere compreso tra 1 e 5 altrimenti compare una stringa a video che indica l'errore nell'inserimento.
            printf(" Il codice inserito deve essere compreso tra 1 e 5\n\n Reinserire il codice del prodotto: ");
    }
    printf(" Prodotto selezionato: %s\n Costo: %.2f euro\n", prodotto[codice-1].tipo, prodotto[codice-1].costo);

    return codice;
}


/*questa function verifica se l'acquisto puo' essere portato a termine.
Se non pu' essere portato a termine, stampa un messaggio a video.
Se puo' essere portato a termine controlla se il budget inserito e' maggiore o uguale al prezzo del prodotto.*/
float ricicla(Prodotti *prodotto, float budget_inserito, int codice)
{
    if (budget_inserito>=prodotto[codice-1].costo)
    {
        prodotto[codice-1].spazio--;
        printf(" Il prodotto e' stato riciclato\n");
        printf(" Rimangono: %d spazi!\n", prodotto[codice-1].spazio);

        return codice;
    }
    else
        printf(" Il prodotto non e' stato riciclato! Il budget e' poco\n");
    return inserisci_budget();
}


/*Questa procedura consente di controllare gli spazi dei prodotti, e se a un prodotto
rimangono 13 spazi liberi per riciclare si provvede a liberare lo spazio a 20 spazi disponibili  */
void controllo_spazio(Prodotti *prodotto, float budget_inserito, int codice)
{
    if (prodotto[codice-1].spazio<=13)

        prodotto[codice-1].spazio = prodotto[codice-1].spazio+7;
        printf("\n Si provvede a liberare di questo prodotto: '%s' spazio (aggiornato): %d\n\n",prodotto[codice-1].tipo, prodotto[codice-1].spazio);
}


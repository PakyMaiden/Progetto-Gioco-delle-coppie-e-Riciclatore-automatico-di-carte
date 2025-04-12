
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

//Prototipi:

//Procedura che stampera' i prodotti di tipo Prodotti
void stampa_prodotti(Prodotti *);

//Function che permettera' di inserire un budget iniziale
float inserisci_budget();

//function che permettera' la scelta dei prodotti di tipo Prodotti da smaltire
int scelta_prodotto(Prodotti *);

//function che permettera' di riciclare i prodotti in base al codice
float ricicla(Prodotti *, float, int );

//procedura che permettera' di controllare gli spazi,ed eventualmente liberare
void controllo_spazio (Prodotti *, float , int );

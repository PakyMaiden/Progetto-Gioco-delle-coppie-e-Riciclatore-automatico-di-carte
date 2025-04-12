/*crea il tipo Semi_Nap enumerando i suoi oggetti, cioe' semi delle carte napoletane
sono costanti di tipo int, ma faremo un cast in stringhe nel main per distinguere il valore al seme associato*/
typedef enum {coppe, bastoni, spade, denari} Semi_Nap;

//struttura il tipo derivato carta_nap
struct carta_nap
{
    int valore;
    Semi_Nap seme;
};

//Crea il tipo Carta_Nap
typedef struct carta_nap Carta_Nap;

//procedura per scambiare le carte, classica funzione dello scambio tra due variabili di carte di tipo Carta_Nap
void scambiare_carte(Carta_Nap *carta1, Carta_Nap *carta2)
{
    Carta_Nap temp;
    temp=*carta1;
    *carta1=*carta2;
    *carta2=temp;
}

/*procedura per mischiare le carte con rand()
effettua la chiamata della procedura 'scambiare_carte'
e quante volte mischiare (variabile mix) scelto dall'utente*/
void mischia_carte(Carta_Nap *mazzo, int n_carte, int mix)
{
    int k, p, q;

    for(k=1; k<=n_carte*mix; k++)
    {
        p=rand()%n_carte;
        q=rand()%n_carte;
        scambiare_carte(&mazzo[p], &mazzo[q]);
    }
}


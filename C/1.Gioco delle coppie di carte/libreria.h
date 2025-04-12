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


//prototipi delle procedure

//Prototipo per mischiare le carte
void mischia_carte(Carta_Nap *, int, int);

//Prototipo per scambiare le carte serve asse portante per mischiare_carte
void scambiare_carte(Carta_Nap *, Carta_Nap *);

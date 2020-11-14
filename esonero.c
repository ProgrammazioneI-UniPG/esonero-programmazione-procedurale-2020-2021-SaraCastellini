#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>


int main() {
char chiave[130];  //chiave inserita da tastiera
int Lchiave;
unsigned char chiave_finale[130];
char testo_dopo_cifratura[130];
time_t t;


char testo[130]; //primo testo inserito da tastiera
printf("inserisca un testo con lunghezza max 128 caratteri, oltre il limite i caratteri saranno scartati\n");
fgets(testo, 130, stdin); //inserisco una stringa da tastiera

int ch;                                          //svuoto il buffer
while((ch = getchar()) != '\n' && ch != EOF);

int Ltesto;
Ltesto = (strlen(testo)-1); //calcolo solamente il numero dei caratteri inseriti
printf("la lunghezza del testo inserito è: %d\n", Ltesto);
printf("il testo inserito è: %s\n", testo);
printf("adesso ha due possibilità,scegliendo 1 la chiave dovrà essre inserita manualmte, digitando 2 la chiave sarà generata automaticamente\n");

int s; //scelta dell'utente per generare la chiave
scanf("%d", &s);
int c;                                          //svuoto il buffer
while((c = getchar()) != '\n' && c != EOF);

//caso in cui l'utente sceglie di inserire manualmente la chiave
if(s==1) {
  int c;                                          //svuoto il buffer
  while((c = getchar()) != '\n' && c != EOF);
do {
  printf("ha scelto di inserire manualmente la chiave, la cui lunghezza dovrà essere >= al testo precedentemente inserito\n");
  fgets(chiave, 130 , stdin);
  int c;                                          //svuoto il buffer
  while((c = getchar()) != '\n' && c != EOF);
  Lchiave = (strlen(chiave)-1); //calcolo solamente il numero dei caratteri inseriti
  printf("la chiave inserita è: %s\n", chiave);
  }
while (Lchiave < Ltesto);     //ripeto il ciclo finchè la lunghezza della chiave non sia >= a quella del testo
int n;
printf("messaggio cifratato è: ");
for ( n=0 ; n< Ltesto ; n++) {
chiave_finale[n]=testo[n]^chiave[n];                   //cifro il testo
testo_dopo_cifratura[n]=chiave_finale[n]^chiave[n];    //verifico che la cfratura del testo sia avvenuta correttamente
printf("%X", chiave_finale[n]);                        //stampo in esadecimale così da visualizzare nello schermo i caratteri speciali

}
int ch;                                          //svuoto il buffer
while((ch = getchar()) != '\n' && ch != EOF);
printf("la lunghezza della chiave inserita è: %d\n", Lchiave);
printf("la lunghezza del testo inserito è: %d\n", Ltesto);
printf("il testo inserito inizialmente e: %s\n", testo_dopo_cifratura);

}

//caso in cui l'utente sceglie di generare automaticamnete una chiave
else if (s==2) {
srand((unsigned) time(&t));
int g;
for( g=0 ; g< Ltesto; g++)
{
chiave_finale[g]=(rand() % 128);
chiave_finale[g]=testo[g]^chiave[g];                 //cifro il testo
testo_dopo_cifratura[g]=chiave_finale[g]^chiave[g];  //verifico che la cifratura del testo sia avvenuta correttamente

}
printf("il messaggio cifrato è: %s\n", chiave_finale);
printf("il testo inizialmente inserito è: %s\n", testo_dopo_cifratura);
}

//caso in cui l'utente non ha scelto nessuna delle precedenti opzioni
else
printf("non digitando ne 1 ne 2 ha scelto di terminare il programma\n");

}

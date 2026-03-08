/**
 *  INF2, Thema: Dynamische Speicherverwaltung
 *
 *  Dieses Programm soll zeigen, wie ein auf dem Heap angelegter, dynamischer
 *  Speicherbereich bei Bedarf vergroessert werden kann.
 *
 *  @version 1.0, 14.03.2017
 *  @version 1.1, 05.03.2019
 *  @author bkrt
 */

#include <stdio.h>
#include <stdlib.h>


/**
 *  Makro zum Testen, ob Speicherallokation erfolgreich war
 *
 *  Vorteil gegenueber einer Funktion: (unwesentlich) schneller, da Code
 *  direkt in die aufrufende Funktion eingebettet wird – trotzdem waere 
 *  eine Funktion hier vorzuziehen (das Makro soll hier nur als weiteres
 *  Beispiel fuer den Einsatz des Praeprozessors dienen) 
 */
#define CHECK_ALLOC(zeiger) if ((zeiger) == NULL) { \
    fprintf(stderr, "Speicher voll.\n"); \
    exit(EXIT_FAILURE); \
}

void copyArr(int arr1[], int arr2[], int n);

/**
 *  Hauptfunktion zum Einlesen der Daten
 */
int main (void) {
    
    int groesse = 5, inkrement = 3, index = 0, zahl, i, res;
    char inp[10];  // Buffer zum Einlesen der Zahlen

    // dynamisch Speicher reservieren und prüfen, ob erfolgreich
    int * zahlen = malloc(groesse * sizeof(int));
    CHECK_ALLOC(zahlen)
    
    do {
        // Zahl einlesen
        printf("Naechste Zahl: ");
        fgets(inp, 10, stdin);
        res = sscanf(inp,"%i", &zahl);
        if (res != 1) {
            fprintf(stderr, "Keine Zahl!\n");
            continue;
        }

        // Zahl abspeichern
        if (zahl != -1) {
            
            // Array voll?
            if (index >= groesse) {
                printf("Array wird vergrösster\n");
                int * store_array = malloc(groesse * sizeof(int));
                copyArr(zahlen, store_array, groesse);
                groesse += 3;
                zahlen = realloc(groesse * sizeof(int));
                copyArr(store_array, zahlen, groesse);
            }
            
            zahlen[index] = zahl;
            index += 1;
        }
        
        // Zahlen ausgeben
        for (i = 0; i<index; i+=1) {
            printf("%d ", zahlen[i]);
        }
        printf("\n");
    }
    while (zahl != -1);
    
    free(zahlen);
    return 0;
}

void copyArr(int arr1[], int arr2[], int n) {
    for (int i = 0; i < n; i++) {

        // Copy each element one by one
        arr2[i] = arr1[i];
    }
}


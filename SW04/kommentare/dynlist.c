/**
 *  INF2, Thema: Dynamische verkettete Listen
 *
 *  @version 17.03.2017    
 *  @author  bkrt    
 */

#include <stdio.h>
#include <stdlib.h>

// define DEBUG(code) /* */
#define DEBUG(code) code


/**
 *  Datenstruktur, die eine Zahl und einen Zeiger zur naechsten Zahl
 *  (bzw. zur Datenstruktur mit der naechsten Zahl) speichert
 */
struct Item {
    int value;
    struct Item *next;
};


/**
 *  Funktion zum Testen, ob Speicherallokation erfolgreich war
 */
void checkAlloc (struct Item *item) {
    if (item == NULL) { 
        fprintf(stderr, "Out of memory!\n");
        exit(EXIT_FAILURE);
    }
}


/**
 *  Dynamische Liste anlegen
 *  Genau genommen wird ein Anker-Element angelegt, an das die 
 *  Listenelemente dann angehaengt werden; ein Zeiger auf dieses
 *  Anker-Element wird zurueckgegeben
 */
struct Item * makeItemList (void) {
    struct Item *anchor = malloc(sizeof(struct Item));
    checkAlloc(anchor);
    anchor->value = 0;
    anchor->next = NULL;
    return anchor;
}


/**
 *  Element zur Liste hinzufuegen
 *
 *  In dieser Version wird das neue Element hinten an die Liste
 *  angehaengt
 */
void addItem (struct Item *list, int number) {
    struct Item *curr = list;

    // Ende der Liste suchen
    while (curr->next != NULL) {
        curr = curr->next;
    }
    // neues Element anlegen und initialisieren 
    struct Item *newItem = malloc(sizeof(struct Item));
    checkAlloc(newItem);
    newItem->value = number;
    newItem->next = NULL;
    
    // in Liste einhaengen
    curr->next = newItem;
}


/**
 *  Listenelemente ausgeben
 *
 *  Die Funktion hangelt sich von Element zu Element, bis am Ende der
 *  Liste der Nullpointer gefunden wird
 */
void printItems (struct Item *list) {
    struct Item *curr = list;
    while (curr->next != NULL) {
        printf("%d ", curr->next->value);
        curr = curr->next;
    }
    printf("\n");
}


/**
 *  Listenspeicher wieder freigeben
 *
 */
void freeItems (struct Item *list) {
    struct Item *curr = list, *temp;
    while (curr != NULL) {
        temp = curr;
        curr = curr->next;
        DEBUG(printf("freeing %d\n", temp->value));
        free(temp);
    }
}


/**
 *  Hauptfunktion mit Einlesen der Daten
 */
int main (void) {
    
    int num, res;
    char inp[10];  // Buffer zum Einlesen der Zahlen
    
    struct Item *list = makeItemList();

    do {
        // Zahl einlesen
        printf("Next: ");
        fgets(inp, 10, stdin);
        res = sscanf(inp,"%i", &num);
        if (res != 1) {
            fprintf(stderr, "Not a number!\n");
            continue;
        }

        // Zahl abspeichern
        if (num != -1) {
            addItem(list, num);
        }
        
        // Zahlen ausgeben
        printItems(list);
    }
    while (num != -1);
    
    freeItems(list);
    return 0;
}

/**
 *  RankingList
 *  INF2-Praktikum
 *
 *  @author: tham, ZHAW
 *  kleinere Anpassungen: bkrt
 *
 *  @version 24.02.2019  
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_LEN   32
#define LIST_LEN 100


typedef struct Participant_s {
    char first[STR_LEN];
    char name[STR_LEN];
    int  rang;
    struct Participant_s* next;
} Participant;

void checkAlloc (Participant *participant) {
    if (participant == NULL) { 
        fprintf(stderr, "Out of memory!\n");
        exit(EXIT_FAILURE);
    }
}

Participant * makeParticipantList (void) {
    Participant *anchor = malloc(sizeof(Participant));
    checkAlloc(anchor);
    anchor->first[0] = '\0';
    anchor->name[0] = '\0';
    anchor->rang = -1;
    anchor->next = NULL;
    return anchor;
}

void addParticipant (Participant *list, char *participantRead) {
    Participant *curr = list;
    char *first;
    char *name;
    int rang;
        
    first = strtok(participantRead, ";\n");
    name  = strtok(NULL, ";\n");
    rang = atoi(strtok(NULL, ";\n"));

    while (curr->next != NULL /*&& rang > curr->next->rang*/ ) {
        //printf("Rang: %d\n", rang);
        curr = curr->next;
    }
    Participant *newParticipant = malloc(sizeof(Participant));
    checkAlloc(newParticipant);

    strcpy(newParticipant->first, first);
    strcpy(newParticipant->name, name);
    newParticipant->rang = rang;
    newParticipant->next = curr->next;

    curr->next = newParticipant;
}


/**
 *  displayCSVRankingList
 *  CSV-Datei einlesen und auf der Konsole ausgeben
 *
 *  @param filename     Name der CSV-Datei
 */
void displayCSVRankingList (const char *filename) {
    char buffer[STR_LEN];
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "*** open of %s failed ***\n", filename);
        return;
    }
    while (fgets(buffer, STR_LEN, fp) != NULL) {
        printf("%s", buffer);
    }
    fclose(fp);
}


/**
 *  readCSVRankingList
 *  CSV-Datei einlesen und zwischenspeichern
 *
 *  @param filename     Name der CSV-Datei
 *  @param list         Array, in dem die Werte gespeichert werden sollen
 *  @return             Anzahl gelesener Datensaetze
 */
void readCSVRankingList (const char *filename, int *length, Participant *list) {
    int  num = 0;
    char buffer[STR_LEN];
    char *str;
    FILE *fp;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "*** open of %s failed ***\n", filename);
        return;
    }

    while (fgets(buffer, STR_LEN, fp) != NULL) {
        addParticipant(list, buffer);
    }
    fclose(fp);

    *length=num;
}


/**
 *  displayRankingList
 *  gespeicherte Daten auf der Konsole ausgeben
 *
 *  @param list         Array, in dem die Werte gespeichert sind
 *  @param length       Anzahl der Datensaetze
 */
void displayRankingList (Participant *list) {
        Participant *curr = list;
        while (curr->next != NULL) {
            printf("%s ", curr->next->first);
            printf("%s ", curr->next->name);
            printf("%d ", curr->next->rang);
            curr = curr->next;
            }
         printf("\n");
}


/**
 *  storeRankingList
 *  gespeicherte Daten in eine Datei ausgeben
 *
 *  @param filename     Name der Ausgabe-Datei
 *  @param list         Array, in dem die Werte gespeichert sind
 *  @param length       Anzahl der Datensaetze
 */
void storeRankingList (const char *filename, Participant *list, int length) {
    FILE *fp;

    fp = fopen(filename, "w");
    if (fp == NULL) {
        fprintf(stderr, "*** open of %s failed ***\n", filename);
        return;
    }
    int i = 0;
    for (i = 0; i < length; i++) {
        fprintf(fp, "%-8s %-8s: Rang %2d\n", 
            list[i].first, list[i].name, list[i].rang);
    }
    fflush(fp);
    fclose(fp);
}


/**
 *  writeRankingList
 *  gespeicherte Daten im Binaerformat in eine Datei speichern
 *
 *  @param filename     Name der Ausgabe-Datei
 *  @param list         Array, in dem die Werte gespeichert sind
 *  @param length       Anzahl der Datensaetze
 */
void writeRankingList (const char *filename, Participant *list, int length) {
    FILE *fp;
    fp = fopen(filename, "wb");
    
    if (fp == NULL) {
        fprintf(stderr, "*** open of %s failed ***\n", filename);
        return;
    }
    
    fwrite((void *)list, sizeof(Participant), length, fp);
    fflush(fp);
    fclose(fp);
}


/**
 *  readRankingList
 *  Daten im Binaerformat aus Datei lesen
 *
 *  @param filename     Name der Ausgabe-Datei
 *  @param list         Array, in dem die Werte gespeichert werden sollen
 *  @return             Anzahl der Datensaetze
 */
Participant * readRankingList (const char *filename, int *length) {
    FILE *fp;
    fp = fopen(filename, "rb");
    
    if (fp == NULL) {
        fprintf(stderr, "*** open of %s failed ***\n", filename);
        return 0;
    }
    
    //length = fread((void *)list, sizeof(Participant), LIST_LEN, fp);
    
    //  alternativ koennte man auch einen Datensatz nach dem anderen lesen
    //  und abspeichert: jeweils den Inhalt der Groesse eines Datensatzes 
    //  von der Datei lesen und ab dem Pointer speichern; dieser wird dazu 
    //  an die jeweilige Position im Array gesetzt:
        
    //    while (fread(list, size, 1, fp) > 0) {
    //        length+=1;
    //        list += size;
    //    }
    
    fclose(fp);
    return NULL;
}


/**
 *  clearRankingList
 *  gespeicherte Datensaetze loeschen
 *
 *  @param list         Array, in dem die Werte gespeichert sind
 *  @param length       Zeiger auf Anzahl der Datensaetze
 */
Participant * clearRankingList (Participant *list) {
    Participant *curr = list, *temp;
    while (curr != NULL) {
        temp = curr;
        curr = curr->next;
        printf("freeing %d\n", temp->rang);
        free(temp);
    }
    return list;
}


/**
 *  getMenuSelection
 *  Menueauswahl
 *
 *  @return             ausgewaehlter Menuepunkt
 */
int getMenuSelection (void) {
    char input[STR_LEN];
    int  retval;
    printf("\nRanglisten-Verwaltung\n\n");
    printf("  0) Rangliste aus CSV Datei ausgeben\n");
    printf("  1) Rangliste aus CSV Datei einlesen\n");
    printf("  2) Rangliste ausgeben \n");
    printf("  3) Rangliste in Textdatei speichern\n");
    printf("  4) Rangliste in Binaerdatei speichern\n");
    printf("  5) Rangliste von Binaerdatei lesen\n");
    printf("  6) Rangliste loeschen\n");
    printf("  7) Programm beenden\n");
    printf("\n> ");
    input[0] = '\0';
    fgets(input, STR_LEN, stdin);
    retval = (int)(input[0] - '0');
    return retval;
}


/**
 *  main-Funktion
 */
int main (void) {
    //Participant rankingList[LIST_LEN];
    int  length = 0, running = 1;
    int  selection;
    Participant *participantList = makeParticipantList();

    while (running) {
        selection = getMenuSelection();
        switch (selection) {
            case 0  : displayCSVRankingList("listeWin.csv");
                      break;
            case 1  : readCSVRankingList("listeWin.csv", &length, participantList);
                      break;
            case 2  : displayRankingList(participantList);
                      break;
            case 3  : storeRankingList("listeWin.txt", participantList, length);
                      break;
            case 4  : writeRankingList("listeWin.bin", participantList, length);
                      break;
            case 5  : participantList = readRankingList("listeWin.bin", &length);
                      break;
            case 6  : participantList = clearRankingList(participantList);
                      break;
            case 7  : running = 0;
                      break;
            default : break;
        }
    }
    return 0;
}

//*****************************************************************************


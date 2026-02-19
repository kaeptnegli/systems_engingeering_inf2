//*****************************************************************************
// Inf2, Praktikum 1
// tham, ZHAW
//*****************************************************************************

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_LEN   32
#define LIST_LEN 100

typedef struct Participant {
    char first[STR_LEN];
    char name[STR_LEN];
    int  rank;
} Participant;

//-----------------------------------------------------------------------------
// Parameter:     Filename
// Rueckgabewert: keiner

int displayCSVRankingList(const char *filename) {
    FILE *fp;
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return 1;
    }

    char string_buffer[100];

    while (fscanf(fp, "%s", string_buffer) == 1){
        printf("%s\n", string_buffer);
    }
    fclose(fp);
    return 0;
}

//-----------------------------------------------------------------------------
// Parameter:     Filename, Teilnehmerliste (Array of Strcuts)
// Rueckgabewert: Anzahl Teilnehmer

int readCSVRankingList(const char *filename, Participant *list, int *length) {
   FILE *fp;
   fp = fopen(filename, "r");
   int linesCount=0;
   char string_buffer[100];

   if (fp == NULL) {
       printf("Error opening file %s\n", filename);
       return 1;
   }

   while(fgets(string_buffer, sizeof(string_buffer), fp) != NULL){
       char *token;

       // First name
        token = strtok(string_buffer, ";");
        if (token != NULL)
            strcpy(list[linesCount].first, token);

        // Last name
        token = strtok(NULL, ";");
        if (token != NULL)
            strcpy(list[linesCount].name, token);

        // Rank
        token = strtok(NULL, ";");
        if (token != NULL)
            list[linesCount].rank = atoi(token);

       linesCount++;
   }

   fclose(fp);
   
   *length=linesCount;
   
   return 0;
}

//-----------------------------------------------------------------------------
// Parameter:     Teilnehmerliste (Array of Strcuts), Länge der Liste
// Rueckgabewert: keiner

void displayRankingList(Participant *list, int *length) {
   for(int i = 0; i < *length; i++) {
      printf("%s", list[i].first);
      printf("%s", list[i].name);
      printf("%d", list[i].rank);
   }
}

//-----------------------------------------------------------------------------
// Parameter:     Filename, Teilnehmerliste (Array of Strcuts), Länge der Liste
// Rueckgabewert: keiner

void storeRankingList(const char *filename, Participant *list, int length) {
}


//-----------------------------------------------------------------------------
/*void writeRankingList(const char *filename, Participant *list, int length) {
}*/

/*int readRankingList(const char *filename, Participant *list) {
}*/

//-----------------------------------------------------------------------------
// Parameter:     Teilnehmerliste (Array of Strcuts), Zeiger auf Länge der Liste
// Rueckgabewert: keiner

void clearRankingList(Participant *list, int *length) {
    for(int i = 0; i < *length; ++i){
        list[i].first[0] = '\0';   // empty string
        list[i].name[0] = '\0';   // empty string
        list[i].rank = 1;
    }
    *length = 0;
}

int getMenuSelection(void) {
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

    input[0] = '\0';                    // set string to empty
    fgets(input, STR_LEN, stdin);
    retval = (int)(input[0] - '0');     // convert ASCII to decimal

    return retval;

}

int main (void) {
    Participant rankingList[LIST_LEN];
    int  length, running = 1;
    int  selection;

    //length = STR_LEN;
    clearRankingList(rankingList, &length);

    while (running) {
        selection = getMenuSelection();
        switch (selection) {
            case 0  : displayCSVRankingList("listeWin.csv");
                      break;
            case 1  : readCSVRankingList("listeWin.csv", rankingList, &length);
                      break;
            case 2  : displayRankingList(rankingList, &length);
                      break;
            case 3  : //storeRankingList("listeWin.txt", rankingList, length);
                      break;
            case 4  : //writeRankingList("listeWin.bin", rankingList, length);
                      break;
            case 5  : //length = readRankingList("listeWin.bin", rankingList);
                      break;
            case 6  : clearRankingList(rankingList, &length);
                      break;
            case 7  : running = 0;
                      break;
            default : break;
        }
    }
    return 0;
}

//*****************************************************************************


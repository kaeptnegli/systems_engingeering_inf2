/**
 *  INF2, Thema: Dynamische verkettete Listen
 *
 *  @version 13.03.2020    
 *  @author  bkrt    
 */

#include <stdio.h>
#include <stdlib.h>

// define DEBUG(code) /* */
#define DEBUG(code) code


struct Item {
    int value;
    struct Item *next;
};

void checkAlloc (struct Item *item) {
    if (item == NULL) { 
        fprintf(stderr, "Out of memory!\n");
        exit(EXIT_FAILURE);
    }
}

struct Item * makeItemList (void) {
    struct Item *anchor = malloc(sizeof(struct Item));
    checkAlloc(anchor);
    anchor->value = 0;
    anchor->next = NULL;
    return anchor;
}

void addItem (struct Item *list, int number) {
    struct Item *curr = list;
    while (curr->next != NULL && number > curr->next->value ) {
        printf("number: %d\n", number);
        curr = curr->next;
    }
    struct Item *newItem = malloc(sizeof(struct Item));
    checkAlloc(newItem);
    newItem->value = number;
    newItem->next = curr->next;
    curr->next = newItem;
}

void printItems (struct Item *list) {
    struct Item *curr = list;
    while (curr->next != NULL) {
        printf("%d ", curr->next->value);
        curr = curr->next;
    }
    printf("\n");
}

void freeItems (struct Item *list) {
    struct Item *curr = list, *temp;
    while (curr != NULL) {
        temp = curr;
        curr = curr->next;
        DEBUG(printf("freeing %d\n", temp->value));
        free(temp);
    }
}

int main (void) {
    
    int num, res;
    char inp[10];
    
    struct Item *list = makeItemList();

    do {
        printf("Next: ");
        fgets(inp, 10, stdin);
        res = sscanf(inp,"%i", &num);
        if (res != 1) {
            fprintf(stderr, "Not a number!\n");
            continue;
        }
        if (num != -1) {
            addItem(list, num);
        }
        printItems(list);
    }
    while (num != -1);
    
    freeItems(list);
    return 0;
}

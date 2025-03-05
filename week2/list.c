#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct node {
    int value;
    struct node *next;
};

struct node *listAdd(int value) {
    struct node *new = malloc(sizeof(struct node));
    new->value = value;
    new->next = NULL;
    return new;
}

void printList(struct node *list) {
    for (struct node *curr = list; curr != NULL; curr = curr->next) {
        printf("%d ", curr->value);
    }
	printf("\n");
}

int listLength(struct node *l) {
    if (l == NULL) { // base case
        return 0;
    }

    // recursive case
    return 1 + listLength(l->next);
}

int listCountOdds(struct node *l) {
    if (l == NULL) {
        //base case
        return 0;

    } else {
        //recursive case
        if (l->value % 2 != 0) {
            // odd number
            return 1 + listCountOdds(l->next);

        } else {
            // even number
            return listCountOdds(l->next);
        }
    }
}

bool listIsSorted(struct node *l) {
    // empty list is 'sorted'
    if (l == NULL) {
        return true;
    }

    // Single node, is sorted
    if (l->next == NULL) {
        return true;
    }

    // exit if list is unsorted at this point
    if (l->value > l->next->value) {
        return false;
    }

    // otherwise we need to verify the rest of the list
    return listIsSorted(l->next);
}

struct node *listDelete(struct node *l, int value) {
    // base case
    if (l == NULL) {
        return NULL;
    }

    if (l->value == value) {
        // if this is the node to delete
        struct node *newNext = l->next;
        free(l);
        return newNext;

    } else {
        // if this not the node to delete
        l->next = listDelete(l->next, value);
        return l;
    }
}

int main(void) {
    // simple linked list
    // 1 -> 4 -> 7 -> 9 -> 13 -> X

    int numbers[5] = {1, 4, 7, 9, 13};

    struct node *list = listAdd(numbers[0]);
    struct node *curr = list;
    for (int i = 1; i < 5; i++) {
        curr->next = listAdd(numbers[i]);
        curr = curr->next;
    }
    printList(list);

    printf("Length of list is %d\n", listLength(list));

    printf("Number of Odds in list is %d\n", listCountOdds(list));

    printf("Is list sorted? %s\n", listIsSorted(list) ? "true" : "false");

	listDelete(list, 7);
	printList(list);

    listDelete(list, 10);
	printList(list);

    return 0;
}

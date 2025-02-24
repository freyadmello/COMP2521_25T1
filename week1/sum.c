#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *next;
};

struct node *addNode(struct node *list, int v);
int sumList(struct node *list);
struct node *listDelete(struct node *list, int value);
void print(struct node *list);

int main(void) {
	
    // Make list
    struct node *list = NULL;
    list = addNode(list, 1);
    list = addNode(list, 3);
    list = addNode(list, 5);
    list = addNode(list, 9);
    print(list);
    
    int sum = sumList(list);
    printf("Sum of the list is %d\n", sum);

    list = listDelete(list, 1);
    print(list);

    listDelete(list, 6);
    print(list);
}

void print(struct node *list) {
    for (struct node *curr = list; curr != NULL; curr = curr->next) {
        printf("%d ", curr->value);
    }
    printf("\n");
}

struct node *addNode(struct node *list, int v) {
    struct node *new = malloc(sizeof(struct node));
    new->next = list;
    new->value = v;
    return new;
}

int sumList(struct node *list) {

    int sum = 0;

    
    for (struct node *current = list; current != NULL; current = current->next) {
        sum += current->value;
    }

    return sum;
}

struct node *listDelete(struct node *list, int value) {
    
    // empty
    if (list == NULL) {
        return list;
    }

    // head of list
    if (list->value == value) {
        struct node *newHead = list->next;
        list->next = list->next->next;
        free(list);
        return newHead;
    }

    // otherwise we want to go through the rest of the list
    for (struct node *curr = list; curr->next != NULL; curr = curr->next) {

        if (curr->next->value == value) {
            struct node *toDelete = curr->next;
            curr->next = toDelete->next;
            free(toDelete);
            break;
        }

    }

    return list;
}

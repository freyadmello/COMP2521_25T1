#include "Stack.h"
#include <stdlib.h>

typedef struct queue *Queue;

struct queue {
	Stack s1;
	Stack s2;
};

Queue QueueNew(void) {
	Queue q = malloc(sizeof(struct queue));
	q->s1 = StackNew();
	q->s2 = StackNew();
	return q;
}

void QueueFree(Queue q) {
	StackFree(q->s1);
	StackFree(q->s2);
	free(q);
}

void QueueEnqueue(Queue q, int item) { // O(1)
	StackPush(q->s1, item);
}

int QueueDequeue(Queue q) { // O( n )
	while (StackSize(q->s1) > 1) { // (n - 1)
		// Transfer to other stack
		int item = StackPop(q->s1);
		StackPush(q->s2, item);
	}

	// Get next item
	int dequeuedItem = StackPop(q->s1); // (1)

	while (StackSize(q->s2) > 0) { // (n - 1)
		// restore all nodes to original stack
		int item = StackPop(q->s2);
		StackPush(q->s1, item);
	}

	return dequeuedItem;
}

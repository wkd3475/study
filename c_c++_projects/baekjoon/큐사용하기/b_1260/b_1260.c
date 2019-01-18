#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct QueueNode {
    int n;
    struct QueueNode *prev;
    struct QueueNode *next;
};

struct Queue {
    struct QueueNode *head;
    struct QueueNode *tail;
    int size;
};

struct Stack {
    struct StackNode *top;
    int size;
};

struct StackNode {
    int n;
    struct StackNode *prev;
};

void initQueue(struct Queue *queue);
void enqueue(struct Queue *queue, int x);
int dequeue(struct Queue *queue);
int sizeQueue(struct Queue *queue);
int isEmptyQueue(struct Queue *queue);
int frontQueue(struct Queue *queue);
int backQueue(struct Queue *queue);

void initStack(struct Stack *stack);
void push(struct Stack *stack, int x);
int isEmptyStack(struct Stack *stack);
int pop(struct Stack *stack);
int sizeStack(struct Stack *stack);
int topStack(struct Stack *stack);

int main() {
    struct Queue *queue;
    initQueue(queue);
    struct Stack *stack;
    initStack(stack);

    int N, M, V;
    scanf("%d %d %d", &N, &M, &V);
    
    return 0;
}

void initQueue(struct Queue *queue) {
    queue = (struct Queue*)malloc(sizeof(struct Queue*));
    queue->size=0;
    queue->head=NULL;
    queue->tail=NULL;
}

void enqueue(struct Queue *queue, int x) {
    struct QueueNode *node = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    
    node->n = x;
    node->prev = queue->tail;
    node->next = NULL;
    
    if(isEmpty(queue)) {
        queue->head = node;
    }
    else {
        queue->tail->next = node;
    }
    queue->tail = node;
    queue->size++;
}

int dequeue(struct Queue *queue) {
    int val;
    if(isEmpty(queue)) return -1;
    else if(size(queue)==1) {
        val = queue->head->n;
        queue->head = NULL;
        queue->tail = NULL;
        queue->size --;
    }
    else {
        val = queue->head->n;
        queue->head = queue->head->next;
        queue->size --;
    }

    return val;
}

int sizeQueue(struct Queue *queue) {
    return queue->size;
}

int isEmptyQueue(struct Queue *queue) {
    if(queue->size==0) return 1;
    else return 0;
}

int frontQueue(struct Queue *queue) {
    if(isEmpty(queue)) return -1;
    else return queue->head->n;
}

int backQueue(struct Queue *queue) {
    if(isEmpty(queue)) return -1;
    else return queue->tail->n;
}

void initStack(struct Stack *stack) {
    stack = (struct Stack*)malloc(sizeof(struct Stack*));
    stack->size = 0;
    stack->top = NULL;
}

void push(struct Stack *stack, int x) {
    struct StackNode *node;
    node = malloc(sizeof(struct StackNode));
    node->n = x;
    node->prev = stack->top;
    stack->top = node;
    stack->size ++;
}

int isEmptyStack(struct Stack *stack) {
    if(stack->size > 0) return 0;
    else return 1;
}

int pop(struct Stack *stack) {
    if(!empty(stack)) {
        int n = stack->top->n;
        stack->top = stack->top->prev;
        stack->size --;
        return n;
    }
    else return -1;
}

int sizeStack(struct Stack *stack) {
    return stack->size;
}

int topStack(struct Stack *stack) {
    if(empty(stack)) return -1;
    else {
        return stack->top->n;
    }
}
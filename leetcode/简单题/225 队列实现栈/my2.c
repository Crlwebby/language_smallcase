#define SIZE 20
typedef struct {
    int *data;
    int size;
    int head;
    int tail;
}Queue;

typedef struct {
    Queue *queue1,*queue2;
} MyStack;

/** Initialize your data structure here. */
Queue* myQueueInit(int k){
    Queue* temp = (Queue*)malloc(sizeof(Queue));
    temp->data = (int*)malloc(sizeof(int) * k);
    temp->head=temp->tail=0;
    temp->size = k;
    return temp;
}

int push(Queue* obj, int x){
    if((obj->tail + 1)%obj->size == obj->head)
        return 0;
    obj->data[obj->tail++] = x;
    obj->tail %= obj->size;
    return 1;
}

int pop(Queue* obj){
    if(obj->head == obj->tail)
        return 0;
    int temp = obj->data[obj->head++];
    obj->head %= obj->size;
    return temp; 
}
bool myQueueEmpty(Queue* obj){
    return obj->head == obj->tail;
}
bool myQueueFull(Queue* obj){
    return (obj->tail + 1)%obj->size == obj->head;
}

MyStack* myStackCreate() {
    MyStack *stack = (MyStack*)malloc(sizeof(MyStack));
    stack->queue1 = myQueueInit(SIZE);
    stack->queue2 = myQueueInit(SIZE);
    return stack;
}

/** Push element x onto stack. */
int myStackPush(MyStack* obj, int x) {
    if(myQueueFull(obj->queue1)){
        return 0;
    }
    push(obj->queue2,x);
    while(!myQueueEmpty(obj->queue1)){
        push(obj->queue2,pop(obj->queue1));
    }
    Queue *temp = obj->queue1;
    obj->queue1 = obj->queue2;
    obj->queue2 = temp;
    return 1;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    if(myQueueEmpty(obj->queue1))
        return 0;
    return pop(obj->queue1);
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    if(myQueueEmpty(obj->queue1))
        return 0;
    return obj->queue1->data[obj->queue1->head];
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return myQueueEmpty(obj->queue1);
}

void myStackFree(MyStack* obj) {
    free(obj->queue1->data);
    free(obj->queue1);
    free(obj->queue2->data);
    free(obj->queue2);
    free(obj);
}

//最后还是用C写了一遍队列，然后用队列实现栈，差点没把我累死……还好debug完成后样例一遍过，海星
//一个栈实现的应该就看看原理，不写了……太麻烦了
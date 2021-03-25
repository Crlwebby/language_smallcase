#define SIZE 20
typedef struct {
    int *data;
    int esp;
    int length;
} Stack;

Stack* Init(int length){
    Stack* temp = (Stack *)malloc(sizeof(Stack));
    temp->data = (int *)malloc(sizeof(int) * length);
    temp->esp = -1;
    temp->length = length;
    return temp;
}
bool Full(Stack* obj){
    return obj->esp +1 == obj->length;
}
bool Empty(Stack* obj){
    return obj->esp == -1;
}
bool push(Stack* obj,int x){
    if(Full(obj))
        return 0;
    obj->data[++obj->esp] = x;
    return 1;
}

int pop(Stack* obj){
    if(obj->esp == -1)
        return 0;
    return obj->data[obj->esp--];
}

int top(Stack* obj){
    if(obj->esp == -1)
        return 0;
    return obj->data[obj->esp];
}

typedef struct {
    Stack* stack1,*stack2;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    MyQueue* temp = (MyQueue*)malloc(sizeof(MyQueue));
    temp->stack1 = Init(SIZE);
    temp->stack2 = Init(SIZE);
    return temp;
}

/** Push element x to the back of queue. */
bool myQueuePush(MyQueue* obj, int x) {
    if(Full(obj->stack1))
        return 0;
    while(!Empty(obj->stack1))
        push(obj->stack2,pop(obj->stack1));
    push(obj->stack2,x);
    while(!Empty(obj->stack2))
        push(obj->stack1,pop(obj->stack2));
    return 1;
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    return pop(obj->stack1);
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    return top(obj->stack1);
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    return Empty(obj->stack1);
}

void myQueueFree(MyQueue* obj) {
    free(obj->stack1->data);
    free(obj->stack1);
    free(obj->stack2->data);
    free(obj->stack2);
    free(obj);
}

//刚写完用队列实现栈，现在写这个当然信手拈来~只不过是简单题23333
//一遍过，感觉还是挺快乐的
//时间复杂度好像有点高？感觉就是常规思路啊，待会儿看看题解
typedef struct {
    int node[100];
    int esp;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack *stack = (MyStack*)malloc(sizeof(MyStack));
    stack->esp = -1;
    return stack;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    obj->node[++obj->esp] = x;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    return obj->node[obj->esp--];
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return obj->node[obj->esp];
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return obj->esp==-1?true:false;
}

void myStackFree(MyStack* obj) {
    while(obj->esp != -1){
        obj->node[obj->esp--]=0;
    }
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/

//怎么说呢……就C语言没有队列……也就没有了这题的精髓……当然，用数组也是大差不差啦，但是还是缺了队列的练习
//用数组单纯的实现了一下栈，比预料之中的更轻松些~
//补一个py用队列实现栈
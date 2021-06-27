int* preorder(struct Node* root, int* returnSize) {
    if(root == NULL){
        *returnSize = 0;
        return NULL;
    }
    int *result = (int *)malloc(sizeof(int) * 10000);
    struct Node **stack = (struct Node **) malloc(sizeof(struct Node *) * 10000);
    int top=0,size=0;
    stack[top++]=root;
    while(top){
        struct Node* temp = stack[top-1];
        result[size++]=stack[--top]->val;
        if(temp->numChildren == 0){
            continue;
        }
        for(int i = temp->numChildren-1; i >= 0; i--){
            stack[top++]=temp->children[i];
        }
        temp->numChildren=0;
    }
    *returnSize=size;
    return result;
}

//就是头铁不学realloc，头铁不用其它语言，硬用C，硬分配大小为一万的数组去做。。。
//有一说一，但凡有个自动扩容的栈，都不会做得这么难受……参考标答的先序遍历，写出来差强人意吧。
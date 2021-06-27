int* postorder(struct Node* root, int* returnSize) {
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
        if(temp->numChildren == 0){
            result[size++]=stack[--top]->val;
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
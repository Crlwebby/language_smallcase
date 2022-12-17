int* postorderTraversal(struct TreeNode* root, int* returnSize){
    if(root == NULL){
        *returnSize = 0;
        return NULL;
    }
    int *result = (int *) malloc(sizeof(int) * 120);
    struct TreeNode** stack = (struct TreeNode**)malloc(sizeof(struct TreeNode*)*120);
    int top = 0;
    int size = 0;
    stack[top++]=root;
    while(top){
        struct TreeNode* temp = stack[top-1];
        if(temp->left == NULL && temp->right == NULL){
            result[size++] = stack[--top]->val;
            continue;
        }
        if(temp->right != NULL){
            stack[top++]=temp->right;
            temp->right = NULL;
            //问题1，如何确定出栈条件？我这里是暴躁老哥，直接把遍历过的二叉树全销毁了……
        }
        if(temp->left !=NULL){
            stack[top++]=temp->left;
            temp->left = NULL;
        }
    }
    *returnSize = size;
    return result;
}
//还是画图简单清楚干净……自己瞎想想半天想不出来一个结果
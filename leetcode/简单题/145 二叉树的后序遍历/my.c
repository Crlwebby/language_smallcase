void postorder(struct TreeNode* root, int *result, int* returnSize){
    if(root == NULL)
        return;
    postorder(root->left,result,returnSize);
    postorder(root->right,result,returnSize);
    result[(*returnSize)++] = root->val;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize){
    int *a = (int *)malloc(sizeof(int) * 120);
    *returnSize = 0;
    postorder(root,a,returnSize);
    return a;
}

//去看看迭代咋写的，都不太记得什么是迭代了……
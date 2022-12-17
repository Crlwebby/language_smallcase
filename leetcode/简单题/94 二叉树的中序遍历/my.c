void inorder(struct TreeNode* root, int* result, int* returnSize){
    if(root == NULL)
        return;
    inorder(root->left,result,returnSize);
    result[(*returnSize)++]=root->val;
    inorder(root->right,result,returnSize);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int *result = (int *) malloc(sizeof(int) * 120);
    *returnSize = 0;
    inorder(root,result,returnSize);
    return result;
}

//趁着刚做完前序遍历，直接一鼓作气中序后序……反正一样的……
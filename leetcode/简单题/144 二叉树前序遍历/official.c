void preorder(struct TreeNode* root, int *result, int* returnSize){
    if(root == NULL)
        return;
    result[(*returnSize)++] = root->val;
    preorder(root->left,result,returnSize);
    preorder(root->right,result,returnSize);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int *a = (int *)malloc(sizeof(int) * 120);
    *returnSize = 0;
    preorder(root,a,returnSize);
    return a;
}

//=.= 说明自己完全不会考虑递归，这么简单个实现，纠结了半天，还在反复考虑calloc的事情……
//简单来说，力扣虽然与一般的从main执行的东西不同，但是你可以把它原本的主函数变成main；
//正如这个例子而言，既然直接使用全局变量不太方便，那就把原本的当作主函数，在外面再调用一个，不就方便得多了吗？
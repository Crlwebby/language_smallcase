int min(struct TreeNode* root){
    if(root->left == NULL)
        return root->val;
    else{
        return min(root->left);
    }
}
int max(struct TreeNode* root){
    if(root->right == NULL)
        return root->val;
    else{
        return max(root->right);
    }
}
bool isValidBST(struct TreeNode* root){
    if(!root->left && !root->right){
        return true;
    }
    else if(root->left && !root->right){
        return root->val > max(root->left) && isValidBST(root->left);
    }
    else if(!root->left && root->right){
        return root->val < min(root->right) && isValidBST(root->right);
    }
    else{
        return root->val < min(root->right) && root->val > max(root->left) && isValidBST(root->left) && isValidBST(root->right);
    }
}

//被坑了……哎，还是自己对二叉搜索树理解不透彻吧，忘了要大于左子树所有节点和小于右子树所有节点……
//最初只是简单判断根节点和左右子树首个节点的值就开始整递归了，然后爆了……
//么事！看见样例就懂了，加了个min和max进行最大值的判断
//显而易见！这个方法，很粗糙！而且，递归深度未免太深了，初步判断觉得可以用一个数组维护每个节点子节点的最小值和最大值，就不需要如此多次的重复遍历了=。=
//简单粗暴就好。。。自顶向下是最浅显的思路，看看大佬有没有自底向上的思路或者更NB的思路！
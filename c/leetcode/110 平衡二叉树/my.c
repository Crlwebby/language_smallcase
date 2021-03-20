int depth(struct TreeNode* root){
    if(root == NULL){
        return 0;
    }
    else{
        int left = depth(root->left);
        int right = depth(root->right);
        return 1+(left > right ? left : right);
    }
}

bool isBalanced(struct TreeNode* root){
    if(root == NULL)
        return true;
    if(abs(depth(root->left) - depth(root->right)) > 1)
        return false;
    return isBalanced(root->left) && isBalanced(root->right);
}

//心累……没想到写个判断平衡二叉树的都这么累……看来确实太久太久没接触树和图了，麻烦大了……
//总而言之就是使用递归……判断左右子树的深度，绝对值是否大于二，没有的话继续递归左右子树，然后继续算深度，深度也是用递归……
//总感觉是个很蠢的办法，想优化反复求高度这件事情，但是树的结构又不尽如人意，去看看有没有更巧妙的办法吧
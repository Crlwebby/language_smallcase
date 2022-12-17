/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void inorder(struct TreeNode* root){
    if(root == NULL){
        printf("NULL\t");
        return;
    }
    printf("%d\t",root->val);
    inorder(root->left);
    inorder(root->right);
}
struct TreeNode* trimBST(struct TreeNode* root, int low, int high){
    if(root == NULL)
        return NULL;
    if(root->val < low){
        root = root->right;
        root = trimBST(root,low,high);
    }
    else if(root->val > high){
        root = root->left;
        root = trimBST(root,low,high);
    }
    else{
        root->left = trimBST(root->left,low,high);
        root->right = trimBST(root->right,low,high);
    }
    return root;
}

//inorder是一个中序遍历，用于测试用的，不想删就留着了，不过也简单……
//由于这棵树本身就是二叉搜索树，而且不是删除任意节点，所以和想的还是有些出入
//比普通的删除节点简单，因为有一个值不符合的话，相应的左子树|右子树整个都可以不要了。。。
//就是获取返回值这种东西的时候出了偏差，没有把root->left或root->right成功更改，然后调了会儿bug，整体而言还是很简单的
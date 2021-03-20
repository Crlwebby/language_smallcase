
int height(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    if (leftHeight == -1 || rightHeight == -1 || fabs(leftHeight - rightHeight) > 1) {
        return -1;
    } else {
        return fmax(leftHeight, rightHeight) + 1;
    }
}

bool isBalanced(struct TreeNode* root) {
    return height(root) >= 0;
}

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/balanced-binary-tree/solution/ping-heng-er-cha-shu-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

//大概能理解思路，就是我递归不会写呗……
//思路是类似的，就是避免height重复计算，官方用到的递归思想就是在求高度的时候同时判断是否是平衡二叉树，如果不平衡，给一个flag=-1，标记一下然后一层层的退出递归
//height求的是单个节点的高度，肯定大于0，而如果遇见不平衡二叉树的情况，则会返回-1，因此主函数的height(root) != -1 也是可以的
//后序遍历思想，就是先左子节点，然后右子节点，然后再自己，这个过程
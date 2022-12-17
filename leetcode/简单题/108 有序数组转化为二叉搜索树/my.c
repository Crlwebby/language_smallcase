/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    if(numsSize == 0)
        return NULL;
    struct TreeNode* head = malloc(sizeof(struct TreeNode));
    int middle = numsSize / 2;
    int left_length,right_length;
    if(numsSize % 2){
        left_length = middle;
        right_length = middle;
    }
    else{
        left_length = middle;
        right_length = middle - 1;
    }
    head->val = nums[middle];
    head->left = sortedArrayToBST(nums, left_length);
    head->right = sortedArrayToBST(nums + middle + 1, right_length);
    return head;
}

//还是有点陷入细节问题了，就是陷入了边界条件的问题处理上
//奇数和偶数的情况不同，两边子树的长度是不一样的，为了处理这个东西费了一番波折，看看题解有没有什么更干净的做法吧
//噢对，也是用了递归，感觉递归分治是最容易的做法了，怎么不用递归呢？暂时还没有想到……
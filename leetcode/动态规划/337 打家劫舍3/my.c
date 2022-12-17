#include<stdio.h>
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int getMaxMoney(struct TreeNode* node) {
    int binary[1000]={0};
    struct TreeNode * my_queue[20];
    int top = 0;
    my_queue[top++] = node;
    int len = 0;
    while(top != 0){
        struct TreeNode *temp = my_queue[--top];
        binary[len++] = temp->val;
        if(temp->left != NULL){
            my_queue[top++] = temp->left;
        }else{
            binary[len++] = 0;
        }
        if(temp->right != NULL){
            my_queue[top++] = temp->right;
        }else{
            binary[len++] = 0;
        }
        printf("%d\n",top);
        for(int i = 0; i < top; i++)
            my_queue[i] = my_queue[i+1];
    }
    for(int i = 0; i < len; i++){
        printf("%d\t",binary[i]);
    }
    return 0;
}

int main(){
    struct TreeNode node1;
    node1.val = 1;
    struct TreeNode node2;
    node2.val = 2;
    struct TreeNode node3;
    node2.val = 3;
    struct TreeNode node4;
    node2.val = 4;
    node1.left=&node2;
    node1.right=&node3;
    node2.left=NULL;
    node2.right=NULL;
    node3.left=&node4;
    node3.right=NULL;
    node4.left=NULL;
    node4.right=NULL;
    int res = getMaxMoney(&node1);
    printf("%d\n",res);

    return 0;
    
}
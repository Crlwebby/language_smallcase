#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x),left(NULL),right(NULL){}
};
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
        if(inorder.empty())
            return NULL;
        static int i=0;
            TreeNode* Final;
            Final=new TreeNode(preorder[i]);
            vector<int>::iterator j;
            for(j=inorder.begin();j!=inorder.end();j++){
                if(*j==preorder[i])
                    break;
            }
            ++i;
            vector<int> left;
            vector<int> right;
            for(int t=0;inorder[t]!=*j;t++){
                left.push_back(inorder[t]);
            }
            for(vector<int>::iterator t=j+1;t!=inorder.end();t++){
                right.push_back(*t);
            }
            Final->left=buildTree(preorder,left);
            Final->right=buildTree(preorder,right);
            return Final;
    }
};
int main()
{
    vector<int> preorder;
    vector<int> inorder;
    int t;
    cin>>t;
    while(t!=-10){
        preorder.push_back(t);
        cin>>t;
    }
    cin>>t;
    while(t!=-10){
        inorder.push_back(t);
        cin>>t;
    }
    Solution Tree;
    TreeNode* team=Tree.buildTree(preorder,inorder);
    queue<TreeNode*> traverse;
    traverse.push(team);
    while(!traverse.empty()){
        TreeNode* temp=traverse.front();
        traverse.pop();
        if(temp->left!=NULL)
            traverse.push(temp->left);
        if(temp->right!=NULL)
            traverse.push(temp->right);
        cout<<temp->val<<"  ";
    }
    return 0;
}

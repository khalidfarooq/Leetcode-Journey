/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    
public:
    int res = 0;
    void preorder(TreeNode *root, int currNum){
        if(root != NULL){
            currNum = (currNum << 1) | root->val;
            if(root->left == NULL && root->right == NULL){
                res += currNum;
            }
            
            preorder(root->left, currNum);
            preorder(root->right, currNum);
        }
    }
    
    int sumRootToLeaf(TreeNode* root) {
        preorder(root,0);
        return res;
    }
};
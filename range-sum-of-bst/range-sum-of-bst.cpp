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
    bool inRange(int data, int low, int high){
        return (data>=low && data<= high) ? true : false;
    }
    int dfs(TreeNode* root, int low, int high){
        if(root == NULL) return res;
        if(inRange(root->val,low,high)){
            res += root->val;
        }
        
        dfs(root->left,low,high);
        dfs(root->right,low,high);
        return res;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        dfs(root,low,high);
        return res;
    }
};
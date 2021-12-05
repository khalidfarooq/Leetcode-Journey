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
    vector<int> dfs(TreeNode* root){
        
        if(root == NULL) return {0,0};
        
        
        vector<int> leftPair = dfs(root->left);
        vector<int> rightPair = dfs(root->right);
        
        int withRoot = root->val + leftPair[1] + rightPair[1];
        int withoutRoot = max(leftPair[0], leftPair[1]) + max(rightPair[0],rightPair[1]);
        
        return {withRoot, withoutRoot};
        
    }
    
    int rob(TreeNode* root) {
        vector<int>res(2);
        
        res = dfs(root);
        
        return max(res[0],res[1]);
    }
};
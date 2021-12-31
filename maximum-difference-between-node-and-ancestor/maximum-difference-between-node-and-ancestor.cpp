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
    int result;
    int maxAncestorDiff(TreeNode* root) {
        if(root == NULL) return 0;
        result = 0;
        helper(root,root->val,root->val);
        return result;
    }
    void helper(TreeNode* root, int currMax, int currMin){
        if(root == NULL) return;
        
        int currRes = max(abs(currMax - root->val) , abs(currMin - root->val));
        result = max(result, currRes);
        currMax = max(currMax, root->val);
        currMin = min(currMin, root->val);
        
        helper(root->left, currMax, currMin);
        helper(root->right, currMax, currMin);
        return ;
    }
};
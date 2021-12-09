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
    void dfs(TreeNode* root, vector<int>&curr_path, vector<vector<int>>&all_paths, int req_sum){
        if(!root) return;
        curr_path.push_back(root->val);
        if(root->left == NULL && root->right == NULL && req_sum == root->val)
            all_paths.push_back(curr_path);
        
        dfs(root->left, curr_path, all_paths, req_sum-root->val);
        dfs(root->right, curr_path, all_paths, req_sum-root->val);
        
        curr_path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>curr_path;
        vector<vector<int>>all_paths;
        dfs(root,curr_path,all_paths,targetSum);
        return all_paths;
    }
};
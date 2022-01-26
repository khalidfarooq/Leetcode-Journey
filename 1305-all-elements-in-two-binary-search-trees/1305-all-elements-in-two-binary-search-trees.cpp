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
    vector<int>res;
    void h2(TreeNode *r){
        if(r == NULL) return;
        h1(r->left);
        res.push_back(r->val);
        h1(r->right);
        
        return;
    }
    void h1(TreeNode *r){
        if(r == NULL) return;
        h1(r->left);
        res.push_back(r->val);
        h1(r->right);
        
        return;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
        h1(root1);
        h2(root2);
        sort(begin(res), end(res));
        return res;
    }
};
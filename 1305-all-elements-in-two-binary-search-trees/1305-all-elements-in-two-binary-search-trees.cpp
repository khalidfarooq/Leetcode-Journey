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
    
//     void dfs(TreeNode *r){
//         if(r == NULL) return;
//         dfs(r->left);
//         res.push_back(r->val);
//         dfs(r->right);
        
//         return;
//     }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode *>s1,s2;
        if(root1 == NULL && root2 == NULL) return res;
        
        TreeNode * r1 = root1;
        TreeNode * r2 = root2;
        while(!s1.empty() || !s2.empty() || r1 != NULL || r2 != NULL){
            while(r1 != NULL){
                s1.push(r1);
                r1 = r1->left;
            }
            while(r2 != NULL){
                s2.push(r2);
                r2 = r2->left;
            }
            int x = (!s1.empty()) ? s1.top()->val : INT_MAX;
            int y = (!s2.empty()) ? s2.top()->val : INT_MAX;
            
            if(x < y){
                res.push_back(x);
                r1 = s1.top()->right;
                s1.pop();
            }else{
                res.push_back(y);
                r2 = s2.top()->right;
                s2.pop();
            }
        }
        
        // dfs(root1);
        // dfs(root2);
        // sort(begin(res), end(res));
        return res;
    }
};
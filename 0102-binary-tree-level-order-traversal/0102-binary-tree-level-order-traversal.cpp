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
    void dfs(int level,TreeNode* root,vector<vector<int>>& ans){
        if(root==NULL){
            return;
        }
        if(ans.size()==level){
            ans.push_back({});
        }
        ans[level].push_back(root->val);
        dfs(level+1,root->left,ans);
        dfs(level+1,root->right,ans);


    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        dfs(0,root,ans);
        return ans;
    }
};
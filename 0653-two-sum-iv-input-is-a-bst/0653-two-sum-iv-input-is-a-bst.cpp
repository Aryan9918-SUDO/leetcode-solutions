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
    vector<int>ans;
    void inorder(TreeNode* root){
        if(root == NULL){
            return;
        }
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);

    }
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        map<int,int>mp;
        for(int i =0; i<ans.size(); i++){
            int target =k-ans[i];
            if(mp.find(target)!=mp.end()){
                return true;
            }
            mp[ans[i]]=i;
        }
        return false;
       
    } 
};
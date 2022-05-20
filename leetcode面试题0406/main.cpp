/*
author:lanben
date:2022/5/16
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        vector<TreeNode*> res;
        inorder(root,res);
        int target=p->val;
        int i=0;
        for(i=0;i<res.size();i++){
            if(res[i]->val==target) break;//此时i就是p的index
        }
        if(i==res.size()-1) return NULL;
        return res[i+1];
    }
private:
    void inorder(TreeNode* root,vector<TreeNode*> &res){
        if(root==NULL) return ;
        if(root->left){
            inorder(root->left,res);
        }
        
        res.push_back(root);
        if(root->right){
            inorder(root->right,res);
        }
        
    }
};
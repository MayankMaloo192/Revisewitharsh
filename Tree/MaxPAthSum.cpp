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

   int maxPath(TreeNode* root,int &ans){
        if(root == NULL)return 0;

        int ls = maxPath(root->left,ans);
        int rs =  maxPath(root->right,ans);

        int a = max(ls,rs);

        int max_one_path = max(a+root->val,root->val);

        int max_top = max(root->val+ls+rs,max_one_path);
        ans = max(ans,max_top);

        return max_one_path;
   }
    int maxPathSum(TreeNode* root) {

       // if(!root->left && !root->right)return root->val;
        int ans = -1e9;

        maxPath(root,ans);

        return ans;
        
    }
};
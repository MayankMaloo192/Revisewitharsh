class Solution {
public:
  void Helper(TreeNode* root,long long int target,int &ans){
      if(!root)return;

     if(target == root->val)ans++;

      Helper(root->left,target-root->val,ans);
      Helper(root->right,target-root->val,ans);
  }
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL)return 0;

        int ans = 0;
        Helper(root,targetSum,ans);

        ans += pathSum(root->left,targetSum) + pathSum(root->right,targetSum);

        return ans;
        //o(n^2) approach
        
    }
};
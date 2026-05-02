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
    int b(TreeNode* &root , bool& flag){
        if(!root)
            return 0;

        int left = b(root -> left , flag);
        int right = b(root -> right, flag);

        if(abs(left - right) > 1)
            flag = false;

        return max(left , right) + 1;    
    }

    bool isBalanced(TreeNode* root) {
        
        bool flag = true;
        b(root , flag);
        return flag;   
        
    }
};

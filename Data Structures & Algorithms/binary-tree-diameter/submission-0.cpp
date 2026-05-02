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
    int height(TreeNode* &root){
        if(!root)
            return 0;

        int left = height(root -> left);
        int right = height(root -> right);

        return max(left , right) + 1;
    }

    void dia(TreeNode* &root , int &maxi){
        if(!root)
            return ;

        pair<int , int> p;
        p.first = height(root -> left);
        p.second = height(root -> right);

        dia(root->left , maxi);
        dia(root->right , maxi);
        
        maxi = max (p.first + p.second , maxi);    
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        dia(root , maxi);
        return maxi;
    }
};

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
    void preOrder(TreeNode* &root ){
        if(!root)
            return;

        swap(root->right , root->left);

        preOrder(root->left);
        preOrder(root->right);
     
    }

    TreeNode* invertTree(TreeNode* root) {

        preOrder(root);
        return root;

    }
};

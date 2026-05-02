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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newNode = new TreeNode(val);

        if(!root)
            return newNode;

        TreeNode* temp = root;
        
        while(temp != NULL){
            if(temp->val < val && temp->right != NULL)
                temp = temp->right;
            else if(temp->val > val && temp->left != NULL)
                temp = temp -> left;  
            else 
                break;      
        }

        if(temp->val < val)
            temp->right = newNode;
        else if(temp->val > val)
            temp->left = newNode;

        return root;
    }
};
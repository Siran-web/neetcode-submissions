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
    TreeNode* anc(TreeNode* &root , TreeNode* &p , TreeNode* &q){
        if(!root)
            return root;

        int mini = min(p->val , q->val);
        int maxi = max(p->val , q->val);

        while(root != NULL){
            if(root->val < mini && root->val < maxi)
                root = root->right;
            else if(root->val > mini && root->val > maxi)
                root = root->left;
            else
                return root;        
        }
                
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return anc(root , p , q);
    }
};

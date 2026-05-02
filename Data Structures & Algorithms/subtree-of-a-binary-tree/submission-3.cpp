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
    void same(TreeNode* &p , TreeNode* &q , bool &flag){
        if(!p && !q)
            return;

        if(!p || !q){
            flag = false;
            return;
        }    

        if(p->val != q->val){
            flag = false;
            return;
        }

        same(p->left , q->left , flag);
        same(p->right , q->right , flag);    
    }

    void find(TreeNode* &p , TreeNode* &q , bool &found){
        if(!p )
            return;

        if(p->val == q->val){
            bool flag = true;
            same(p , q , flag);

            if(flag){
                found = true;
                return;
            }
        } 

        find(p->left , q , found);
        find(p->right , q , found);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool flag = false;
        find(root , subRoot , flag);
        return flag;
    }
};

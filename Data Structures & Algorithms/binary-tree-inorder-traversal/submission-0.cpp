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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root)
            return ans;

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            TreeNode* top = st.top();

            if(top->left){
                st.push(top->left);
                top->left = NULL;
            }
            else{
                ans.push_back(top->val);
                st.pop();
                
                if(top->right)
                    st.push(top->right);

            }    
        }    
        return ans;
    }
};
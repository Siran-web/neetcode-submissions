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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root)
            return ans;

        stack<TreeNode*> st , temp;
        st.push(root);

        while(!st.empty()){
            TreeNode* top = st.top();
            st.pop();

            if(top->left)
                st.push(top->left);
            if(top->right)
                st.push(top->right);

            temp.push(top);       
        }
        
        while(!temp.empty()){
            ans.push_back(temp.top() -> val);
            temp.pop();
        }
        return ans;
    }
};
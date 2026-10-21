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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        TreeNode* curr = root;
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(curr);

        int leftToRight = 1;
        while(!q.empty()) {
            int size = q.size();
            vector<int> level(size);
            for(int i = 0; i < size; i++) {
                TreeNode* temp = q.front();
                q.pop();

                int idx;
                if(leftToRight) {
                    idx = i;
                }
                else {
                    idx = size - i - 1; 
                }

                level[idx] = temp->val;
                if(temp->left != nullptr) q.push(temp->left);
                if(temp->right != nullptr) q.push(temp->right);
            }
            ans.push_back(level);
            leftToRight = 1 - leftToRight;
        }

        return ans;
    }
};
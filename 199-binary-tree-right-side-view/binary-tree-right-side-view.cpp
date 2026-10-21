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
private:
    void helperRecurs(TreeNode* root, int level, vector<int>& rightView) {
        if(root == nullptr) return;

        if(level == rightView.size()) rightView.push_back(root->val);

        helperRecurs(root->right, level + 1, rightView);
        helperRecurs(root->left, level + 1, rightView);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr) return {};

        vector<int> rightView;

        helperRecurs(root, 0, rightView);

        return rightView;
    }
};
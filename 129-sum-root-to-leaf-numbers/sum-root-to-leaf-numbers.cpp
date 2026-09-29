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
    int helperFunc(TreeNode* root, int ans) {
        if(root == nullptr) return 0;

        ans = ans * 10 + root->val;
        if(root->left == nullptr && root->right == nullptr) return ans;

        return helperFunc(root->left, ans) + helperFunc(root->right, ans);
    }
public:
    int sumNumbers(TreeNode* root) {
        return helperFunc(root, 0);
    }
};
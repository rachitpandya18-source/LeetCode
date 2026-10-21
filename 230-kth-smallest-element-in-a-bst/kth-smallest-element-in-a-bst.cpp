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
    void helperRecurs(TreeNode* root, int& count, int k, int& ans) {
        if(root == nullptr) return;

        helperRecurs(root->left, count, k, ans);
        count++;
        if(count == k) {
            ans = root->val;
            return;
        }
        helperRecurs(root->right, count, k, ans);
    }
public:
    int kthSmallest(TreeNode* root, int k) {

        int count = 0;
        int ans;
        helperRecurs(root, count, k, ans);

        return ans;
    }
};
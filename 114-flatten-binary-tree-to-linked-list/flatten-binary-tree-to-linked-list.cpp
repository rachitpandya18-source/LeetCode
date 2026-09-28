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
    void flatten(TreeNode* root) {
        TreeNode* temp = root;
        while(temp) {
            if(temp->left) {
                TreeNode* leftSub = temp->left;
                while(leftSub->right) leftSub = leftSub->right;

                leftSub->right = temp->right;
                temp->right = temp->left;
                temp->left = nullptr;
            }
            temp = temp->right;
        }
    }
};
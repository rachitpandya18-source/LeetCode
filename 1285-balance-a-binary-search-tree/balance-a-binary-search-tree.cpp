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
void Inorder(TreeNode* root, vector<int>& inOrder) {
    if(root == nullptr) return;

    Inorder(root->left, inOrder);
    inOrder.push_back(root->val);
    Inorder(root->right, inOrder);
} 
TreeNode* constructBST(int l, int r, vector<int>& inOrder) {
    if(l > r) return nullptr;

    int mid = (l + r) >> 1;
    TreeNode* root = new TreeNode(inOrder[mid]);

    root->left = constructBST(l, mid - 1, inOrder);
    root->right = constructBST(mid + 1, r, inOrder);

    return root; 
}
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inOrder;
        Inorder(root, inOrder);

        int l = 0, r = inOrder.size();

        return constructBST(l, r - 1, inOrder);
    }
};
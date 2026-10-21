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
    TreeNode* buildLogic(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& inHashMap) {
        if(preStart > preEnd || inStart > inEnd) return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);
        int inIndex = inHashMap[root->val];
        int leftNums = inIndex - inStart;

        root->left = buildLogic(preorder, preStart + 1, preStart + leftNums, inorder, inStart, inIndex - 1, inHashMap);
        root->right = buildLogic(preorder, preStart + leftNums + 1, preEnd, inorder, inIndex + 1, inEnd, inHashMap);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int n = preorder.size();
        unordered_map<int, int> inHashMap;

        for(int i = 0; i < n; i++) inHashMap[inorder[i]] = i;

        return buildLogic(preorder, 0, n - 1, inorder, 0, n - 1, inHashMap);
    }
};
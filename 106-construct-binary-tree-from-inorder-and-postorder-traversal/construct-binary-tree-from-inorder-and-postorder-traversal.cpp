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
    TreeNode* buildLogic(vector<int>& inorder, int instart, int inend, vector<int>& postorder, int poststart, int postend, unordered_map<int, int>& inHashMap) {
        if(instart > inend || poststart < postend) return NULL;

        TreeNode* root = new TreeNode(postorder[poststart]);
        int rootIndex = inHashMap[root->val];
        int numsOnTheRight = inend - rootIndex;

        root->left = buildLogic(inorder, instart, rootIndex - 1, postorder, poststart - numsOnTheRight - 1, postend, inHashMap);     
        root->right = buildLogic(inorder, rootIndex + 1, inend, postorder, poststart - 1, poststart - numsOnTheRight, inHashMap);                

        return root;           
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();

        unordered_map<int, int> inHashMap;
        for(int i = 0; i < n; i++) inHashMap[inorder[i]] = i;

        return buildLogic(inorder, 0, n - 1, postorder, n - 1, 0, inHashMap);
    }
};
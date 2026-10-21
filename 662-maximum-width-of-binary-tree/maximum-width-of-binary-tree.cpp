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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;

        queue<pair<TreeNode*, unsigned long long>> q;
        TreeNode* curr = root;
        q.push({curr, 0});
        unsigned long long maxi = 0;
        while(!q.empty()) {
            int size = q.size();

            unsigned long long mini = q.front().second;
            unsigned long long first, last;
            for(int i = 0; i < size; i++) {
                unsigned long long currIdx = q.front().second - mini; // To prevent overflowww
                TreeNode* node = q.front().first;
                q.pop();
                if(i == 0) first = currIdx;
                if(i == size - 1) last = currIdx;

                if(node->left) q.push({node->left, currIdx * 2 + 1});
                if(node->right) q.push({node->right, currIdx * 2 + 2});
            }

            maxi = max(maxi, last - first + 1);
        }
        return maxi;
    }
};
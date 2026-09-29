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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        priority_queue<long long, vector<long long>, greater<long long>> pq;

        q.push(root);

        while(q.empty() != true) {
            int size = q.size();
            long long levelSum = 0;
            while(size--) {
                TreeNode* curr = q.front();
                levelSum += curr->val;

                if(curr->left != nullptr) q.push(curr->left);
                if(curr->right != nullptr) q.push(curr->right);

                q.pop();
            }
            pq.push(levelSum);

            if(pq.size() > k) pq.pop();
        }

        if(pq.size() < k) return -1;
        return pq.top();
    }
};
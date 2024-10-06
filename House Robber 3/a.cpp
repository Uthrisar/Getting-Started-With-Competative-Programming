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
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, vector<int>> dp;
        return max(rec(root,0,dp),rec(root,1,dp));
    }

    int rec(TreeNode* node, int isTaken, unordered_map<TreeNode*, vector<int>>& dp){
        if(dp[node].empty()) dp[node] = vector<int>(2, -1);
        if(dp[node][isTaken] != -1) return dp[node][isTaken];
        if(isTaken){
            int ans = node->val;
            if(node->left != nullptr){
                ans += rec(node->left,0,dp);
            }
            if(node->right != nullptr){
                ans += rec(node->right,0,dp);
            }
            return dp[node][1] = ans;
        } else {
            int ans = 0;
            if(node->left != nullptr){
                ans += max(rec(node->left,0,dp),rec(node->left,1,dp));
            }
            if(node->right != nullptr){
                ans += max(rec(node->right,0,dp),rec(node->right,1,dp));
            }
            return dp[node][0] = ans;
        }
    }
};

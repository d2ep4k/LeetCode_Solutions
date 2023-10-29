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

    void dfs(int level, TreeNode * cur, vector<int>& maxAt){
        if(!cur) return;
        if(level + 1 > maxAt.size()){
            maxAt.push_back(cur->val);
        }
        else{
            maxAt[level] = max(maxAt[level], cur->val);
        }
        if(cur->left){
            dfs(level + 1, cur->left, maxAt);
        }
        if(cur->right){
            dfs(level + 1, cur->right, maxAt);
        }
        return;
    }

    vector<int> largestValues(TreeNode* root) {
        vector<int> maxAt;
        dfs(0, root, maxAt);
        return maxAt;
    }
};

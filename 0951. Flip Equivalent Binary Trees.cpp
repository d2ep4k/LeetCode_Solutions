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

//METHOD 1
class Solution {
public:

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr&&q==nullptr)  return true;
        if(p==nullptr||q==nullptr)  return false;
        if(p->val!=q->val)  return false;
        return isSameTree(p->right, q->right)&&isSameTree(p->left, q->left);
    }

    void sortTree(TreeNode * p){
        if(!p)return;
        if(!p->right)swap(p->right, p->left);
        if(p->left&&p->right){
            if(p->left->val>p->right->val)
                swap(p->right,p->left);
        }
        if(p->right)  sortTree(p->right);
        if(p->left)  sortTree(p->left);
        return;
    }

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        sortTree(root1);
        sortTree(root2);
        return isSameTree(root1,root2);
    }
};


// METHOD 2

// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     bool flipEquiv(TreeNode* p, TreeNode* q) {
//         if(p==nullptr&&q==nullptr)  return true;
//         if(p==nullptr||q==nullptr)  return false;
//         if(p->val!=q->val)  return false;
//         return (flipEquiv(p->right,q->right)&&flipEquiv(p->left,q->left))||(flipEquiv(p->right,q->left)&&flipEquiv(p->left,q->right));
//     }
// };

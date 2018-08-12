#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool is_sym(TreeNode *l, TreeNode* r)
    {
        bool result = true;
        if(l==NULL && r==NULL)
        {
            return true;
        }
        if(l->val!=r->val)
        {
            return false;
        }
        if(l->left==NULL ^ r->right==NULL)
        {
            return false;
        }
        result &= is_sym(l->left,r->right);
        if(l->right==NULL ^ r->left==NULL)
        {
            return false;
        }
        result &= is_sym(l->right,r->left);

        return result;
    }

    bool isSymmetric(TreeNode* root)
    {
        if(root==NULL)
        {
            return true;
        }
        if(root->left==NULL ^ root->right==NULL)
        {
            return false;
        }
        return is_sym(root->left,root->right);
    }
};

int main()
{
    return 0;
}

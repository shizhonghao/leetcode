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
    int sum = 0;

    TreeNode* convertBST(TreeNode* root)
    {
        if(root==NULL)
        {
            return root;
        }
        if(root->right!=NULL)
        {
            convertBST(root->right);
        }
        root->val+=sum;
        sum=root->val;
        if(root->left!=NULL)
        {
            convertBST(root->left);
        }
        return root;
    }
};

int main()
{
    return 0;
}

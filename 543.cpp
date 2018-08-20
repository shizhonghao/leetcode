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
    int result = 0;

    int deepth(TreeNode *node)
    {
        int d1 = 0, d2 = 0;
        if(node->left!=NULL)
        {
            d1 = deepth(node->left);
        }
        if(node->right!=NULL)
        {
            d2 = deepth(node->right);
        }
        result = max(result,d1+d2+1);
        return max(d1,d2)+1;
    }

    int diameterOfBinaryTree(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        deepth(root);
        return result-1;
    }
};

int main()
{
    return 0;
}


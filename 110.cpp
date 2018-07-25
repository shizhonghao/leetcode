
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
    bool result = true;
    int dfs(TreeNode* node)
    {
        int l_depth = 0, r_depth = 0;
        if(node->left!=NULL)
        {
            l_depth = dfs(node->left)+1;
        }
        if(node->right!=NULL)
        {
            r_depth = dfs(node->right)+1;
        }
        if(abs(l_depth-r_depth)>1 )
        {
            result = false;
        }
        return max(l_depth,r_depth);
    }

    bool isBalanced(TreeNode* root)
    {
        if(root==NULL)
        {
            return result;
        }
        dfs(root);
        return result;
    }
};

int main()
{
    return 0;
}

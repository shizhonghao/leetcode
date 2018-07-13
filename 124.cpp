/**
 * Definition for a binary tree node.
 */

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    const int INF = 0x3f3f3f3f;
    int result = -INF;

    int max_val(TreeNode* root)
    {
        int lval = 0;
        int rval = 0;
        if(root->left!=NULL)
        {
            lval = max(0,max_val(root->left));
        }
        if(root->right!=NULL)
        {
            rval = max(0,max_val(root->right));
        }
        result = max(result,lval+root->val+rval);
        return max(lval+root->val,rval+root->val);
    }

    int maxPathSum(TreeNode* root)
    {
        max_val(root);
        return result;
    }
};

int main()
{
    return 0;
}

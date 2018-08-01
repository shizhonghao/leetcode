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
    int findBottomLeftValue(TreeNode* root)
    {
        int result = 0;
        queue<TreeNode> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            result = node->val;
            if(node->right!=NULL)
            {
                q.push(node->right);
            }
            if(node->left!=NULL)
            {
                q.push(node->left);
            }
        }
        return result;
    }
};

int main()
{
    return 0;
}


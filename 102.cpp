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
    vector<vector<int> > levelOrder(TreeNode* root)
    {
        vector<vector<int> > result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            vector<int> layer;
            int n = q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode *node = q.front();
                layer.push_back(node->val);
                q.pop();
                if(node->left!=NULL)
                {
                    q.push(node->left);
                }
                if(node->right!=NULL)
                {
                    q.push(node->right);
                }
            }
            result.push_back(layer);
        }
        return result;
    }
};

int main()
{

    return 0;
}

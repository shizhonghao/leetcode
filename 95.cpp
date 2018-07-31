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
    TreeNode* copy_of(TreeNode* root, int x)
    {
        if(root==NULL)
        {
            return NULL;
        }
        TreeNode* node = new TreeNode(root->val+x);
        if(root->left!=NULL)
        {
            node->left = copy_of(root->left,x);
        }
        if(root->right!=NULL)
        {
            node->right = copy_of(root->right,x);
        }
        return node;
    }

    vector<TreeNode*> generateTrees(int n)
    {
        vector<TreeNode*> result;
        if(n==0)
        {
            return result;
        }
        vector<TreeNode*> dp[n+1];
        TreeNode *tmp = NULL;
        dp[0].push_back(tmp);
        tmp = new TreeNode(1);
        dp[1].push_back(tmp);
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                for(int l=0;l<dp[j-1].size();l++)
                {
                    for(int r=0;r<dp[i-j].size();r++)
                    {
                        tmp = new TreeNode(j);
                        tmp->left = copy_of(dp[j-1][l],0);
                        tmp->right = copy_of(dp[i-j][r],j);
                        dp[i].push_back(tmp);

                    }
                }
            }
        }

        return dp[n];
    }
};

int main()
{
    return 0;
}


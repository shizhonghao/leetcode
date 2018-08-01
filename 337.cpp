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
    struct Node {
        int val;
        int if_rob;
        int not_rob;
        Node *left;
        Node *right;
        Node(int x) : val(x), if_rob(x), not_rob(0), left(NULL), right(NULL) {}
    };

    Node* copy_from(TreeNode *root)
    {
        if(root==NULL)
        {
            return NULL;
        }
        Node* new_root = new Node(root->val);
        if(root->left!=NULL)
        {
            new_root->left = copy_from(root->left);
        }
        if(root->right!=NULL)
        {
            new_root->right = copy_from(root->right);
        }
        return new_root;
    }

    int rob_most(Node* root)
    {
        int result = 0;
        if(root->left!=NULL)
        {
            rob_most(root->left);
            root->if_rob += root->left->not_rob;
            root->not_rob += max(root->left->if_rob, root->left->not_rob);
        }
        if(root->right!=NULL)
        {
            rob_most(root->right);
            root->if_rob += root->right->not_rob;
            root->not_rob += max(root->right->if_rob, root->right->not_rob);
        }
        return max(root->if_rob,root->not_rob);
    }

    int rob(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        Node* cp = copy_from(root);
        return rob_most(cp);
    }
};

int main()
{
    return 0;
}


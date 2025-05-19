/*
Request: Implement function:
int lowestAncestor(BTNode* root, int a, int b);
*/

#include <bits/stdc++.h>
using namespace std;

class BTNode 
{
    public: 
        int val; 
        BTNode *left; 
        BTNode *right; 
        BTNode() 
        {
            this->left = this->right = NULL;
        } 
        BTNode(int val) 
        {
            this->val = val;
            this->left = this->right = NULL;
        } 
        BTNode(int val, BTNode*& left, BTNode*& right) 
        {
            this->val = val;
            this->left = left;
            this->right = right;
        }

        // TODO
        // Helper function to find the LCA and return its pointer
        BTNode* findLCA(BTNode* node, int a, int b) // lowest common ancestor
        {
            // Base case: if node is NULL, return NULL
            if (!node) return nullptr;
            // If current node is either a or b, return the node
            if (node->val == a || node->val == b) return node;
            // Recursively search in left and right subtrees
            BTNode* leftLCA = findLCA(node->left, a, b);
            BTNode* rightLCA = findLCA(node->right, a, b);
            
            // If both left and right subtrees return non-NULL, current node is the LCA
            if (leftLCA != nullptr && rightLCA != nullptr) return node;
            // Otherwise, return the non-NULL result (if any), or NULL if both are NULL
            return (leftLCA != nullptr) ? leftLCA : rightLCA;
        }

        int lowestAncestor(BTNode* root, int a, int b) 
        {
            // Find the LCA node
            BTNode* lca = findLCA(root, a, b);
            // Return its value (lca is guaranteed to exist as a and b are in the tree)
            return lca->val;
        }
};

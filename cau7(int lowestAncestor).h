/*
Request: Implement function:
int sumDigitPath(BTNode* root);

Where root is the root node of given binary tree (this tree has between 2 and 100000 elements). 
This function returns the sum of all digit path numbers of this binary tree (the result may be large, so you must use mod 27022001 before returning).
More information:
- A path is called as digit path if it is a path from the root node to the leaf node of the binary tree.
- Each digit path represents a number in order, each node's val of this path is a digit of this number, while root's val is the first digit.
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
        BTNode* findLCA(BTNode* node, int a, int b) 
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
/*
Request: Implement function:
int longestPathSum(BTNode* root);

Where root is the root node of given binary tree (this tree has between 1 and 100000 elements). 
This function returns the sum of the largest path from the root node to a leaf node. If there are more than one equally long paths, return the larger sum.


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
        // Helper struct to store path length and sum
        struct PathInfo 
        {
            int length; // Length of path to leaf
            int sum;    // Sum of path to leaf
            PathInfo(int l, int s) : length(l), sum(s) {}
        };

        // Helper function to recursively find the longest path and its sum
        PathInfo findLongestPath(BTNode* node) 
        {
            // Base case: if node is null, return length 0 and sum 0
            if (node == nullptr) return PathInfo(0, 0);
            // Base case: if node is a leaf, return length 1 and its value
            if (node->left == nullptr && node->right == nullptr) return PathInfo(1, node->val);
            
            // Recursively get the longest path info from left and right subtrees
            PathInfo leftPath = findLongestPath(node->left);
            PathInfo rightPath = findLongestPath(node->right);
            
            // Compare paths: prioritize longer path, if lengths are equal, take larger sum
            if (leftPath.length > rightPath.length) return PathInfo(leftPath.length + 1, leftPath.sum + node->val);
            else if (rightPath.length > leftPath.length) return PathInfo(rightPath.length + 1, rightPath.sum + node->val);
            else 
            {
                // If lengths are equal, choose the path with the larger sum
                if (leftPath.sum >= rightPath.sum) return PathInfo(leftPath.length + 1, leftPath.sum + node->val);
                else return PathInfo(rightPath.length + 1, rightPath.sum + node->val);
            }
        }
        int longestPathSum(BTNode* root) 
        {
            // Edge case: if root is NULL, return 0
            if (root == NULL) return 0;
            // Get the longest path info starting from the root
            PathInfo result = findLongestPath(root);
            return result.sum;
        }
};
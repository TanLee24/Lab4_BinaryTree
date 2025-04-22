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
        const int MOD = 27022001;
        // Helper function to calculate the sum of digit paths
        void calculatePathSum(BTNode* node, long long currentNum, long long& totalSum) 
        {
            if (!node) return;
            // Update the current number: multiply by 10 and add the current node's value
            currentNum = (currentNum * 10 + node->val) % MOD;
            // If it's a leaf node, add the current number to the total sum
            if (node->left == nullptr && node->right == nullptr) 
            {
                totalSum = (totalSum + currentNum) % MOD;
                return;
            }
            calculatePathSum(node->left, currentNum, totalSum);
            calculatePathSum(node->right, currentNum, totalSum);
        }

        int sumDigitPath(BTNode* root) 
        {
            if (!root) return 0;
            long long totalSum = 0;
            calculatePathSum(root, 0, totalSum);
            return totalSum;
        }
};
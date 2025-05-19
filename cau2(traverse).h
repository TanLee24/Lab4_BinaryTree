/*Given class BinaryTree, you need to finish methods getHeight(), preOrder(), inOrder(), postOrder().*/

#include <bits/stdc++.h>
using namespace std;

template<class K, class V>
class BinaryTree
{
public:
    class Node;

private:
    Node *root;

public:
    BinaryTree() : root(nullptr) {}
    ~BinaryTree()
    {
        // You have to delete all Nodes in BinaryTree. However in this task, you can ignore it.
    }

    class Node
    {
    private:
        K key;
        V value;
        Node *pLeft, *pRight;
        friend class BinaryTree<K, V>;

    public:
        Node(K key, V value) : key(key), value(value), pLeft(NULL), pRight(NULL) {}
        ~Node() {}
    };

    void addNode(string posFromRoot, K key, V value)
    {
        if(posFromRoot == "")
        {
            this->root = new Node(key, value);
            return;
        }

        Node* walker = this->root;
        int l = posFromRoot.length();
        for (int i = 0; i < l-1; i++)
        {
            if (!walker)
                return;
            if (posFromRoot[i] == 'L')
                walker = walker->pLeft;
            if (posFromRoot[i] == 'R')
                walker = walker->pRight;
        }
        if(posFromRoot[l-1] == 'L')
            walker->pLeft = new Node(key, value);
        if(posFromRoot[l-1] == 'R')
            walker->pRight = new Node(key, value);
    }

    // STUDENT ANSWER BEGIN
    int getHeight() 
    {
        // TODO: return height of the binary tree.
        if (!root) return 0;
        BinaryTree<K, V> leftSubtree;
        BinaryTree<K, V> rightSubtree;
        leftSubtree.root = root->pLeft;
        rightSubtree.root = root->pRight;
        return 1 + max(leftSubtree.getHeight(), rightSubtree.getHeight());
    }

    string preOrder() // root - left - right
    {
        // TODO: return the sequence of values of nodes in pre-order.
        if (!root) return "";
        stringstream ss;
        BinaryTree<K, V> leftSubtree;
        BinaryTree<K, V> rightSubtree;
        leftSubtree.root = root->pLeft;
        rightSubtree.root = root->pRight;
        string left = leftSubtree.preOrder();
        string right = rightSubtree.preOrder();
        // Combine: left, current value, right
        ss << root->value;
        if (!left.empty()) ss << " " << left;
        if (!right.empty()) ss << " " << right;
        return ss.str();
    }

    string inOrder() // left - root - right
    {
        // TODO: return the sequence of values of nodes in in-order.
        if (!root) return "";
        stringstream ss;
        BinaryTree<K, V> leftSubtree;
        BinaryTree<K, V> rightSubtree;
        leftSubtree.root = root->pLeft;
        rightSubtree.root = root->pRight;
        string left = leftSubtree.inOrder();
        string right = rightSubtree.inOrder();
        // Combine: left, current value, right
        if (!left.empty()) ss << left << " ";
        ss << root->value;
        if (!right.empty()) ss << " " << right;
        return ss.str();
    }

    string postOrder() // left - right - root
    {
        // Base case: empty tree returns empty string
        if (!root) return "";
        // Create temporary trees for left and right subtrees
        BinaryTree<K, V> leftSubtree;
        BinaryTree<K, V> rightSubtree;
        leftSubtree.root = root->pLeft;
        rightSubtree.root = root->pRight;
        // Get left and right postorder strings
        string left = leftSubtree.postOrder();
        string right = rightSubtree.postOrder();
        // Combine: left, right, current value
        stringstream ss;
        if (!left.empty()) ss << left << " ";
        if (!right.empty()) ss << right << " ";
        ss << root->value;
        return ss.str();
    }
    // STUDENT ANSWER END
};

/*Given a Binary tree, the task is to calculate the sum of leaf nodes. (Leaf nodes are nodes which have no children)*/

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
    int sumOfLeafs()
    {
        //TODO
        if (!root) return 0;
        BinaryTree<K, V> leftSubtree;
        BinaryTree<K, V> rightSubtree;
        leftSubtree.root = root->pLeft;
        rightSubtree.root = root->pRight;
        if (leftSubtree.root == nullptr && rightSubtree.root == nullptr)
        {
            return root->value;
        }
        return leftSubtree.sumOfLeafs() + rightSubtree.sumOfLeafs();
    }
    // STUDENT ANSWER END
};
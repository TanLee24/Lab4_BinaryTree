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
    void BFS() 
    {
        if (!root) return;
        queue<Node*> q;
        q.push(root);
        bool first = true;
        while (!q.empty()) 
        {
            Node* current = q.front();
            q.pop();
            // Print value, with space before it unless it's the first node
            if (first) 
            {
                cout << current->value;
                first = false;
            } 
            else cout << " " << current->value;
            // Add left child to queue if it exists
            if (current->pLeft != nullptr) q.push(current->pLeft);
            // Add right child to queue if it exists
            if (current->pRight != nullptr) q.push(current->pRight);
        }
    }
    // STUDENT ANSWER END
};
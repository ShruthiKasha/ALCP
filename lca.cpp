#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

Node* LCA(Node* root, int a, int b) {
    if (root == NULL || root->data == a || root->data == b)
        return root;

    Node* left = LCA(root->left, a, b);
    Node* right = LCA(root->right, a, b);

    if (left && right)
        return root;

    if (left)
        return left;

    return right;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int a, b;

    cout << "Enter two nodes: ";
    cin >> a >> b;

    Node* ans = LCA(root, a, b);

    cout << "Lowest Common Ancestor = " << ans->data;

    return 0;
}
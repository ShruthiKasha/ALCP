#include <iostream>
#include <queue>
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

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    Node* nodes[n];

    cout << "Enter node values: ";
    for (int i = 0; i < n; i++)
        nodes[i] = new Node(i + 1);

    cout << "Enter values in level order: ";
    for (int i = 0; i < n; i++)
        cin >> nodes[i]->data;

    for (int i = 0; i < n; i++) {
        if (2 * i + 1 < n)
            nodes[i]->left = nodes[2 * i + 1];

        if (2 * i + 2 < n)
            nodes[i]->right = nodes[2 * i + 2];
    }

    queue<Node*> q;
    q.push(nodes[0]);

    cout << "Level order: ";

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if (temp->left)
            q.push(temp->left);

        if (temp->right)
            q.push(temp->right);
    }

    return 0;
}

#include <iostream>
#include <map>
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    int hd;
    Node *left, *right;

    Node(int key)
    {
        data = key;
        hd = INT_MAX;
        left = right = NULL;
    }
};

void topView(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    map<int, int> m;
    int hd = 0;
    root->hd = hd;

    q.push(root);

    cout << "The top view of the tree is : \n";

    while (q.size())
    {
        hd = root->hd;

        if (m.count(hd) == 0)
            m[hd] = root->data;
        if (root->left)
        {
            root->left->hd = hd - 1;
            q.push(root->left);
        }
        if (root->right)
        {
            root->right->hd = hd + 1;
            q.push(root->right);
        }
        q.pop();
        root = q.front();
    }
    map<int, int>::iterator i;
    for (i = m.begin(); i != m.end(); i++)
    {
        cout << i->second << " ";
    }
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    topView(root);

    return 0;
}



// C++ program to print left view of Binary Tree
#include <bits/stdc++.h>
using namespace std;
vector<int> res;
struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *newNode(int item)
{
    struct Node *temp = (struct Node *)malloc(
        sizeof(struct Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

void dfs(Node *root, int height)
{
    if (!root)
        return;
    if (height == res.size())
        res.push_back(root->data);
    dfs(root->right, height + 1);
    dfs(root->left, height + 1);
}

vector<int> rightSideView(Node *root)
{
    dfs(root, 0);
    return res;
}

int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
    vector<int> v;
    v = rightSideView(root);
    for (auto i : v)
        cout << i << " ";
    return 0;
}

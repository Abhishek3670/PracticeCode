#include <iostream>
#include <stdlib.h>
using namespace std;

struct NODE
{
    NODE *left;
    NODE *right;
    int data;
};
NODE *newNODE(int value)
{
    NODE *temp = new NODE();
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}

NODE *createTree(NODE *root, int value)
{
    if (root == NULL)
        return newNODE(value);
    if (root->data == value)
    {
        cout << "duplicate";
        exit(0);
    }

    if (root->data > value)
        root->left = createTree(root->left, value);
    else
        root->right = createTree(root->right, value);
}
void *inorder(NODE *root)
{
    if (root)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
void *preorder(NODE *root)
{
    if (root)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
void *postorder(NODE *root)
{
    if (root)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}
int countNodes(NODE *root)
{
    int x = 0, y = 0;
    if (root)
    {
        x = countNodes(root->left);
        y = countNodes(root->right);
        return x + y + 1;
    }
}
int height(NODE *root)
{
    int x = 0, y = 0;
    if (root)
    {
        x = height(root->left);
        y = height(root->right);
        if (x > y)
            return x + 1;
        else
            return y + 1;
    }
}
// void display(NODE *root)
// {
//     if (root == NULL)
//         return;

//     cout << root->data << " ";
//     display(root->left);
//     display(root->right);
// }
int main()
{
    NODE *root = new NODE();
    root = NULL;
    root = createTree(root, 50);
    root = createTree(root, 30);
    root = createTree(root, 70);
    root = createTree(root, 20);
    root = createTree(root, 40);
    root = createTree(root, 60);
    root = createTree(root, 80);
    root = createTree(root, 35);
    root = createTree(root, 90);
    root = createTree(root, 75);
    // display(root);
    cout << endl;
    cout << "Inorder : ";
    inorder(root);
    cout << endl;
    cout << "preorder : ";
    preorder(root);
    cout << endl;
    cout << "postorder : ";
    postorder(root);
    cout << endl;
    cout << "No. of nodes : " << countNodes(root);
    cout << endl;
    cout << "Height of tree : " << height(root) - 1;
}
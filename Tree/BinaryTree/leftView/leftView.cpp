// C++ program to print left view of Binary Tree
#include <bits/stdc++.h>
using namespace std;

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
void printLeftView(Node* root)
{
    if (!root)
        return;
 
    queue<Node*> q;
    q.push(root);
 
    while (!q.empty())
    {    
        // number of nodes at current level
        int n = q.size();
         
        // Traverse all nodes of current level
        for(int i = 1; i <= n; i++)
        {
            Node* temp = q.front();
            q.pop();
                 
            // Print the left most element
            // at the level
            if (i == 1)
                cout<<temp->data<<" ";
             
            // Add left node to queue
            if (temp->left != NULL)
                q.push(temp->left);
 
            // Add right node to queue
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
}    
 
void leftViewUtil(struct Node *root, int level, int *max_level)
{
    if (root == NULL)
        return;
    if (*max_level < level)
    {
        cout << root->data << " ";
        *max_level = level;
    }
    leftViewUtil(root->left, level + 1, max_level);
    leftViewUtil(root->right, level + 1, max_level);
}

void leftView(struct Node *root)
{
    int max_level = 0;
    leftViewUtil(root, 1, &max_level);
}

// Driver Code
int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    printLeftView(root);

    return 0;
}

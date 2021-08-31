#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *link;
};

struct Node *top;

void push(int data)
{

    struct Node *temp;
    temp = new Node();
    temp->data = data;
    temp->link = top;
    top = temp;
}

Node* pop()
{
    struct Node *temp;
    temp = top;
    top = top->link;
    temp->link = NULL;
    return temp;
}

void display()
{
    struct Node *temp;
    temp = top;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->link;
    }
}
void remove()
{
    Node *temp ;
    while(top)
    {
        temp = pop();
        temp->
    }
}
int main()
{
    Node *s = new Node();
    int n;
    int Q;
    int mini = INT_MAX;
    cin >> Q;

    while (1)
    {
        char ch;
        cin >> ch;
        switch (ch)
        {
        case 'A':
            cin >> n;
            push(n);
            break;
        case 'B':
            display();
            break;
        case 'C':
            cout << pop();
            break;
        case 'D':
            reverse();
            break;
        }
        default:
            exit(1);

    }
}
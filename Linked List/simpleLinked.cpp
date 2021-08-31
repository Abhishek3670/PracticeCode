#include <iostream>

using namespace std;

struct NODE
{
    int data;
    NODE *next;
};
void printNODE(NODE *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}
NODE *insertFromBack(NODE *node, int value)
{
    NODE *curr = node;
    NODE *first_node = node->next;
    NODE *temp = new NODE();
    temp->data = value;
    temp->next = NULL;
    if (curr->next == NULL)
        return temp;

    while (curr->next != NULL)
        curr = curr->next;

    curr->next = temp;
    return first_node;
}
NODE *insertFromFront(NODE *node, int value)
{
    NODE *curr = node;
    NODE *first_node = node->next;
    NODE *temp = new NODE();
    temp->data = value;
    temp->next = first_node;
    if (curr->next == NULL)
        return temp;
    curr->next = temp;
    return temp;
}
NODE *reverseList(struct NODE *head)
{
    NODE *currNODE = head;
    NODE *nextNODE = NULL;
    nextNODE = currNODE->next;
    NODE *prev = NULL;
    while (currNODE != NULL)
    {
        nextNODE = currNODE->next;
        currNODE->next = prev;
        prev = currNODE;
        currNODE = nextNODE;
        next
    }
    return currNODE;
}
int main()
{
    NODE *head = new NODE();
    head->next = NULL;
    int d, n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> d;
        head->next = insertFromFront(head, d);
    }
    printNODE(head->next);
    head->next = reverseList(head);
    printNODE(head->next);
}
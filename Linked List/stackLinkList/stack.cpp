#include <iostream>

using namespace std;

struct STACK
{
    struct STACK *link;
    int data;
    STACK(int x)
    {
        link = NULL;
        data = x;
    }
};
struct STACK *top;
void push(int x)
{
    STACK *temp = new STACK(x);
    temp->link = top;
    top = temp;
}
void pop()
{
    STACK *temp;
    temp = top;
    top = top->link;
    temp->link = NULL;
    free(temp);
}
void display()
{
    STACK *curr;
    curr = top;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->link;
    }
}
int middle()
{
    STACK *slow, *fast;
    slow = top;
    fast = top;
    while (fast && fast->link)
    {
        slow = slow->link;
        fast = fast->link;
        fast = fast->link;
    }
    return slow->data;
}
void reverse()
{
    STACK *curr, *next, *temp;
    curr = top;
    next = NULL;
    temp = NULL;
    while (curr != NULL)
    {
        next = curr->link;
        curr->link = temp;
        temp = curr;
        curr = next;
    }
    top = temp;
}
int main()
{
    STACK *s;
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);

    display();
    cout << endl;
    cout << middle() << endl;
    reverse();
    display();
}
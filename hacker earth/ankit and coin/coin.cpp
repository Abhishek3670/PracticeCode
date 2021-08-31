#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int data;
    ListNode *next;
};
ListNode *rotateRight(ListNode *head, int k)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *tmp = head;
    int cnt = 0;
    while (tmp)
        tmp = tmp->next, cnt++;
    tmp = head;
    k %= cnt;
    if (k == 0)
        return head;
    while (k--)
        tmp = tmp->next;
    ListNode *tmpHead = head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
        head = head->next;
    }
    ListNode *newHead = head->next;
    tmp->next = tmpHead;
    head->next = NULL;
    return newHead;
}
ListNode *insertNode(ListNode *head, int ele)
{
    head->data = ele;
    head->next = NULL;
    return head;
}
int main()
{
    ListNode *head = new ListNode();
    int ele , n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> ele;
        head = insertNode(head , ele);
    }
    head->next = NULL;
    head = rotateRight(head, 2);
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
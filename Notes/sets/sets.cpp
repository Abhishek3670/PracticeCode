#include <iostream>
#include <set>
#include <iterator>
using namespace std;
// SETS -> implementation - self balancing BST.

// syntax -> set<int> s;

// 1. Stores unique element.
// 2. Duplicate not allowed.
// 3. Addition / deletion possible, modification not possible
// 4. Sorted array in ascending order.
//     for reverse - set<int,greater<int>> s;
// 5. Time Complexity - O(log n)

// Operetion ->
//                 insert(), find(), clear(), size()
//                 erase(), begin(), end(), max_size()

// UNORDERED SETS -> implementation - hash table.

// Time Complexity -
//                     avg - O(1)
//                     worst - O(n)
template <class T>
T merge(T a, T b)
{
    T t(a);
    t.insert(b.begin(), b.end());
    return t;
}
void reverseSet(set<int> s)
{
    set<int>::reverse_iterator ritr;
    for (ritr = s.rbegin(); ritr != s.rend(); ritr++)
    {
        cout << *ritr << " ";
    }
    cout << endl;
}
void display(set<int> s, set<int>::iterator itr)
{
    for (itr = s.begin(); itr != s.end(); itr++)
    {
        cout << *itr << " ";
    }
    cout << endl;
}
int main()
{
    set<int> s, s_merge, s_copy;
    set<int>::iterator itr;
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);
    s.insert(50);
    int arr[] = {60,70,80,90,100};
    int len = sizeof(arr)/sizeof(arr[0]);
    set<int> s_arr (arr,arr+len);
    display(s_arr, itr);      // display set s_arr
    display(s, itr);      // display set s
    s_copy = s;           //Copy
    display(s_copy, itr); // display set s_copy

    s_merge = merge(s_arr, s_copy); // merging s , s_copy
    display(s_merge, itr);      //display merged set
    
    reverseSet(s); //reversing existing set

}
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL || l2 == NULL)
        {
            if (l1)
                return l1;
            else if (l2)
                return l2;
            else
                return NULL;
        }
        ListNode *begin = NULL, *prev = NULL, *cur1 = l1, *cur2 = l2;
        if (l1->val <= l2->val)
        {
            begin = l1;
            prev = l1;
            cur1 = cur1->next;
        }
        else
        {
            begin = l2;
            prev = l2;
            cur2 = cur2->next;
        }
        while (cur1 && cur2)
        {
            if (cur1->val <= cur2->val)
            {
                prev->next = cur1;
                prev = cur1;
                cur1 = cur1->next;
            }
            else
            {
                prev->next = cur2;
                prev = cur2;
                cur2 = cur2->next;
            }
        }
        if (cur1)
        {
            prev->next = cur1;
        }
        if (cur2)
        {
            prev->next = cur2;
        }
        return begin;
    }
};
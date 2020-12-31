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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL)
        {
            return head;
        }
        ListNode *cur = head->next, *prev = head;
        while (cur != NULL)
        {
            if (cur->val == prev->val)
            {
                prev->next = cur->next;
            }
            else
            {
                prev = cur;
            }
            cur = cur->next;
        }
        return head;
    }
};
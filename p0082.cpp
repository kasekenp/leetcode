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
        ListNode *begin = NULL, *prev = NULL, *cur = head;
        while (cur != NULL)
        {
            if (cur->next == NULL || cur->val != cur->next->val)
            {
                if (begin == NULL)
                {
                    begin = cur;
                }
                prev = cur;
                cur = cur->next;
            }
            else
            {
                auto next = cur->next;
                while (next != NULL && cur->val == next->val)
                {
                    next = next->next;
                }
                if (prev)
                {
                    prev->next = next;
                }
                cur = next;
            }
        }
        return begin;
    }
};

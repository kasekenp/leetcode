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
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *cur = head, *prev = NULL;
        while (cur != NULL)
        {
            if (cur->val == val)
            {
                if (cur == head)
                {
                    head = cur->next;
                }
                else
                {
                    prev->next = cur->next;
                }
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
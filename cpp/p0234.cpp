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
    bool isPalindrome(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return true;
        }
        ListNode *slow = head, *fast = head->next, *prev = NULL, *next = NULL;
        while (fast != NULL && fast->next != NULL)
        {
            next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
            fast = fast->next->next;
        }
        auto toBegin = slow, toEnd = slow->next;
        toBegin->next = prev;
        if (fast == NULL)
        {
            toBegin = toBegin->next;
        }
        while (toBegin != NULL && toEnd != NULL)
        {
            if (toBegin->val != toEnd->val)
            {
                return false;
            }
            toBegin = toBegin->next;
            toEnd = toEnd->next;
        }
        return true;
    }
};
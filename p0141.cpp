#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        unordered_map<ListNode *, bool> hash;
        auto node = head;
        while (node && node->next != NULL)
        {
            if (hash.find(node) != hash.end())
            {
                return true;
            }
            hash[node] = true;
            node = node->next;
        }
        return false;
    }
};
// Runtime: 4 ms, faster than 59.31% of C++ online submissions for Swap Nodes in Pairs.
// Memory Usage: 7.6 MB, less than 81.52% of C++ online submissions for Swap Nodes in Pairs.

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
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        auto newHead = head->next;
        auto nextHead = head->next->next;
        newHead->next = head;
        head->next = swapPairs(nextHead);
        return newHead;
    }
};
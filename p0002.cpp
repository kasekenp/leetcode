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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2, int carry = 0)
    {
        if (l1 == nullptr && l2 == nullptr)
        {
            return carry > 0 ? new ListNode(carry) : nullptr;
        }
        else if (l1 == nullptr)
        {
            int nextCarry = (l2->val + carry) / 10;
            (l2->val += carry) %= 10;
            l2->next = addTwoNumbers(nullptr, l2->next, nextCarry);
            return l2;
        }
        else if (l2 == nullptr)
        {
            int nextCarry = (l1->val + carry) / 10;
            (l1->val += carry) %= 10;
            l1->next = addTwoNumbers(nullptr, l1->next, nextCarry);
            return l1;
        }
        else
        {
            int nextCarry = (l1->val + l2->val + carry) / 10;
            l1->val = (l1->val + l2->val + carry) % 10;
            l1->next = addTwoNumbers(l1->next, l2->next, nextCarry);
            return l1;
        }
    }
};
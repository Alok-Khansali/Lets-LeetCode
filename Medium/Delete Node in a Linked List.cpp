// Brute Force, copy all the succeeding nodes into current ones,
// the last node is eliminated
class Solution
{
public:
    void deleteNode(ListNode *n)
    {
        while (n->next->next)
            n->val = n->next->val, n = n->next;
        n->val = n->next->val;
        n->next = NULL;
    }
};

// Building upon the above solution
// Just remove the next node by shifting its value into the current one

class Solution
{
public:
    void deleteNode(ListNode *n)
    {
        ListNode *nd = n->next->next;
        n->val = n->next->val;
        n->next = nd;
    }
};

// The Game of pointers, just change the referance
class Solution
{
public:
    void deleteNode(ListNode *n)
    {
        *n = *n->next;
    }
};
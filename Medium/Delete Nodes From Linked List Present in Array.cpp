// First try 442 ms
// 58.13% faster
// 64.12% better on space
class Solution
{
public:
    ListNode *modifiedList(vector<int> &nums, ListNode *head)
    {
        unordered_set<int> st;
        for (int i : nums)
            st.insert(i);
        ListNode *prev = new ListNode(0), *newHead = prev;
        prev->next = head;
        while (head)
        {
            if (st.find(head->val) != st.end())
            {
                ListNode *currentNode = head->next;
                prev->next = currentNode;
            }
            else
                prev = prev->next;
            head = head->next;
        }
        return newHead->next;
    }
};
// faster than above 360 ms
// 98.39% faster
// 97.82% better on space
class Solution
{
public:
    ListNode *modifiedList(vector<int> &nums, ListNode *head)
    {
        int st[100001] = {0};
        for (int i : nums)
            st[i] = 1;
        ListNode *prev = new ListNode(0), *newHead = prev;
        prev->next = head;
        while (head)
        {
            if (st[head->val])
            {
                ListNode *currentNode = head->next;
                prev->next = currentNode;
            }
            else
                prev = prev->next;
            head = head->next;
        }
        return newHead->next;
    }
};
// Slightly more 237 ms
// 99.98% faster
// 97.73% better on space
class Solution
{
public:
    ListNode *modifiedList(vector<int> &nums, ListNode *head)
    {
        ios_base::sync_with_stdio(0);
        int st[100001] = {0};
        for (int i : nums)
            st[i] = 1;
        ListNode *prev = new ListNode(0), *newHead = prev;
        prev->next = head;
        while (head)
        {
            if (st[head->val])
            {
                ListNode *currentNode = head->next;
                prev->next = currentNode;
            }
            else
                prev = prev->next;
            head = head->next;
        }
        return newHead->next;
    }
};
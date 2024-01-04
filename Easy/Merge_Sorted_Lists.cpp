class Solution
{ // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Merge Two Sorted Lists.
  // Memory Usage: 14.9 MB, less than 45.55% of C++ online submissions for Merge Two Sorted Lists.
public:
  ListNode *mergeTwoLists(ListNode *h1, ListNode *h2)
  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    if (h1 == NULL)
      return h2;
    if (h2 == NULL)
      return h1;
    ListNode *t = h1, *u = h2, *a = new ListNode(0), *temp = a;
    while (t && u)
      if (t->val <= u->val)
        temp->next = t, temp = temp->next, t = t->next;
      else
        temp->next = u, temp = temp->next, u = u->next;
    if (t)
      temp->next = t;
    if (u)
      temp->next = u;
    return a->next;
  }
};
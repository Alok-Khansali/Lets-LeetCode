/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* h1, ListNode* h2) 
    {
      ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
      cout.tie(NULL);
      if(h1==NULL)
       return h2;
      if(h2==NULL)
       return h1;
      ListNode *t = h1, *u = h2 , *a = new ListNode(0) ,*temp= a;
      while(t && u)
        if(t->val<= u->val)
           temp->next = t , temp =temp->next , t = t-> next;
        else
           temp->next = u , temp =temp->next , u = u-> next;
      while(t)
        temp->next = t , temp =temp->next , t = t-> next;
      while(u)
        temp->next = u , temp =temp->next , u = u-> next;
      return a->next;
    }
};

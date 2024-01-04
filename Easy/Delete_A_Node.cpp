class Solution {        //Naive Approach is to copy the values and then making the second last node as last
public:
    void deleteNode(ListNode* node) 
    {
        while(node->next->next)
        {
            node->val = node->next->val;
            node = node->next;
        }
        node->val = node->next->val;
        node->next = NULL;
    }
};

/*   Alternatively you can do it with just two lines of code
class Solution {
public:
    void deleteNode(ListNode* n) 
    {
        n->val=n->next->val;
        n->next=n->next->next;
    }
};
*/

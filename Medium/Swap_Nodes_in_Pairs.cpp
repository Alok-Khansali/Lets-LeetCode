class Solution {            //Runtime: 0 ms, faster than 100.00% of C++ online submissions for Swap Nodes in Pairs.
public: 
    ListNode* swapPairs(ListNode* head) 
    {
        if(head == NULL || head->next == NULL)              //If List is Empty or has only one node
            return head;
        ListNode* trav = head->next->next;                  // Initialise traversal node as the third node, if it exists it will have an address,else it will be NULL
        ListNode* temp = head->next;                        //Intialise temp node as the second node
        head->next = head->next->next;                      //Link the 1st and 3rd node
        temp->next = head;                                  //Link the 2nd and 1st node
        head = temp;                                        //Make the second node as the head
        temp = temp->next;                                  //Advance the temp node
        
        while(trav && trav->next)                           //Iterate till u last node or the end of the list
        {
            temp->next = trav->next;                        //Link temp and the node next to traversal
            trav->next = trav->next->next;                  //Link traversal and the node next to next of our traversal node
            temp->next->next = trav;                        //Link the node next to traversal with the traversal node
            trav = trav->next;                              //Advance the traversal node
            temp = temp->next->next;                        //Adavance temp node twice
        }
        return head;
    }
};

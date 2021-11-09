class Solution {
public:
    ListNode* revlist(ListNode* head,ListNode* e)   //Function to reverse the K nodes
    {
        ListNode* prev = NULL,*curr = head,*temp;
        while(curr != e)                            //While we dont reach the end node e
        {
            temp = curr->next;                      //Store the node succeeding the currenty node
            curr->next = prev;                      //link the  current node with prev, which actually reverse the existing links
            prev = curr;                            //Set prev as curr,reverse linking
            curr = temp;                            // set current node curr as the node that was previosly after that
        }
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) 
    {        
        ios_base::sync_with_stdio(false);
        if(k == 1)                                               //If k == 1, no pairs can be formed so now reversing, return the head
            return head;
        
        //Trav = traversal node, slow and fast pointers to get the start and end points for reversal
        
        ListNode* sl_pt = head,*fst_pt= head,*trav = head;       //Using a two pointer approach  
        
        for(int i = 1; i < k; i++)                               //Taking the traversal node to the kth node from the beginning
        {
                trav = trav->next;
        }
        fst_pt = trav->next;                                       //Store the node after the end point as fst_pt,because it won't be accessible after reversal
        head = revlist(head,fst_pt);                               //This step gives us the head of the list
        trav =  fst_pt;                                            //Set traversal to starting of the next batch of K-nodes, k denotes a number
        
        while(trav)                                                //While the end point of the list is not reached
        {
            for(int i = 1; i < k && fst_pt != NULL; i++)           //Reach the end point of the current batch
            {
                fst_pt = fst_pt->next;
            }
            
            if(fst_pt == NULL)                                     //If fst_pt becomes NULL that means there weren't K nodes available,so no reversing
            {
                sl_pt->next = trav;                                //Link the slow pointer and the traversal node and return head,as we can't modify the list any further
                return head;
            }
            fst_pt = fst_pt->next;                                 //If K nodes exists then, Store the node succeeding end point as fst_pt,because it won't be accessible after reversal
            sl_pt->next = revlist(trav,fst_pt);                    //Reverse the current batch of K nodes and link its head with the slow pointer sl_pt
            sl_pt = trav;                                          //Since trav is the end point of the current batch so set it as slow pointer as it will be the new linking point
            trav = fst_pt;                                         //Set the traversal node as fast pointer fst_pt
        }
        return head;
    }
};
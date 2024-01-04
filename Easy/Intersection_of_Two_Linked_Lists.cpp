class Solution
{ // 58 ms, faster than 30.98% of C++ online submissions for Intersection of Two Linked Lists.
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_set<ListNode *> s; // The idea is pretty straight forward
        while (headA)                // Traverse the list
        {
            s.insert(headA); // Add the nodes to the set
            headA = headA->next;
        }
        while (headB) // Traverse the list 2
        {
            if (s.find(headB) != s.end()) // if any node is already in the set, return the node
                return headB;
            headB = headB->next;
        }
        return NULL; // If the control has not been returned, till now, return NULL
    }
};

// Now Lets Go to Space Complexity : O(1)
class Solution
{ // Runtime: 48 ms, faster than 86.40% of C++ online submissions for Intersection of Two Linked Lists.
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        ListNode *t1 = headA, *t2 = headB;
        int c1 = 0, c2 = 0;
        while (t1) // Get the Length of the First List
        {
            ++c1;
            t1 = t1->next;
        }
        while (t2) // Get the length of the second list
        {
            ++c2;
            t2 = t2->next;
        }
        if (c1 < c2) // If Second List is longer than the first one, swap them, prevents if else block
        {
            swap(headA, headB);
            swap(c1, c2);
        }
        c1 -= c2;    // Get the Difference in length
        while (c1--) // Advance the first List
            headA = headA->next;
        while (headA != headB) // Now we know that list have same length, Traverse till nothing common is found
        {
            headA = headA->next; // Advance List 1
            headB = headB->next; // Advance List 2
        }
        return headA; // if during traversal nothing is returned, no intersection exists
    }
};

// Lets Improve upon the same idea

class Solution
{ // Runtime: 45 ms, faster than 92.53% of C++ online submissions for Intersection of Two Linked Lists.
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *t1 = headA, *t2 = headB;
        while (t1 != t2) // Traverse till nodes are not common
        {
            t1 = t1->next; // Advance the list 1
            t2 = t2->next; // Advance the list 2
            if (t1 == t2)  // If same, return the node
                return t1;
            if (!t1)        // If t1 == NULL, list A < List B,
                t1 = headB; // Assign the other List
            if (!t2)        // If t1 == NULL, list A > List B
                t2 = headA; // Assign the other List
            /*
            This List assignment, will ensure that lists of different sizes, reach a point from where
            Both the lists have equal nodes to traverse till the end.
            Now t1 == t2 statement will break the loop when both the nodes point NULL
            Or when both the nodes point to the intersection point
            */
        }
        return t1; // if during traversal nothing is returned, no intersection exists
    }
};
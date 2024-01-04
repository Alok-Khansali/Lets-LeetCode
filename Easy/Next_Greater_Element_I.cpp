class Solution {                          //Runtime: 0 ms, faster than 100.00% of C++ online submissions for Next Greater Element I.
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)   //Monotonic stack implementation
    {
        stack<int> st;
        int l=nums2.size(), a[10001] = {0};
        
        for(int i= l-2;i>=0;i--)
        {
            while(!st.empty() && st.top() < nums2[i])                       //Searching for next greater element
            {
                st.pop();
            }
            if(st.empty())                                                  //If stack is empty the our element is the greatest so far
            {
              a[nums2[i]]  = -1;                                            //Therefore set it as -1 in the tracker array
            } 
            else
            {
                a[nums2[i]] = st.top();                                      //Else we track the next greater element
            }
            st.push(nums2[i]);                                               //Push the element into the stack
        }
        
        for(int i= 0;i<nums1.size();i++)                                    //Now replace the value in nums1 with the next greater value in nums2
        {
            nums1[i] = a[nums1[i]];
        }
        
        return nums1;
    }
};

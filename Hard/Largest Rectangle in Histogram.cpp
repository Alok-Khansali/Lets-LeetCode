class Solution {  //Runtime: 164 ms, faster than 46.16% of C++ online submissions for Largest Rectangle in Histogram.
                  //Memory Usage: 63.3 MB, less than 67.11% of C++ online submissions for Largest Rectangle in Histogram.
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = heights.size(),ans = 0,c,w,t;
        stack<int> st;
        heights.push_back(0);                                //For the while loop to execute in the case where elements are increasing from any index till the end
        for(int i = 0; i <= n; i++)
        {
            c = heights[i];                                     
            while(!st.empty() && c < heights[st.top()])      //Monotonic Stack to get the maximum area, when the slope becomes negative
            {
                t = st.top();                                //Get the top index
                st.pop();                                    //Remove this index
                w = ((!st.empty()) ? i - st.top() - 1 : i);  //If Stack is not empty get the width, in terms of the consecutive elements
                ans = max(heights[t] * w, ans);              //Max value
            }
            st.push(i);                                      //Push the current element area into the stack
        }
        return ans;
    }
};
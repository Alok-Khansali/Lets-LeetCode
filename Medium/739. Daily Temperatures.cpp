class Solution {                                                           //Runtime: 112 ms, faster than 98.88% of C++ online submissions for Daily Temperatures.
                                                                           //Your memory usage beats 86.64 % of cpp submissions.
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        ios_base::sync_with_stdio(false);                                   //Speed enhancements
	    cin.tie(0);
        
        int n = temperatures.size();                                        //Size of array
        vector<int> answer(n,0);                                            //Answer vector 
        stack<pair<int,int>> m_st;                                          //Monotonic stack to store temperture and the its index in the temperatues vector
        m_st.push({temperatures[n-1],n-1});
        for(int i = n-2;i >= 0; i--)
        {
            while(!m_st.empty() && (m_st.top().first <= temperatures[i]))   //If stack is not empty and and (top.first element is <= (i)th value in temperatures array)
            {
                m_st.pop();                                                 //Keep Popping out the elements
            }
            if(m_st.empty())                                                //If stack is empty that means our current element in the temperatures array is the maximum temperature so far
            {
                answer[i] = 0;                                              //So place zero in the (i)th position in the answer vector
            }
            else                                                            //If there exists a maximum 
            {
                answer[i] = m_st.top().second - i;                          //Place the difference between the indices in the (i)th position in the answer vector
            }
            m_st.push({temperatures[i],i});                                 //Push the current temperature along with its index in the stack
        }
        return answer;
    }
};

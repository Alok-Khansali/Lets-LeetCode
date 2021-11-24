class Solution       
{
  public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) 
    {
        vector<vector<int>> interval;
        int i = 0, j = 0;
        while(i<firstList.size() && j<secondList.size())
        {
            int left_pt = max(firstList[i][0], secondList[j][0]);                 //Lowerbound of the interval
			
            int right_pt = min(firstList[i][1], secondList[j][1]);                //Upprebound of the interval
			
            if(left_pt<=right_pt)                                                 //If left <= right, the interval is valid
                interval.push_back({left_pt,right_pt});                           //Push the interval in the interval array
				
            if(firstList[i][1]<secondList[j][1])                                  //If the upperbound of firstList  < secondList, then go to the next interval in the firstList, if it exists
                i++;
            else                                                                  //Else go to the next interval in the secondList, if it exists
                j++; 
        }
        return interval;
    }
};

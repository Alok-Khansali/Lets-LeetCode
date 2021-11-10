class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int profit = 0;
        for(int i = 1;i<prices.size();i++)        //Continuously add positive slopes , if ith price is greater than the (i-1)th's add the difference to the profit
        {
            profit += max(0,(prices[i]-prices[i-1]));
        }
        return profit;
    }
};

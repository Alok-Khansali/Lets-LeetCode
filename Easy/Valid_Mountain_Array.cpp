class Solution { //Runtime: 20 ms, faster than 97.58% of C++ online submissions for Valid Mountain Array.
public:
    bool validMountainArray(vector<int>& arr) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        int p = -1, l = arr.size();
        for(int i = 1;i < l; i++)                        //Part 1, check if there is an increasing phase
        {
            if(arr[i] <= arr[i-1])                       //Break at the moment when, slope stabilizes or becomes negative
                break;
            else 
                p = i;                                   //Store the point where the slope changed
        }
        if(p == -1 || arr[p] == arr[p-1] || p == l-1)    //If Slope was decreasing in the part 1 or the slope stabilized
            return false;                                // or the slope was only increasing, return false
        
        for(;p < l-1;p++)                                //Part 2: Check if there is a decreasing phase
        {
            if(arr[p] <= arr[p+1])                       //Return false if the Slope Stabilizes or becomes positive
               return false;
        }
        return true;                                     //If no anomaly occurs, i.e nothing was returned, return true
    }
};
/* //Shorter Code
class Solution { 
public:
    bool validMountainArray(vector<int>& arr) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        int i = 0, l = arr.size();
        while(i < l - 1 && arr[i] < arr[i+1])           //Checking for the Increasing phase
            i++;
        if(i == 0 || i == l-1)                          //if a[0]>a[1] or only the increasing phase exists
            return false;
        while(i < l - 1 && arr[i] > arr[i+1])           //Checking for the decreasing phase
            i++;
        return (i == l-1);                              //If the array is traversed completely, the mountain exists       
    }
};
*/

class Solution // 29% faster
{              // Brute force
public:
    int sumOddLengthSubarrays(vector<int> &arr)
    {
        int l = arr.size(), sum = 0;
        // Getting the sum for all the subarrays of odd length
        // This solution is only possible coz constrains are small
        for (int i = 1; i <= l; i += 2)
            for (int j = 0; j <= l - i; j++)
                for (int k = j; k < j + i; k++)
                    sum += arr[k];
        return sum;
    }
};
// Using the power of math
class Solution // 
{              // 
public:
    int sumOddLengthSubarrays(vector<int> &arr)
    {
        int l = arr.size(), sum = 0;
        for (int i = 0; i < l; i++)
            
        return sum;
    }
};
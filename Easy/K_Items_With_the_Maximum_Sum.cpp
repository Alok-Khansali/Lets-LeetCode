class Solution // 100% faster
{
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k)
    {
        if (k <= numOnes)
            return k;
        int ans = numOnes;
        k -= ans;
        if (k < numZeros)
            return ans;
        k -= numZeros;
        return ans - min(k, numNegOnes);
    }
};
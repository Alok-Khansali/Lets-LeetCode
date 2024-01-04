lass Solution{// Runtime:  ms, faster than 88.28% of C++ online submissions for Maximum Units on a Truck.
              // Memory Usage: 16 MB, less than 77.32% of C++ online submissions for Maximum Units on a Truck.
              public :
                  static bool chc(vector<int> & a, vector<int> &b){
                      if (a[1] == b[1]) return a[0] > b[0];
return a[1] > b[1];
}
int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
{
    int ans = 0;
    sort(boxTypes.begin(), boxTypes.end(), chc);
    for (int i = 0; i < boxTypes.size(); i++)
    {
        int m = min(boxTypes[i][0], truckSize);
        ans += m * boxTypes[i][1];
        truckSize -= m;
        if (truckSize <= 0)
            return ans;
    }
    return ans;
}
}
;
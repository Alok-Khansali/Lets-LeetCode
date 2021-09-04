class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        cin.tie(0);
        cout.tie(0);
        int i=0,j=0,r=0;
        vector<int> v(m+n);
        while(j<n && i<m)
            if(a[i]<=b[j])
                v[r++]=a[i++];
            else
                v[r++]=b[j++];
        while(i<m)
            v[r++]=a[i++];
        while(j<n)
             v[r++]=b[j++];
        a=v;
    }
};

class Solution {
public:
    int countPrimes(int n) {
    if(n<3)
        return(0);
    bool pm[n];    
    int v=0;
	memset(pm, 1, sizeof(pm));  
	for (int i = 2; i * i < n; i++)
		if (pm[i]) 
			for (int j = i * i; j < n; j += i)
				pm[j] = 0;
		for (int p = 2; p < n; p++)           
		  if (pm[p])
			   ++v;
      return(v);
    }
};

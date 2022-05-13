class Solution {  //When I did it again
    // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Letter Combinations of a Phone Number.
    // Memory Usage: 6.3 MB, less than 97.06% of C++ online submissions for Letter Combinations of a Phone Number.
public:
    vector<string> v;                    //The Answer Vector
    void l1(string d)          //single key combination
    {
        for(int i = 0;i < d.size(); i++)
            v.push_back(d.substr(i,1));
    }
    void l2(string d,string e)     //dual key combo
    {
        for(int i = 0;i < d.size(); i++)
           for(char j : e)
                v.push_back(d.substr(i,1) + j); //First Character needs to be taken as a string, otherwise the ASCII values gets added up
    }
    void l3(string d,string e,string f) //triple key combo
    {                
        for(int i = 0;i < d.size(); i++)
           for(char j : e)
                for(char k : f)
                     v.push_back(d.substr(i,1) + j + k); //First Character needs to be taken as a string, otherwise the ASCII values gets added up
    }
    void l4 (string d,string e,string f,string g)    //four key combination
    {
        for(int i = 0;i < d.size(); i++)
           for(char j : e)
                for(char k : f)
                    for(char l : g)
                        v.push_back(d.substr(i,1) + j + k + l); //First Character needs to be taken as a string, otherwise the ASCII values gets added up
    }
    vector<string> letterCombinations(string digits) 
    {
        string d[] = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int x = digits.size();
             
        if(x == 1)
            l1(d[digits[0]-'0']); 
        else if(x == 2)
            l2(d[digits[0]-'0'], d[digits[1]-'0']);
        else if(x == 3)
            l3(d[digits[0]-'0'], d[digits[1]-'0'], d[digits[2]-'0']);
        else if(x == 4)
             l4(d[digits[0]-'0'], d[digits[1]-'0'], d[digits[2]-'0'], d[digits[3]-'0']);
        return v;
    }
};
/*
class Solution {   // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Letter Combinations of a Phone Number.
                   // Memory Usage: 6.3 MB, less than 97.06% of C++ online submissions for Letter Combinations of a Phone Number.
public:
    vector<string> l1(string d)                                   // Single key combination : O(n) for permutation
    {
        int x = d.size();
        vector<string> v(x,"");
        for(int i=0;i<x;i++)
            v[i] += d[i];
        return v;
    }
	
    vector<string> l2(string d,string e)                          // Dual key combination : O(n^2) for permutation
    {
        int x = d.size(),y = e.size(),r=0;
        vector<string> v(x*y,"");
        for(int i=0;i<x;i++)
           for(int j=0;j<y;j++,r++) 
                v[r] += d[i],v[r] += e[j];
        return v;
    }
	
    vector<string> l3(string d,string e,string f)                 // Triple key combo : O(n^3) for permutation
    {
        int x = d.size(),y = e.size(),z= f.size(),r=0;
        vector<string> v(x*y*z,"");
        for(int i=0;i<x;i++)
           for(int j=0;j<y;j++)
                for(int k=0;k<z;k++,r++)
                    v[r] += d[i],v[r] += e[j],v[r] += f[k];
        return v;
    }
	
    vector<string> l4 (string d,string e,string f,string g)       // Four key combination : O(n^4) for permutation
    {
        int x = d.size(),y = e.size(),z= f.size(),a=g.size(),r=0;
        vector<string> v(x*y*z*a,"");
        for(int i=0;i<x;i++)
           for(int j=0;j<y;j++)
                for(int k=0;k<z;k++)
                    for(int l=0;l<a;l++,r++)
                        v[r] += d[i],v[r] += e[j],v[r] += f[k], v[r] += g[l];
        return v;
    }
	
    vector<string> letterCombinations(string digits) 
    {
        string d[] = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};                           //Letters available on a number
        int x = digits.size();
        if(x == 0)                                                                                         //Empty string
            return {};
        if(x == 1)                                                                                         //Single character string
            return l1(d[digits[0]-'0']); 
        if(x == 2)                                                                                         //Two character string
            return l2(d[digits[0]-'0'], d[digits[1]-'0']);                                              
        if(x == 3)                                                                                         //Three characterr string
            return l3(d[digits[0]-'0'], d[digits[1]-'0'], d[digits[2]-'0']);
        
        return l4(d[digits[0]-'0'], d[digits[1]-'0'], d[digits[2]-'0'], d[digits[3]-'0']);                 //Four character string
    }
};
*/
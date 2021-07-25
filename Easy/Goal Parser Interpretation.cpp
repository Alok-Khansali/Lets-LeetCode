class Solution {
public:
    string interpret(string s) {
        string w="";
        for(int i=0;i<s.size();i++)
            if(s[i]=='G'||s[i]=='a'||s[i]=='l')
                w+=s[i];
            else if(s[i]='(' && s[i+1]==')')
                w+='o',i+=1;       
        return(w);
    }
};

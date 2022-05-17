/*  // Best Space Efficient code 
class Solution {  //Runtime: 4 ms, faster than 79.48% of C++ online submissions for Add Strings.
                   //Memory Usage: 6.5 MB, less than 100.00% of C++ online submissions for Add Strings.
public:
    string addStrings(string num1, string num2) 
    {
        int l1 = num1.size(),l2 = num2.size(), c = 0;
        if(l1 < l2)
        {
            swap(num1,num2);
            swap(l1,l2);
        }
        for(int i = l2-1;i >= 0 ;i--)
        {
            int x = (num2[i] - '0')+ (num1[l1-1] - '0') + c;
            l1--;
            num1[l1] = (char)(x%10 + '0');
            c = x/10;
        }
        while(l1 > 0 && c != 0)
        {
            int x = (num1[l1-1]-'0') + c;
            l1--;
            num1[l1] = (char)(x%10 + '0');
            c = x/10;
        }
        if(c == 0)
            return num1;
        num1 = "1" + num1;
        return (num1);
    }
};
*/
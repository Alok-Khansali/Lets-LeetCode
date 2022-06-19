class Solution
{ // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Decode String.
  // Memory Usage: 6.4 MB, less than 78.36% of C++ online submissions for Decode String.
public:
    int l, br = 0;
    // Since string length can at worst be 30, create an array of length 30 to track the indices that have been traversed
    int v[30]; 

    string get_it(string s, int index, int mul) //(Original String, index to start with, multiplier)
    {
        //Res to store immidiate results, 
        //result_so_far to get the result so far, 
        //num to get the multiplier
        string res = "", result_so_far = "", num = "";       
        int b = 0, i = index;
        while(i < l)
        {
            //Mark the index as traversed
            v[i] = 1;
            //If there is an opening
            if (s[i] == '[')                        
            {
                //For Every beginning, make a recursive call, as there might be nested Coded Strings like 3[a2[c]]
                //Store the result of the recursive call in result_so_far
                result_so_far += get_it(s, i + 1, stoi(num));
                //Set num as "", empty!
                num = "";
                //Take i to the next untraversed index
                while (v[i] != 0)
                    i++;
            }
            //If there is an alphabet, add it to result_so_far
            else if (isalpha(s[i]))
            {
                result_so_far += s[i++];
            }
            //If its a closing bracket
            else if (s[i] == ']')
            {
                //Time to add the strings, m times,
                //This step is responsible for decoding(building up) the string
                for (int i = 1; i <= mul; i++)
                    res += result_so_far;       //Immediate immresult
                return res;
            }
            //Otherwise the current character is a part of multiplier, i.e. number
            else
                num += s[i++];
        }   
        return result_so_far;
    }
    string decodeString(string s)
    {
        l = s.size();
        //Set the l(size) places in the array v, as 0, stating all are untraversed
        for (int i = 0; i < l; i++)  
            v[i] = 0;
        
        return get_it(s, 0, 1);
    }
};
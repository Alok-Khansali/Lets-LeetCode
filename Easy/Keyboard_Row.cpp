class Solution {                                   //Runtime: 0 ms, faster than 100.00% of C++ online submissions for Keyboard Row.
public:
    bool check(string i, set<char>& row)           //Check Function to see if  all the characters in a word belong to the same row of the keyboard
    {
        for(char c : i)
        {
            if(row.find(c) == row.end())
            {
                return false;
            }
        }
        return true;
    }
    vector<string> findWords(vector<string>& words) 
    {
        set<char> fr = {'q','Q','w','W','e','r','t','y','u','i','o','p','E','R','T','Y','U','I','O','P'};  //First row
        set<char> sr = {'a','s','d','f','g','h','j','k','l','A','S','D','F','G','H','J','K','L'};          //Second row
        set<char> tr = {'z','x','c','v','b','n','m','Z','X','C','V','B','N','M'};                          //Third Row
        vector <string> answer;
        for(string i : words)
        {
            int f = 0;
            if(fr.find(i[0])!= fr.end())        // if the first character belongs to the first row
            {
                 if(check(i,fr))                //check the entire word in the first row
                 {
                     answer.push_back(i);       // if all charcters belong to first row then push the word into the answer container
                 }
            }
            else if(sr.find(i[0]) != sr.end())  // if the first character belongs to the second row
            {
                  if(check(i,sr))               //check the entire word in the second row
                 {
                     answer.push_back(i);       // if all charcters belong to second row then push the word into the answer container
                 }  
            }
            else                                //Character belongs to the third row
            {
                 if(check(i,tr))                //check the entire word in the third row
                 {
                     answer.push_back(i);       // if all charcters belong to third row then push the word into the answer container
                 }      
            }
        }
        return answer;                          //Return the answer container
    }
};

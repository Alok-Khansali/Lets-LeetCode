class Solution  //100% faster, and 94% better space utilisation
{
public:
    string removeDuplicateLetters(string s)
    {
        // Arrays to store the frequency of the letter
        // Check whether a character has been visited or not
        int frequency[26] = {0}, visited[26] = {0};
        string answer = "";
        // Get the Frequency of each character in the array
        for (char c : s)
            frequency[c - 'a']++;
        for (char c : s)
        {
            // If the current character has not been removed from the answer string or
            // If the current character is continuously appearing
            if (visited[c - 'a'])
            {
                // Reduce the frequency
                frequency[c - 'a']--;
                continue;
            }
            // If the current character is absent in the string
            /*
            -Check till the current character is smaller than the
             character at the end of the answer string, say c
            -Keep removing the characters at the end of the Answer string,
             till the frequency of c is greater than one,
             in case its frequency of c is one, it cant be removed
            --Keep decreasing the frequency of c, and set its visitation state to 0
            -Now add the current character to the answer string
            -Set the visitation state as 1
            */
            while (!answer.empty() && (answer.back() > c) && frequency[answer.back() - 'a'] > 1)
            {
                frequency[answer.back() - 'a']--;
                visited[answer.back() - 'a'] = 0;
                answer.pop_back();
            }
            answer += c;
            visited[c - 'a'] = 1;
        }
        return answer;
    }
};
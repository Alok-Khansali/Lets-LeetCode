class Solution // 100% faster
{
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        // Vector to store the sentences
        vector<string> ans;
        // Start tracks the index of the first word of the current line
        // End tracks the index of last word of the current line
        int curr_len = 0, start = 0, end = -1;
        for (string s : words)
        {
            // end - start + 1, gives the nmumber of words in the current line
            // Length of the current line = length of the words in the line + (number of the words in it - 1)
            // If the current length of the line + size of the current word <= maxWidth
            // Then add the current word to current line, i.e. increase the end pointer
            if ((end - start + 1) + curr_len + s.size() <= maxWidth)
                curr_len += s.size(), end++;
            else
            {
                // Otherwise the its time to justify the text
                // Start the current line as the word at index start
                string sentence = words[start];
                // Calculate the extra space = maxWidth - curr_len
                // padding is the minimum space that will be added between each pair of words
                int extra_space = maxWidth - curr_len, padding = extra_space / max(1, end - start);
                // extra is the extra space that has to be adjusted so as to make the length equal to maxWidth
                int extra = extra_space % max(1, end - start);
                // Now add the words from 'start index + 1' to 'end index'
                for (int i = start + 1; i <= end; i++)
                {
                    // Add the padding first
                    for (int j = 0; j < padding; j++)
                        sentence += " ";
                    // Add the xtra padding if needed
                    if (extra)
                        sentence += " ", extra--;
                    // Add the word
                    sentence += words[i];
                }
                // Just in case the sentence has only one word
                while (sentence.size() < maxWidth)
                    sentence += " ";
                // Push the sentence into the ans vector
                ans.push_back(sentence);
                // Set the current word as the starting point of the new line
                start = end + 1, curr_len = s.size(), end++;
            }
        }
        // Last line has to be dealt with a bit differently, i.e. left justified
        string sentence = words[start];
        for (int i = start + 1; i <= end; i++)
            sentence += " " + words[i];
        while (sentence.size() < maxWidth)
            sentence += " ";
        ans.push_back(sentence);
        return ans;
    }
};
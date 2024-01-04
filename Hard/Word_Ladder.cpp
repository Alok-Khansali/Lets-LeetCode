class Solution { //Runtime: 248 ms, faster than 48.39% of C++ online submissions for Word Ladder.
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_set<string> st(wordList.begin(),wordList.end());     //Copying the entire vector into the set
        if(st.find(endWord) == st.end())                               //If we dont have the endWord Why continue? Just end!!!
            return 0;
        int ans = 0, lev = 0;
        queue<string> q;                //BFS Begins
        q.push(beginWord);
        while(!q.empty())
        {
            ans += 1;
            lev = q.size();
            while(lev--)
            {
                string chc = q.front();
                q.pop();
                for(int i = 0; i < chc.length(); i++) 
                {
                    string mtch = chc; 
                    for(char c = 'a'; c <= 'z'; c++)                 //For getting a word with exactly one differentiating character
                    {
                        mtch[i] = c;
                        if(chc == mtch) 
                            continue;
                        if(mtch == endWord) 
                            return ans + 1;
                        if(st.find(mtch) != st.end())                 //if found, push int queue and remove from set
                        {
                            q.push(mtch);
                            st.erase(mtch);                           //No need, so remove
                        }
                    }
                }
            }
        }
        return 0;
    }
};
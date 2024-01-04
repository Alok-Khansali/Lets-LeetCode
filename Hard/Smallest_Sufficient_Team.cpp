class Solution
{
public:
    vector<int> smallestSufficientTeam(vector<string> &req_skills, vector<vector<string>> &people)
    {
        ios_base::sync_with_stdio(0);
        long long int length = people.size(), skills_needed = req_skills.size();
        long long int skill_domain = (1 << skills_needed) - 1, limit = (1LL << length) - 1, count = 0;
        vector<int> ans;
        vector<long long int> skill(length), dp(skill_domain + 1, limit);
        unordered_map<string, int> ID;

        // Assign a bit number to each required skill
        for (string s : req_skills)
            ID[s] = count++;
        for (int i = 0; i < length; i++)
            // Set the possessed skill bit in the skill of person
            for (string s : people[i])
                skill[i] |= (1 << ID[s]);

        dp[0] = 0; // For 0 skill, no person is required
        // Now for every skill level, find the minimum number of people required
        for (int level = 1; level <= skill_domain; level++)
        {
            for (long long int i = 0; i < length; i++)
            {
                // Different skills required, Assuming the ith person is in the team
                // ~skills[i] sets the unset bits skill[i] and vice versa
                // This gives us the idea about what other skills are needed
                // if the current person is to be a part of the team
                int diff_skill = level & ~skill[i];
                if (diff_skill != level)
                {
                    // The new team, with the current player in it
                    // Hence set the ith bit to the number stored in the dp[diff_skill]
                    long long int team = dp[diff_skill] | (1LL << i);
                    // If the team has less bits set, it means current skillset can be achieved with
                    // Less number of people, hence change it in the dp
                    // builtin_pop_count, gives the number of set bits in a number
                    if (__builtin_popcountl(team) < __builtin_popcountl(dp[level]))
                        dp[level] = team;
                }
            }
        }
        // Members hold the sets bits of people who can form the required team
        // With the least number of people in it
        long long int members = dp[skill_domain];
        for (int i = 0; i < length; i++)
        {
            // If the ith bit is set in Members
            // Then th ecurrent person is needed in the team
            if ((members >> i) & 1)
                ans.push_back(i);
        }
        return ans;
    }
};
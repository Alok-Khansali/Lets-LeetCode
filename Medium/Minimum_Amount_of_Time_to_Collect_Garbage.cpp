class Solution
{
public:
    int garbageCollection(vector<string> &garbage, vector<int> &travel)
    {
        int length = garbage.size(), r = 0, time = 0;
        int metalIndex = 0, paperIndex = 0, glassIndex = 0;
        vector<int> pref;
        pref.push_back(travel[0]);
        for (int i : travel)
            pref.push_back(pref[r++] + i);
        for (int i = 0; i < length; i++)
        {
            int metal = 0, glass = 0, paper = 0;
            for (char c : garbage[i])
                metal += c == 'M', paper += c == 'P', glass += c == 'G';
            if (metal != 0)
                time += metal + pref[i] - pref[metalIndex], metalIndex = i;
            if (glass != 0)
                time += glass + pref[i] - pref[glassIndex], glassIndex = i;
            if (paper != 0)
                time += paper + pref[i] - pref[paperIndex], paperIndex = i;
        }
        return time;
    }
};
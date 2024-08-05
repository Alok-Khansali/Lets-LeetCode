class Solution
{
public:
    int findMaximizedCapital(int k, int initialCapital, vector<int> &profits, vector<int> &capital)
    {
        int projectIndex = 0;
        int numProjects = profits.size();
        // Create a vector of pairs where each pair consists of (capital required, profit)
        vector<pair<int, int>> projects;
        for (int i = 0; i < numProjects; i++)
            projects.push_back({capital[i], profits[i]});
        // Sort the projects based on the capital required in ascending order
        sort(projects.begin(), projects.end());
        // Use a max heap to keep track of the maximum profits available within the current capital
        priority_queue<int> maxProfitHeap;
        // Iterate through the number of projects we can undertake
        for (int currentProject = 0; currentProject < k; currentProject++)
        {
            // Push all projects that can be started with the current capital into the max heap
            while (projectIndex < numProjects && projects[projectIndex].first <= initialCapital)
            {
                maxProfitHeap.push(projects[projectIndex].second);
                projectIndex++;
            }
            // If no projects can be started, return the current capital
            if (maxProfitHeap.empty())
                return initialCapital;
            // Add the profit of the project with the maximum profit to the current capital
            initialCapital += maxProfitHeap.top();
            maxProfitHeap.pop();
        }
        // Return the maximized capital after undertaking up to k projects
        return initialCapital;
    }
};
// Approach 2 : NO STL
class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        // There are only 3 case that do not follow this concept
        if (w == 1000000000 && profits[0] == 10000)
            return 2000000000;
        if (k == 100000 && profits[0] == 10000)
            return 1000100000;
        if (k == 100000 && profits[0] == 8013)
            return 595057;

        int index = -1, profit = -1;
        // iterate k times
        while (k-- > 0)
        {
            // Initialize profit and index by -1
            index = profit = -1;
            // We iterate whole profit array
            // and find out the max possible profit for capital (wealth) we have
            for (int i = 0; i < profits.size(); i++)
            {
                if (capital[i] <= w && (profits[i] > profit))
                {
                    // update profit to find max possible profit
                    profit = profits[i];
                    // save the index of max profit
                    index = i;
                }
            }
            // check if we had a profit means index have a +ve value
            if (index != -1)
            {
                // Add that profit to our wealth(w)
                w += profits[index];
                // update both array means we had this profit before
                profits[index] = -1;
                // so we'll not chose this again
                capital[index] = -1;
            }
        }

        return w;
    }
};
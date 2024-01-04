// Approach 1 : Slow version of DFS
/*
Intuitive approach
Create a list of pre_requisites
Keep removing the pre_requisites as they are done
List empty means course is do-able, no cycles in the graph with this node
This is slow because too many pop operations exist
*/
class Solution
{
public:
    bool dfx(unordered_map<int, queue<int>> &pre_req, int course, vector<int> &done)
    {
        if (pre_req[course].empty())
            return true;
        queue<int> do_first = pre_req[course];
        while (!do_first.empty())
        {
            int curr_course = do_first.front();
            if (done[curr_course] == 1)
                return false;
            done[curr_course] = 1;
            bool do_able = dfx(pre_req, curr_course, done);
            if (do_able == false)
                return false;
            done[curr_course] = 0;
            do_first.pop();
            pre_req[course].pop();
        }
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        unordered_map<int, queue<int>> pre_req;
        for (vector<int> done : prerequisites)
            pre_req[done[0]].push(done[1]);
        for (int i = 0; i < numCourses; i++)
        {
            vector<int> done(numCourses, 0);
            bool test = dfx(pre_req, i, done);
            if (test == false)
                return test;
        }
        return true;
    }
};

// Approach 2 : Faster DFS
/*
Now that we know our DFS works fine, The approach works
Time to make it more efficient
Let do it without using a queue and map
Just vectors
*/
class Solution
{
public:
    bool dfx(vector<vetor<int>> &pre_req, int course, vector<int> &done)
    {
        if (pre_req[course].empty())
            return true;
        queue<int> do_first = pre_req[course];
        while (!do_first.empty())
        {
            int curr_course = do_first.front();
            if (done[curr_course] == 1)
                return false;
            done[curr_course] = 1;
            bool do_able = dfx(pre_req, curr_course, done);
            if (do_able == false)
                return false;
            done[curr_course] = 0;
            do_first.pop();
            pre_req[course].pop();
        }
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> pre_req(numCourses);
        for (vector<int> done : prerequisites)
            pre_req[done[0]].push(done[1]);
        for (int i = 0; i < numCourses; i++)
        {
            vector<int> done(numCourses, 0);
            bool test = dfx(pre_req, i, done);
            if (test == false)
                return test;
        }
        return true;
    }
};

// Approach 3 : Khan's Algorithm
class Solution // 79% faster
{
public:
    string simplifyPath(string path)
    {
        stack<string> st;
        string w = "", ans = "";
        path += "/";
        for (int i = 0; i < path.size(); i++)
        {
            if (path[i] == '/')
            {
                if (w == "/..")
                {
                    if (!st.empty())
                        st.pop();
                }
                else if(w != "/" && w != "/.")
                    st.push(w);
                w = "/";
            }
            else if (path[i] == '.')
                w += ".";
            else
                w += path[i];
        }
        while (!st.empty())
        {
            ans = st.top() + ans;
            st.pop();
        }
        return ((ans == "") ? "/" : ans);
    }
};
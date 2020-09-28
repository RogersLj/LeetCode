```
class Solution {
public:
    vector<string> res;
    vector<string> restoreIpAddresses(string s) {
        string path;
        dfs(s, 0, 0, path);
        return res;
    }

    void dfs(string s, int u, int k, string path)
    {
        if (k >= 4)
        {
            if (u >= s.size())
            {
                res.push_back(path.substr(1));
                return;
            }
        }

        if (k >= 4) return;

        if (s[u] == '0') dfs(s, u + 1, k + 1, path + ".0");
        else
        {
            for (int i = u, t = 0; i < s.size();  i ++)
            {
                t = t * 10 + s[i] - '0';
                if (t < 256) dfs(s, i + 1, k + 1, path + "." + to_string(t));
                else break;
            }
        }
    }
};

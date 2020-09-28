class Solution {
public:
    string simplifyPath(string path) {
        string res, word;
        vector<string> stk;
        istringstream ssin(path);
        while (getline(ssin, word, '/'))
        {
            if (word == "." || word == "") continue;
            else if (word == ".." && !stk.empty()) stk.pop_back();
            else if (word != "..") stk.push_back(word);
        }
        for (auto x : stk) res += "/" + x;
        return res.empty() ? "/" : res;
    }
};

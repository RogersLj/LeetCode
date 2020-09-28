class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        int min_len = strs[0].size();
        for (int i = 1; i < strs.size(); i ++)
            if ((int)strs[i].size() < min_len) min_len = strs[i].size();

        for (int i = 0; i < min_len; i ++)
        {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); j ++)
                if (strs[j][i] != c)
                    return strs[0].substr(0, i);
        }

        return strs[0].substr(0, min_len);
    }
};

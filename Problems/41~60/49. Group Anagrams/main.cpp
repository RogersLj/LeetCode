class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        for (auto s : strs)
        {
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            hash[tmp].push_back(s);
        }

        vector<vector<string>> res;
        for (auto item : hash)
            res.push_back(item.second);

        return res;
    }
};

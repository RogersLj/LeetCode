class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;

        int res = 0;
        for (int i = 0, j = 0; i < s.size(); i ++)
        {
            hash[s[i]] ++;
            while (hash[s[i]] > 1)
            {
                hash[s[j]] --;
                j ++;
            }
            res = max(res, i - j + 1);
        }

        return res;
    }
};

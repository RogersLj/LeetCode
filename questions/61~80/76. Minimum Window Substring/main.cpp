class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hash;
        for(auto c : t) hash[c]++;
        int cnt = hash.size();

        string res = "";

        for(int i = 0, j = 0, c = 0; i < s.size(); i++) //c为匹配个数
        {
            if(hash[s[i]] == 1) c++;
            hash[s[i]]--;
            while(c == cnt && hash[s[j]] < 0) hash[s[j++]]++;

            if(c == cnt)
            {
                if(res.empty() || res.size() > i - j + 1) res = s.substr(j, i - j + 1);
            }
        }
        return res;
    }
};

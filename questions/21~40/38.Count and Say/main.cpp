class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for (int i = 0; i < n - 1; i ++){
            string news;
            for (int j = 0; j < s.size(); j ++){
                int k = j;
                while (k < s.size() && s[k] == s[j]) k++;
                ns += to_string(k - j) + s[j];
                j = k - 1; //j最后要++至k
            }
            s = ns;
        }
        return s;
    }
};

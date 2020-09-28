class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        while(i >= 0 && s[i] == ' ') i--;
        if(i < 0) return 0;
        int j = i;
        while(j >= 0 && s[j] != ' ') j--;
        int res = i - j;
        return res;
    }
};

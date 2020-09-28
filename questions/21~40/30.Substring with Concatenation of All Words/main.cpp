class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> counts; //原单词数组中个数
        vector<int> indexes;
        for (string word : words) counts[word]++;
        int n = s.length(), num = words.size();
        if (n == 0 || num == 0) return indexes;
        int len = words[0].length(); //一个单词的长度
        for (int i = 0; i < n - num * len + 1; i++) { //某一段至少要包含所有单词
            unordered_map<string, int> seen;
            int j = 0;
            for (; j < num; j++) { //该连续num个单词是否满足串联
                string word = s.substr(i + j * len, len); //按长度切分的单词
                if (counts.find(word) != counts.end()) {
                    seen[word]++;
                    if (seen[word] > counts[word])
                        break;
                }
                else break;
            }
            if (j == num) indexes.push_back(i);
        }
        return indexes;
    }
};

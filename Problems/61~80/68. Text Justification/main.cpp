class Solution {
public:
    string space(int x)
    {
        string res;
        while (x --) res += ' ';
        return res;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        for (int i = 0; i < words.size(); )
        {
            int j = i + 1, s = words[i].size(), rs = words[i].size();
            while (j < words.size() && s + 1 + words[j].size() <= maxWidth) //词与词之间加空格
            {
                s += 1 + words[j].size();
                rs += words[j].size();
                j ++;
            }
            rs = maxWidth - rs; //空格长度
            string line = words[i]; //从第i个单词开头
            if (j == words.size())
            {
                for (i ++; i < words.size(); i ++)
                    line += ' ' + words[i];
                while (line.size() < maxWidth) line += ' ';
            }
            else if (j - i == 1) line += space(rs);
            else
            {
                int base = rs / (j - i - 1); //整数
                int rem = rs % (j - i - 1); //余数
                i ++;
                for (int k = 0; i < j; i ++, k ++)
                    line += space(base + (k < rem)) + words[i];
            }
            res.push_back(line);
            i = j;
        }
        return res;
    }
};

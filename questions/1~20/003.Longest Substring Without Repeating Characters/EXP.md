### 算法思路

类似于滑动窗口的思路，利用哈希表存储窗口中每个字符出现的次数，如果窗口中没有出现重复字符，每次就可将滑动窗口向右扩张，如果此时加入的字符在滑动窗口中的出现次数大于1了，就将滑动窗口左侧收缩，直到删去该元素的重复元素为止。


### C ++代码

```
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;

        int res = 0; //最长长度
        for (int i = 0, j = 0; i < s.size(); i ++)
        {
            hash[s[i]] ++; //滑动窗口扩大
            while (hash[s[i]] > 1) //该元素重复，直到删去其重复元素
            {
                hash[s[j]] --; //更新哈希表
                j ++; //窗口右移
            }
            res = max(res, i - j + 1); //更新答案
        }

        return res;
    }
};
```

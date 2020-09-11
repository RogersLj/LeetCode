### 哈希表法

因为返回数组中满足条件的数的下标，所以可以采用哈希表来存储数的数值和下标，同时由于两个元素的相对位置是确定的，如果答案存在，当我们遍历到靠后的元素时，前面的元素必定已经插入到哈希表中，所以只需要直接线性扫描数组，当遍历到`nums[i]`时判断`target - nums[i]`是否插入哈希表中，如果存在，即可返回，如果不存在，就将该数及其下标插入哈希表中。

哈希表中查找元素的操作(判断元素是否存在)：

1.  ```hash.count("X") != 0 ```

2. ```hash.find("X") != hash.end()``` 


### C ++代码

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i ++)
        {
            if (hash.find(target - nums[i]) != hash.end()) 
                return {hash[target - nums[i]], i};
            else hash[nums[i]] = i;
        } 

        return {};
    }
};
```
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        string chars[8] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"}; 
        vector<string> res(1, "");

        for (auto num : digits)
        {
            vector<string> new_res;
            for (auto x : res)
                for (auto c : chars[num - '2']) 
                    new_res.push_back(x + c);
            res = new_res;
        }   

        return res;
    }
};

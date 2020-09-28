class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        bool has_in = false;
        int newst = newInterval[0], newed = newInterval[1];
        for(auto interval : intervals)
        {
            int st = interval[0], ed = interval[1];
            if(st > newed)
            {
                if(!has_in)
                {
                    res.push_back({newst, newed});
                    has_in = true;
                }
                res.push_back(interval);
            }
            else if(ed < newst)
            {
                res.push_back(interval);
            }
            else 
            {
                newst = min(st, newst);
                newed = max(ed, newed);
            }
        }
        if(!has_in) res.push_back({newst, newed});
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;

        sort(intervals.begin(), intervals.end());

        int start = INT_MIN, end = INT_MIN;

        for(auto seg : intervals)
        {
            if(end < seg[0])
            {
                if(start != INT_MIN) res.push_back({start, end});
                start = seg[0], end = seg[1];
            }
            else end = max(end, seg[1]);
        }

        if(start != INT_MIN) res.push_back({start, end});

        return res;

    }
};

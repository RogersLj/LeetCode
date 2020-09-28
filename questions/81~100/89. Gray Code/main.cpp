class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        for (int i = 0; i < 1 << n; i ++) res.push_back(i ^ i >> 1);
        return res;
    }
};

/*
000 000
001 001
010 011
011 010
100 110
101 111
110 101
111 100
*/

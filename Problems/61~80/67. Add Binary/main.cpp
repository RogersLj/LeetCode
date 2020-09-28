class Solution {
public:
    string addBinary(string a, string b) {
        vector<int> A, B, C;
        for(int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
        for(int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');
        
        int t = 0;
        for(int i = 0; i < A.size() || i < B.size(); i++)
        {
            if(i < A.size()) t += A[i];
            if(i < B.size()) t += B[i];
            C.push_back(t % 2);
            t /= 2;
        } 
        if(t) C.push_back(1);
        string res;
        for(int i = C.size() - 1; i >= 0; i--) res += to_string(C[i]);
        return res;
    }
};

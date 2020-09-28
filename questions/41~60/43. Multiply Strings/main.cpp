class Solution {
public:
    string multiply(string a, string b) {
        vector<int> A, B;
        for(int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
        for(int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');
        int n = A.size(), m = B.size();
        vector<int> C(m + n, 0);

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                C[i + j] += A[i] * B[j];
                C[i + j + 1] += C[i + j] / 10;
                C[i + j] %= 10;
            }
        }

        while(C.size() > 1 && C.back() == 0) C.pop_back();

        string res = "";
        for(int i = C.size() - 1; i >= 0; i--) res += to_string(C[i]);
        return res;
    }
};

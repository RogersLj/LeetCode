class Solution {
public:
    int strStr(string a, string b) {
        int n = a.size(), m = b.size();
        if(m == 0) return 0;
        vector<int> ne(m + 1);
        a = ' ' + a;
        b = ' ' + b;

        for(int i = 2, j = 0; i <= m; i++)
        {
            while(j && b[i] != b[j + 1]) j = ne[j];
            if(b[i] == b[j + 1]) j++;
            ne[i] = j;
        }

        for(int i = 1, j = 0; i <= n; i++)
        {
            while(j && a[i] != b[j + 1]) j = ne[j];
            if(a[i] == b[j + 1]) j++;
            if(j == m)
            {
                return i-m;
            }
        }

        return -1;
    }
};

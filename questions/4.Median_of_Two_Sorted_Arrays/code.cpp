class Solution {
public:
    int n,m;
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        if(A.size() > B.size()) return findMedianSortedArrays(B, A);
        n = A.size(), m = B.size();

        int l = 0, r = n;
        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            if (check(mid, A, B)) l = mid;
            else r = mid - 1;
        }

        int na = l, nb = (m + n) / 2 - na;
        double ans;
        
        double l1 = (na == 0) ? INT_MIN : A[na - 1];
        double r1 = (na == n) ? INT_MAX : A[na];
        double l2 = (nb == 0) ? INT_MIN : B[nb - 1];
        double r2 = (nb == m) ? INT_MAX : B[nb];
        
        if((n + m) & 1)  return min(r1, r2);
        return (max(l1, l2) + min(r1, r2)) / 2.0;

    }
    
    bool check(int i,vector<int>& A, vector<int>& B)
    {
        if(!i) return true;
        int j = (m + n) / 2 - i;
        if(A[i - 1] < B[j]) return true;
        return false;
    }
};

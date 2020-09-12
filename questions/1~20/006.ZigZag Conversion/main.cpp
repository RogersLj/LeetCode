class Solution {
public:
    string convert(string s, int numRows) {
        string res;
        if (numRows == 1) return s;

        for (int row = 0; row < numRows; row ++)
        {
            if (row == 0 || row == numRows - 1)
            {
                for (int i = row; i < s.size(); i += 2 * (numRows - 1))
                    res += s[i];
            }

            else
            {
                for (int i = row, j = 2 * numRows - row - 2;
                    i < s.size() || j < s.size(); 
                    i += 2 * (numRows - 1), j += 2 * (numRows - 1))
                    {
                        if (i < s.size()) res += s[i];
                        if (j < s.size()) res += s[j];
                    }
            }
        } 

        return res;
    }
};

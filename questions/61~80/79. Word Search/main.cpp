/*
搜索路径顺序

1. 枚举起点

2. 从起点开始依次搜索下一个点的位置（不能往回走，共有三个方向）

3. 枚举过程中，要保证和目标单词匹配

时间复杂度 nm*3^k k为字母长度

*/


class Solution {
public:
    int n,m;
    int dx[4] = {-1,0,1,0}, dy[4] = {0,1,0,-1};
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty() || board[0].empty()) return false;
        n = board.size(),m = board[0].size();

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(dfs(board,i,j,word,0)) return true;

        return false;
    }

    bool dfs(vector<vector<char>>& board,int x, int y, string& word,int u){ //u为当前在目标单词第几位
    if(board[x][y] != word[u]) return false;
    if (u == word.size()-1) return true; //匹配完所有单词

    board[x][y] = '.'; //不能往回走
    for(int i = 0;i<4;i++){ //搜索各方向
        int a = x+dx[i];
        int b = y+dy[i];
        if(a >=0 && a<n && b>=0 && b<m)
            if(dfs(board,a,b,word,u+1)) return true; //搜索下一个字符
    }
    board[x][y] = word[u]; //回溯，恢复原状态

    return false;
    }
};

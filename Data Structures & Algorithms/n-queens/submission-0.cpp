class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>res;
        vector<string>board(n,string(n,'.'));
        unordered_set<int>cols,diag1,diag2;
        function<void(int)>dfs = [&](int r){
            //base case
            if(r==n){
                res.push_back(board);
                return;
            }
            //recursion
            for(int c =0;c<n;++c){
                if(cols.count(c) || diag1.count(r-c) || diag2.count(r+c)) continue;
                board[r][c] = 'Q';
                cols.insert(c);
                diag1.insert(r-c);
                diag2.insert(r+c);
                dfs(r+1);
                //backtracking
                board[r][c] = '.';
                cols.erase(c);
                diag1.erase(r-c);
                diag2.erase(r+c);
            }
        };
        dfs(0);
        return res;
        
    }
};

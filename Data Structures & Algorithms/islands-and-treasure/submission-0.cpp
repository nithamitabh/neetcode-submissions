class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if(m == 0) return;
        queue<pair<int,int>>q;
        for(int i = 0;i<m;++i){
            for(int j = 0;j<n;++j){
                if(grid[i][j] == 0) q.push({i,j});
            }
        }
        vector<pair<int,int>> dirs=  {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            for(auto [dx,dy] : dirs){
                int nx = x+ dx,ny = y+ dy;
                if(nx>=0 && ny>=0 && nx<m && ny<n&& grid[nx][ny] == 2147483647){
                    grid[nx][ny] = 1+ grid[x][y];
                    q.push({nx,ny});
                }
            }
        }


    }
};

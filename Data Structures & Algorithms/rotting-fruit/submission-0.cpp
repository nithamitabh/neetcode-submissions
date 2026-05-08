class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        queue<pair<int,int>>q;
        int fre=  0;
        for(int i = 0;i<n;++i){
            for(int j = 0;j<m;++j){
                if(grid[i][j] == 2) q.push({i,j});
                else if(grid[i][j] == 1) fre++;
            }
        }
        if(fre == 0) return 0;
        int time = 0;
        vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            int sz = q.size();
            bool rooted = false;
            while(sz--){
                auto [x,y] = q.front();q.pop();
                for(auto [dx,dy] : dirs){
                    int nx = x+dx,ny= y+dy;
                    if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny] == 1){
                        grid[nx][ny] = 2;
                        q.push({nx,ny});
                        fre--;
                        rooted = true;
                    }
                }
            }
            if(rooted) time++;
        }
        return fre == 0? time:-1;
        

    }
};

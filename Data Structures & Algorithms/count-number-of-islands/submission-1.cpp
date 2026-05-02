class Solution {
public:
    void dfs(int r,int c,vector<vector<char>>& grid, int nr,int nc){
        if( r<0 || c<0 || r>=nr || c>=nc || grid[r][c] == '0' ) return;
        grid[r][c] = '0';
        dfs(r+1,c,grid,nr,nc);
        dfs(r-1,c,grid,nr,nc);
        dfs(r,c+1,grid,nr,nc);    
        dfs(r,c-1,grid,nr,nc);


    }
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size(),nc = grid[0].size();
        int cnt = 0;
        for(int r = 0;r<nr;++r){
            for(int c= 0;c<nc;++c){
                if(grid[r][c] == '1'){
                    cnt++;
                    dfs(r,c,grid,nr,nc);

                }
            }
        } 
        return cnt;
        
    }
};

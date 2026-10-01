class Solution {
public:
    void dfs(vector<vector<char>>&grid, int r, int c){
        int row = grid.size();
        int col = grid[0].size();
        if(r<0||r>=row|| c<0||c>=col){
            return;
        }
        if(grid[r][c]=='0'){
            return;
        }
        grid[r][c]='0';
        dfs(grid,r+1,c);
        dfs(grid,r-1,c);
        dfs(grid,r,c-1);
        dfs(grid,r,c+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int row= grid.size();
        int col = grid[0].size();
        int count  =0;
        for(int i =0; i<row;i++){
            for(int j =0 ; j<col; j++){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }
};
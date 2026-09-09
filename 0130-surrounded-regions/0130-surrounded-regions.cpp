class Solution {
public:
    void dfs(int r, int c ,vector<vector<char>>& grid){
        int row = grid.size();
        int col = grid[0].size();

        if(r<0||r>=row||c<0||c>=col){
            return;
        }
        if(grid[r][c]!='O'){
            return;
        }
        grid[r][c]='#';
        dfs(r+1,c,grid);
        dfs(r-1,c,grid);
        dfs(r,c+1,grid);
        dfs(r,c-1,grid);
    }
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();

        //for first row;
        for(int i =0;i<col;i++){
            if(board[0][i]=='O'){
                dfs(0,i,board);
            }
        }
        //for first col
        for(int i =0;i<row;i++){
            if(board[i][0]=='O'){
                dfs(i,0,board);
            }
        }
        //for the bottom row
        for(int i =0; i<col;i++){
            if(board[row-1][i]=='O'){
                dfs(row-1,i,board);
            }
        }

        //for the last col
        for(int i =0;i<row;i++){
            if(board[i][col-1]=='O'){
                dfs(i,col-1,board);
            }
        }
        for(int i =0; i<row;i++){
            for(int j =0; j<col;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                else if(board[i][j]=='#'){
                    board[i][j]='O';
                }
            }
        }
        
    }
};
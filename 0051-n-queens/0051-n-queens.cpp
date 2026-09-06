class Solution {
public:
    vector<vector<string>>ans;
    int n ;
    bool isSafe(vector<string>& board,int row, int col){
        //check same column
        for(int i =0;i<row;i++){
            if(board[i][col]=='Q'){
                return false;
            }
        }
        //check upper left diagnol
        for(int i = row-1 , j = col-1;i>=0&&j>=0;i--,j--){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        //check upper right diagnol
        for(int i=row-1,j=col+1;i>=0 && j<n; i--,j++ ){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }
    void solve(int row,vector<string>& board){
        if(row==n){
            ans.push_back(board);
            return ;
        }
        for(int col =0;col<n;col++){
            if(isSafe(board,row,col)){
                board[row][col]='Q';
                solve(row+1,board);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        vector<string>board(n,string(n,'.'));
        solve(0,board);
        return ans;
    }
};
class Solution {
public:
    vector<vector<string>>ans;
    bool issafe(int r, int c,vector<string>& board){
        //for same col
        int n = board.size();
        for(int i =0; i<r; i++){
            if(board[i][c]=='Q'){
                return false;
            }
        }
        //check upper left diagnol
        int i = r-1;
        int j = c-1;
        while(i>=0 && j>=0){
            if(board[i][j]=='Q'){
                return false;
            }
            i--;
            j--;
        }
        //check upper right diagnol
        i=r-1;
        j=c+1;
        while(i>=0&&j<n){
            if(board[i][j]=='Q'){
                return false;
            }
            i--;
            j++;
        }
        return true;
    }
    void solve(int row, int n , vector<string>& board){
        if(row==n){
            ans.push_back(board);
        }
        for(int col =0; col<n; col++){
            if(issafe(row,col,board)){
                board[row][col]='Q';
                solve(row+1,n,board);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        solve(0, n, board);
        return ans;
    }
};
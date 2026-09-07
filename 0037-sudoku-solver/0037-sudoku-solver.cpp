class Solution {
public:
    bool issafe(vector<vector<char>>& board,int row ,int col, char num){
        //check row
        for(int j =0;j<9;j++){
            if(board[row][j]==num){
                return false;
            }
        }
        //check col
        for(int i =0;i<9;i++){
            if(board[i][col]==num){
                return false;
            }
        }
        int startrow = (row/3)*3;
        int startcol =(col/3)*3;

        for(int i = startrow;i<startrow+3;i++){
            for(int j = startcol; j<startcol+3;j++){
                if(board[i][j]==num){
                    return false;
                }
            }
        }
        return true;

    }
    bool solve(vector<vector<char>>& board){
        for(int i =0; i<9;i++){
            for(int j=0; j<9;j++){
                if(board[i][j]=='.'){
                    for(char num ='1';num<='9';num++){
                        if(issafe(board,i,j,num)){
                            board[i][j]=num;
                            if(solve(board)){
                                return true;
                            }
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
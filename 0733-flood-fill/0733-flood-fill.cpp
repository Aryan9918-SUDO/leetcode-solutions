class Solution {
public:
    void dfs(int sr, int sc, vector<vector<int>>& image, int color,int val){
        int row = image.size();
        int col = image[0].size();
        if(sr<0||sr>=row||sc<0||sc>=col){
            return;
        }
        if(image[sr][sc]!=val){
            return;
        }
        if(image[sr][sc]==color){
            return;
        }
        image[sr][sc]=color;
        dfs(sr+1,sc,image,color,val);
        dfs(sr-1,sc,image,color,val);
        dfs(sr,sc-1,image,color,val);
        dfs(sr,sc+1,image,color,val);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int row = image.size();
        int col = image[0].size();
        int val = image[sr][sc];
        dfs(sr,sc,image,color,val);
        return image;
    }
};
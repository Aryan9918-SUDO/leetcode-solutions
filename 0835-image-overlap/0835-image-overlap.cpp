class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int,int>>pos_1;
        vector<pair<int,int>>pos_2;
        int row1=img1.size();
        int col1 = img1[0].size();
        for(int i =0;i<row1;i++){
            for(int j =0; j<col1;j++){
                if(img1[i][j]==1){
                    pos_1.push_back({i,j});
                }
            }
        }
        int row2= img2.size();
        int col2= img2[0].size();
        for(int i =0;i<row2;i++){
            for(int j =0; j<col2;j++){
                if(img2[i][j]==1){
                    pos_2.push_back({i,j});
                }
            }
        }
        map<pair<int,int>,int> count;
        int len1= pos_1.size();
        int len2= pos_2.size();
        for(int i =0; i<len1;i++){
            for(int j =0; j<len2;j++){
                int r1 = pos_1[i].first;
                int c1 = pos_1[i].second;

                int r2 = pos_2[j].first;
                int c2 = pos_2[j].second;

                int dr = r2-r1;
                int dc = c2-c1;
                count[{dr,dc}]++;
            }
        }
        int ans = 0;

        for (auto x : count) {
            ans = max(ans, x.second);
        }

        return ans;
    }
};
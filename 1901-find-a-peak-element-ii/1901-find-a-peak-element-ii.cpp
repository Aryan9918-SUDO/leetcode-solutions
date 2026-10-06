class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m= mat.size();
        int n= mat[0].size();
        int low =0;
        int high = n-1;
        while(low<=high){
            int mid = (low+high)/2;
            int maxrow =0;
            for(int i =0; i<m;i++){
                if(mat[i][mid]>mat[maxrow][mid]){
                    maxrow =i;
                }
            }
            int leftvalue = mid>0 ? mat[maxrow][mid-1]:-1;
            int rightvalue = mid<n-1? mat[maxrow][mid+1]:-1;

            if(mat[maxrow][mid]>leftvalue && mat[maxrow][mid]>rightvalue){
                return {maxrow,mid};
            }
            if(leftvalue>mat[maxrow][mid]){
                high = mid-1;
            }
            if(rightvalue>mat[maxrow][mid]){
                low= mid+1;
            }
        }
        return {-1,-1};
    }
};
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        bool x_lap = false;
        if(rec1[0]<rec2[2]&&rec2[0]<rec1[2]){
            x_lap = true;
        }
        bool y_lap = false;
        if(rec1[1]<rec2[3]&&rec2[1]<rec1[3]){
            y_lap=true;
        }
        return (x_lap && y_lap);
    }
};
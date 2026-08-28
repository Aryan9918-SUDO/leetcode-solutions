class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> arr;

        // Flatten the matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                arr.push_back(grid[i][j]);
            }
        }

        sort(arr.begin(), arr.end());

        int size = arr.size();
        int repeated = -1;
        int missing = -1;

        // Find repeated and missing number
        for (int i = 1; i < size; i++) {
            // Repeated number
            if (arr[i] == arr[i - 1]) {
                repeated = arr[i];
            }

            // Missing number between arr[i-1] and arr[i]
            else if (arr[i] > arr[i - 1] + 1) {
                missing = arr[i - 1] + 1;
            }
        }

        // Missing number is 1
        if (arr[0] != 1) {
            missing = 1;
        }

        // Missing number is n²
        if (arr[size - 1] != n * n) {
            missing = n * n;
        }

        return {repeated, missing};
    }
};
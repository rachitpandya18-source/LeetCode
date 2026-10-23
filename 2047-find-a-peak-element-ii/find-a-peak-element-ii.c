/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <limits.h>

int* findPeakGrid(int** mat, int matSize, int* matColSize, int* returnSize) {
    int rows = matSize, cols = matColSize[0];
    int* ans = (int *)malloc(2 * sizeof(int));
    *returnSize = 2;
    int low = 0, high = cols - 1;

    while(low <= high) {
        int mid = (low + high) / 2;
        int maxi = INT_MIN;
        int maxiRow = -1;

        for(int i = 0; i < rows; i++) {
            if(mat[i][mid] > maxi) {
                maxi = mat[i][mid];
                maxiRow = i;
            }
        }

        int cRow = maxiRow;
        int left = (mid - 1 >= 0) ? mat[cRow][mid - 1] : -1;
        int right = (mid + 1 < cols) ? mat[cRow][mid + 1] : -1;

        if(mat[cRow][mid] > left && mat[cRow][mid] > right) {
            ans[0] = cRow, ans[1] = mid;
            return ans;
        }
        else if(mat[cRow][mid] > left) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return ans;
}
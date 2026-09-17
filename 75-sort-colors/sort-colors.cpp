class Solution {
// Dutch National Flag Algo

// three pointers --> low, mid, high

// 0 to low - 1 --> 0
// low to mid - 1 --> 1
// mid to high - 1 --> unsorted array
// high to n - 1 --> 2
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int mid = 0, high = n - 1;

        while(mid <= high) {
            if(nums[mid] == 0) {
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1) {
                mid++;
            }
            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
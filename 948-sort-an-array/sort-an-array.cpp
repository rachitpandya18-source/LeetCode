class Solution {
private:
    int getRandomIndex(int low, int high) {
    // 1. Static random engine ensures it's initialized only once
    // std::random_device provides a seed based on hardware noise
        static mt19937 generator(random_device{}());
    
    // 2. Define an inclusive uniform integer distribution [low, high]
    uniform_int_distribution<int> distribution(low, high);
    
    // 3. Generate and return the random number
    return distribution(generator);
    }
    
    int piFind(vector<int> &nums, int low, int high) {
        int randomIndex = getRandomIndex(low, high);

        swap(nums[low], nums[randomIndex]);
        int pivot = nums[low];
        int i = low, j = high;

        while(i < j) {
            while((nums[i] <= pivot) && i <= high - 1) i++;
            while((nums[j] > pivot) && j >= low + 1) j--;

            if(i < j) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
        swap(nums[low], nums[j]);

        return j;
    }
    void quickSortLogic(vector<int> &nums, int low, int high) {
        if(low < high) {
            int partitionIndexFind = piFind(nums, low, high);
            quickSortLogic(nums, low, partitionIndexFind - 1);
            quickSortLogic(nums, partitionIndexFind + 1, high);
        }   
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();

        quickSortLogic(nums, 0, n - 1);
        return nums;
    }
};
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n == 0) return true;
        
        int r = flowerbed.size(), count = 0;

        for(int i = 0; i < r; i++) {
            if(((i == 0 || flowerbed[i - 1] == 0) && (i == r - 1 || flowerbed[i + 1] == 0)) && flowerbed[i] == 0) {
                flowerbed[i] = 1;
                count++;

                if(count == n) return true;
            }
        }
        return false;
    }
};
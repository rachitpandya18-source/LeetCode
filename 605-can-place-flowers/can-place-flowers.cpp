class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n == 0) return true;

        int r = flowerbed.size();

        for(int i = 0; i < r; i++) {
            if((i == 0 || flowerbed[i - 1] == 0) && (i == r - 1 || flowerbed[i + 1] == 0) && flowerbed[i] == 0) {
                i++;
                
                if(--n == 0) return true;
            }
        }
        return false;
    }
};
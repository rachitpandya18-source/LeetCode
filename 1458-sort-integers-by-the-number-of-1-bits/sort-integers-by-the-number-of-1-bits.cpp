class Solution {
private:
    int countSetBits(int num) {
        int counter = 0;
        while(num != 0) {
            num = num & num - 1;
            counter++;
        }
        return counter;
    }
    static bool comp(pair<int, int> p1, pair<int, int> p2) {
        if(p1.second != p2.second) return p1.second < p2.second;

        return p1.first < p2.first;
    } 
public:
    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();

        vector<pair<int, int>> setBits(n);

        for(int i = 0; i < n; i++) {
            setBits[i].first = arr[i];
            setBits[i].second = countSetBits(arr[i]);
        }

        sort(setBits.begin(), setBits.end(), comp);

        int i = 0;
        for(auto x : setBits) {
            arr[i] = x.first;
            i++;
        }

        return arr;
    }
};
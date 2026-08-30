class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mp;
        queue<int> q;
        int n = s.size();

        for(int i = 0; i < n; i++) {
            char ch = s[i];

            if(mp.find(ch) == mp.end())
                q.push(i);

            mp[ch]++;

            while(q.size() > 0 && mp[s[q.front()]] > 1) q.pop();
        }

        return q.empty() ? -1 : q.front();
    }
};
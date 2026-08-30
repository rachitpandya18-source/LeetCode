class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        int n = students.size();

        for(int i = 0; i < n; i++) {
            q.push(students[i]);
        }

        int unableToEat = 0;
        int idx = 0;

        while(q.size() > 0) {
            int currentStudent = q.front();
            q.pop();

            if(currentStudent == sandwiches[idx]) {
                idx++;
                unableToEat = 0;
            }
            else {
                q.push(currentStudent);
                unableToEat++;
            }

            if(unableToEat == q.size()) break;
        }

        return q.size();
    }
};
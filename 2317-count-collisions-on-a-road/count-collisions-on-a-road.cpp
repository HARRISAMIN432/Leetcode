class Solution {
public:
    int countCollisions(string directions) {
        stack<char> s;
        int ans = 0;
        for (int i = 0; i < directions.size(); i++) {
            bool collision = false;
            while (!s.empty() && s.top() == 'R' && directions[i] == 'L') {
                ans += 2;
                collision = 1;
                s.pop();
                directions[i] = 'S';
            }
            while (!s.empty() && s.top() == 'R' && directions[i] == 'S') {
                ans += 1;
                collision = 1;
                s.pop();
                directions[i] = 'S';
            }
            while (!s.empty() && s.top() == 'S' && directions[i] == 'L') {
                ans += 1;
                collision = 1;
                s.pop();
                directions[i] = 'S';
            }
            s.push(directions[i]);
        }
        return ans;
    }
};
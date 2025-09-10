class Solution {
public:
    vector<int> closestdivisors(int n) {
        int ans;
        for(int i = 1; i <= pow(n, 0.5); i++) 
            if(n % i == 0) ans = i;
        return {ans, n / ans};
    }

    vector<int> closestDivisors(int num) {
        vector<int> n1 = closestdivisors(num + 1);
        vector<int> n2 = closestdivisors(num + 2);
        return (n1[1] - n2[0] > n2[1] - n2[0]) ? n2 : n1;
    }
};
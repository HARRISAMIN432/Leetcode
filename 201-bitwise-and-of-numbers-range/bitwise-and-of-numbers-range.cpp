class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left == 0) return 0;
        string leftBin = decToBin(left), rightBin = decToBin(right);
        if(leftBin.size() != rightBin.size()) return 0;
        int ans = 0, toAdd = pow(2, leftBin.size() - 1), i = 0;
        while(i < leftBin.size() && leftBin[i] == rightBin[i]) {
            if(leftBin[i] == '1') ans += toAdd;
            toAdd /= 2;
            i++;
        }
        return ans;
    }

private:
    string decToBin(int n) {
        string s;
        while(n > 1) {
            int num = n % 2;
            char c = num + '0';
            string tmp;
            tmp += c;
            s = tmp + s;
            n /= 2;
        }
        return "1" + s;
    }
};
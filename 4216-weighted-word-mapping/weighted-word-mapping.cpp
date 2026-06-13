class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int mp[] = {'z', 'y', 'x', 'w', 'v', 'u', 't', 's', 'r', 'q', 'p', 'o', 'n', 'm', 'l', 'k', 'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a'};
        vector<int> wgt;
        for(string word : words) wgt.push_back(calcWeight(word, weights));
        string ans;
        for(int i = 0; i < words.size(); i++) ans += mp[wgt[i]];
        return ans;
    }

    int calcWeight(string word, vector<int>& weights) {
        int ans = 0;
        for(char c : word) ans = (ans + weights[c - 'a']) % 26;
        return ans;
    }
};
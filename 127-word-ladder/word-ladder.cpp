class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> set;
        for(string s : wordList) set.insert(s);
        if(set.find(endWord) == set.end()) return 0;
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        while(!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            char temp;
            for(int i = 0; i < word.size(); i++) {
                temp = word[i];
                for(int j = 'a'; j <= 'z'; j++) {
                    word[i] = j;
                    if(set.find(word) != set.end()) {
                        if(word == endWord) return steps + 1;
                        q.push({word, steps + 1});
                        set.erase(word);
                    }
                }
                word[i] = temp;
            }
        }
        return 0;
    }
};
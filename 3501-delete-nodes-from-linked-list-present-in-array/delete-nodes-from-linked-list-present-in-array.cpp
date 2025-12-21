/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        int n = nums.size();
        unordered_set<int> s(nums.begin(), nums.end());
        vector<int> ans;
        ListNode* t = head;
        while(t) {
            if(s.find(t->val) == s.end()) ans.push_back(t->val);
            t = t->next;
        }
        if(ans.size() == 0) return NULL;
        ListNode* newHead = new ListNode(ans[0]);
        ListNode* temp = newHead;
        for(int i = 1; i < ans.size(); i++) {
            temp->next = new ListNode(ans[i]);
            temp = temp->next;
        }
        return newHead;
    }
};
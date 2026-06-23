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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head->next) return head;
        vector<int> a;
        ListNode* t = head;
        while(t) {
            a.push_back(t->val);
            t = t->next;
        }
        int n = a.size();
        for(int i = 0; i < n; i += k) {
            if(i + k <= n) 
                reverse(a.begin() + i, a.begin() + i + k);
        }
        t = head;
        for(int i = 0; i < n; i++) {
            t->val = a[i];
            t = t->next;
        }
        return head;
    }
};
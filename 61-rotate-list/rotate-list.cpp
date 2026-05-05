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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        vector<int> a;
        ListNode* tmp = head;
        while(tmp) {
            a.push_back(tmp->val);
            tmp = tmp->next;
        }
        k = k % a.size();
        while(k--) {
            a.insert(a.begin(), a.back());
            a.pop_back();
        }
        tmp = head;
        for(int i = 0; i < a.size(); i++) {
            tmp->val = a[i];
            tmp = tmp->next;
        }
        return head;
    }
};
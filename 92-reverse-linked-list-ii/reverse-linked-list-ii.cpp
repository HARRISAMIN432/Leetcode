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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int> a;
        ListNode* curr = head;
        while(curr) {
            a.push_back(curr->val);
            curr = curr->next;
        }
        reverse(a.begin() + left - 1, a.end() - a.size() + right);
        curr = head;
        int idx = 0;
        while(curr) {
            curr->val = a[idx];
            idx++;
            curr = curr->next;
        }
        return head;
    }
};
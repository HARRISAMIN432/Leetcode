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
    void reorderList(ListNode* head) {
        vector<int> ans;
        ListNode* temp = head;
        while(temp) {
            ans.push_back(temp->val);
            temp = temp->next;
        }
        int left = 0, right = ans.size() - 1;
        temp = head;
        while(left < right) {
            temp->val = ans[left];
            temp = temp->next;
            temp->val = ans[right];
            temp = temp->next;
            left++, right--;
        }
        if(ans.size() & 1) temp->val = ans[ans.size() / 2];
    }
};
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
    ListNode* oddEvenList(ListNode* head) {
        vector<int> tmp;
        ListNode* temp = head;
        while(temp) {
            tmp.push_back(temp->val);
            temp = temp->next;
        }
        temp = head;
        for(int i = 0; i < tmp.size(); i += 2) {
            temp->val = tmp[i];
            temp = temp->next;
        }
        for(int i = 1; i < tmp.size(); i += 2) {
            temp->val = tmp[i];
            temp = temp->next;
        }
        return head;
    }
};
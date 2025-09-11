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
    ListNode* mergeNodes(ListNode* head) {
        int sum = 0;
        ListNode* temp = head;
        while(temp) {
            if(temp->val == 0) {
                sum = 0;
                temp = temp->next;
                continue;
            }
            sum += temp->val;
            if(temp->next->val == 0) temp->val = sum;
            else temp->val = 0;
            temp = temp->next;
        }
        ListNode* newHead = NULL;
        ListNode* curr = NULL;
        temp = head;
        while(temp) {
            if(temp->val != 0) {
                if(!newHead) {
                    newHead = new ListNode(temp->val);
                    curr = newHead;
                }
                else {
                    curr->next = new ListNode(temp->val);
                    curr = curr->next;
                }
            }
            temp = temp->next;
        }
        return newHead;
    }
};
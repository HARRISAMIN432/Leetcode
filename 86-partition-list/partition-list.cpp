class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) return head;
        ListNode *prev = NULL, *curr = head;
        while (curr && curr->val < x) {
            prev = curr;
            curr = curr->next;
        }
        if(!curr) return head;
        ListNode *temp = curr->next, *prevTemp = curr, *newHead = NULL, *newCurr = (prev) ? prev : NULL;
        while (temp)
            if (temp->val < x) {
                prevTemp->next = temp->next;
                if (!newHead && !prev) {
                    newHead = temp;
                    newHead->next = curr;
                    newCurr = newHead;
                } else {
                    temp->next = newCurr->next;
                    newCurr->next = temp;
                    newCurr = temp;
                }
                temp = prevTemp->next;
            } else {
                prevTemp = temp;
                temp = temp->next;
            }
        return (prev) ? head : (newHead) ? newHead : curr;
    }
};
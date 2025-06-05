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
    ListNode* Merge(ListNode* head1, ListNode* head2) {
        if(!head1) return head2;
        if(!head2) return head1;
        ListNode* ansHead;
        ListNode* temp;
        if(head1->val < head2->val) {
            ansHead = head1;
            temp = head1;
            head1 = head1->next;
        }
        else {
            ansHead = head2;
            temp = head2;
            head2 = head2->next;
        }
        while(head1 && head2) {
            if(head2->val > head1->val) {
                temp->next = head1;
                temp = head1;
                head1 = head1->next;
            }
            else {
                temp->next = head2;
                temp = head2;
                head2 = head2->next;
            }
        }
        while(head1) {
            temp->next = head1;
            temp = head1;
            head1 = head1->next;
        }
        while(head2) {
            temp->next = head2;
            temp = head2;
            head2 = head2->next;
        }
        return ansHead;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        else if(lists.size() == 1) return lists[0];
        for(int i = 1; i < lists.size(); i++) lists[0] = Merge(lists[0], lists[i]);
        return lists[0];
    }
};
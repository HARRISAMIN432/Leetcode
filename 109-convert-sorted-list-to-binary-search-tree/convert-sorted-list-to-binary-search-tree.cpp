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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* bst(int l, int r, vector<int> &nums) {
        if (l > r) return nullptr;
        int mid = (l + r) >> 1;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = bst(l, mid - 1, nums);
        node->right = bst(mid + 1, r, nums);
        return node;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        vector<int> nums;
        while(head) {
            nums.push_back(head->val);
            head = head->next;
        }
        return bst(0, nums.size() - 1, nums);
    }
};
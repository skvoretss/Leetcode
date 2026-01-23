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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* pointer = new ListNode;
        ListNode* res = pointer;
        int remainder = 0;

        while (l1 != nullptr && l2 != nullptr) {
            pointer->val = (l1->val + l2->val + remainder) % 10;
            remainder = (l1->val + l2->val + remainder) / 10;
            l1 = l1->next;
            l2 = l2->next;
            if (l1 != nullptr || l2 != nullptr) {
                pointer->next = new ListNode;
                pointer = pointer->next;
            }
            
        }
        while (l1 != nullptr) {
            pointer->val = (l1->val + remainder) % 10;
            remainder = (l1->val + remainder) / 10;
            l1 = l1->next;
            if (l1 != nullptr) {
                pointer->next = new ListNode;
                pointer = pointer->next;
            }
        }

        while (l2 != nullptr) {
            pointer->val = (l2->val + remainder) % 10;
            remainder = (l2->val + remainder) / 10;
            l2 = l2->next;
            if (l2 != nullptr) {
                pointer->next = new ListNode;
                pointer = pointer->next;
            }
        }
        if (remainder) {
            pointer->next = new ListNode;
            pointer = pointer->next;
            pointer->val = remainder;
        }
        return res;
    }
};
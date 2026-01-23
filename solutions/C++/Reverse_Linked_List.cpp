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
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;
        ListNode *tmp3, *tmp1 = head, *tmp2 = head->next;
        tmp1->next = nullptr;
        while (tmp2 != nullptr) {
            tmp3 = tmp2->next;
            tmp2->next = tmp1;
            tmp1 = tmp2;
            tmp2 = tmp3;
        }
        return tmp1;

    }
};
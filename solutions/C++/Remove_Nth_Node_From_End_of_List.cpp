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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *l1 = head, *l2 = head;
        int k = 0;
        while (k < n && l2->next != nullptr) {
            l2 = l2->next;
            ++k;
        }
        if (k < n) return head->next;
        while (l2->next != nullptr) {
            k = 0;
            while (k < n && l2->next != nullptr) {
                l2 = l2->next;
                l1 = l1->next;
            }
        }
        l2 = l1->next;
        if (l2) l1->next = l2->next;
        else return nullptr;
        return head;
    }
};
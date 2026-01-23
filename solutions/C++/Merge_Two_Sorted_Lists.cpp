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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = list2;
        bool is_on_list1 = false;
        if (!(list1 || list2)) return nullptr;
        if (list1 && !list2) return list1;
        if (!list1 && list2) return list2;
        if (list1->val < list2->val) {
            head = list1;
            is_on_list1 = true;
        }
        ListNode *cur_1 = list1, *cur_2 = list2, *cur = head;
        while (cur_1 && cur_2) {
            if (is_on_list1) {
                if (cur_1->next && cur_2->val < cur_1->next->val) {
                    ListNode* t = cur_1->next;
                    cur_1->next = cur_2;
                    cur = cur_2;
                    is_on_list1 = false;
                    cur_1 = t;
                }
                else if (cur_1->next) {
                    cur = cur_1->next;
                    cur_1 = cur_1->next;
                }
                else cur_1 = cur_1->next;
            }
            else {
                if (cur_2->next && cur_1->val < cur_2->next->val) {
                    ListNode* t = cur_2->next;
                    cur_2->next = cur_1;
                    cur = cur_1;
                    is_on_list1 = true;
                    cur_2 = t;
                }
                else if (cur_2->next) {
                    cur = cur_2->next;
                    cur_2 = cur_2->next;
                }
                else cur_2 = cur_2->next;
            }
        }
        if (cur_1) {
            cur->next = cur_1;
        }
        if (cur_2) {
            cur->next = cur_2;
        }
        return head;
    }
};
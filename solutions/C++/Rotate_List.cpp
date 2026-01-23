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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *cur = head, *end = head;
        int size = 0;
        while (cur) {
            end = cur;
            cur = cur->next;
            ++size;
        }
        k %= size;
        if (k == 0) return head;
        int cnt1 = size - k;
        cur = head;
        ListNode* save_prev = head;
        while (cnt1) {
            save_prev = cur;
            cur = cur->next;
            --cnt1;
        }
        save_prev->next = nullptr;
        end->next = head;
        return cur;
    }
};
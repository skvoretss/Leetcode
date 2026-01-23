/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *rabbit = head, *turtle = head;
        while (rabbit != nullptr) {
            turtle = turtle->next;
            rabbit = rabbit->next;
            if (rabbit) rabbit = rabbit->next;
            else continue;
            if (turtle == rabbit) return true;
        }
        return false;
    }
};
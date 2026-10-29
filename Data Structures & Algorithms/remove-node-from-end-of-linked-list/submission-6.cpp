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
        if (head == nullptr) {
            return nullptr;
        }

        ListNode dummy(0, head);

        ListNode* curr = head;
        ListNode* prev = &dummy;
        ListNode* fast = head;

        for (int i = 1; i <= n; i++) {
            fast = fast->next;
        }
        while (fast) {
            prev = prev->next;
            curr = curr->next;
            fast = fast->next;
        }
        
        prev->next = curr->next;
        return dummy.next;
        
    }
};

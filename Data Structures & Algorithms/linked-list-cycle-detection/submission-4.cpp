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
    bool hasCycle(ListNode* head) {
        if (head == nullptr) {
            return false;
        }
        if (head->next == nullptr) {
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr || slow != nullptr) {
            if (fast->next == nullptr) {
                break;
            }
            fast = fast->next->next;
            slow = slow->next;
            if (!fast || !slow) {
                break;
            }
            if (fast->val == slow->val) {
                return true;
            }
        }

        return false;

        
    }
};

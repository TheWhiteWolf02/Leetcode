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
        ListNode *newHead = NULL;
        ListNode *ptr = NULL;
        int val1, val2, carryOver = 0, sum;
        while(l1 != NULL || l2 != NULL || carryOver > 0)
        {
            val1 = 0;
            val2 = 0;
            if (l1 != NULL)
            {
                val1 = l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL)
            {
                val2 = l2->val;
                l2 = l2->next;
            }
            sum = val1 + val2 + carryOver;

            carryOver = sum / 10;

            if (newHead == NULL)
            {
                newHead = new ListNode(sum%10);
                ptr = newHead;
            }
            else
            {
                newHead->next = new ListNode(sum%10);
                newHead = newHead->next;
            }
        }
        return ptr;
    }
};

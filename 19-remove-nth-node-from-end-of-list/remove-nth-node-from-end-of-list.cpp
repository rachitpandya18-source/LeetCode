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
        ListNode* fastPt = head;
        for(int i = 0; i < n; i++) {
            fastPt = fastPt->next;
        }
        
        if(fastPt == nullptr) {
            ListNode* newNode = head->next;
            delete head;
            return newNode;
        }

        ListNode* slow = head;
        while(fastPt->next) {
            slow = slow->next;
            fastPt = fastPt->next;
        }
        ListNode* deleteNode = slow->next;
        slow->next = slow->next->next;
        delete deleteNode;
        return head;
    }
};
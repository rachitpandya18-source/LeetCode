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
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = nullptr;
        ListNode* front = nullptr;

        while(temp) {
            front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return true;
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* secondHalf = reverseList(slow->next);
        ListNode* firstHalf = head;

        while(secondHalf != nullptr) {
            if(firstHalf->val != secondHalf->val) {
                reverseList(secondHalf);
                return false;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        reverseList(secondHalf);
        return true;
    }
};
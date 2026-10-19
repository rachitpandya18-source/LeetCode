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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* temp = head;
        ListNode* prevNode = nullptr;
        ListNode* nextNode;

        while(temp) {
            nextNode = temp->next;
            temp->next = prevNode;
            prevNode = temp;
            temp = nextNode;
        }

        return head;
    }
    ListNode* getKthNode(ListNode* head, int k) {
        k--;
        ListNode* temp = head;
        while(temp) {
            k--;
            temp = temp->next;
            if(k == 0) break;
        }
        return temp;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* temp = head;
        ListNode* prevLast = nullptr;

        while(temp) {
            ListNode* kthNode = getKthNode(temp, k);

            if(kthNode == nullptr) {
                if(prevLast) prevLast->next = temp;
                break;
            }

            ListNode* nextNode = kthNode->next;
            kthNode->next = nullptr;
            reverseList(temp);

            if(head == temp) head = kthNode;
            else prevLast->next = kthNode;

            prevLast = temp;
            temp = nextNode;
        }

        return head;
    }
};
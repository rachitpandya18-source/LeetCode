/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if(head == NULL || head->next == NULL) return head;

    struct ListNode* curr = head;
    struct ListNode* prev = NULL;
    struct ListNode* nextNode = head;

    while(curr) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}

struct ListNode* getKthNode(struct ListNode* head, int k) {
    k--;
    struct ListNode* temp = head;
    while(temp && k > 0) {
        k--;
        temp = temp->next;
    }
    return temp;
}
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode* temp = head;
    struct ListNode* prevLast = NULL;

    while(temp) {
        struct ListNode* kthNode = getKthNode(temp, k);

        if(kthNode == NULL) {
            if(prevLast) prevLast->next = temp;
            break;
        }

        struct ListNode* nextNode = kthNode->next;
        kthNode->next = NULL;
        reverseList(temp);

        if(head == temp) head = kthNode;
        else prevLast->next = kthNode;

        prevLast = temp;
        temp = nextNode;
    }

    return head;   
}
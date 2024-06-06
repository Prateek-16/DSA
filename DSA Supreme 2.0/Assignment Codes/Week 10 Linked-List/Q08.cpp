//https://leetcode.com/problems/rotate-list/


//Rotate List


/*
Simple Problem This is Use the Property of linked list to Adjsut the pointers but first
Reach at the correct position Node using Modulos and length of the linked list
*/


class Solution {
public:
    int getLength(ListNode* head) {
        int len = 0;
        while (head != NULL) {
            len++;
            head = head->next;
        }
        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        int n = getLength(head);

        int length = k % n;
        if (length == 0) {
            return head;
        }
        int pos = n - length - 1;
        ListNode* temp1 = head;
        for (int i = 0; i < pos; i++) {
            temp1 = temp1->next;
        }
        ListNode* head2 = temp1->next;
        ListNode* temp2 = temp1;
        while (temp2->next != NULL) {
            temp2 = temp2->next;
        }

        temp1->next = NULL;
        temp2->next = head;
        head = head2;
        return head;
    }
};
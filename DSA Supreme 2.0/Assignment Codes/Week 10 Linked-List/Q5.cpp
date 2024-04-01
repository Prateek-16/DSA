//https://leetcode.com/problems/sort-list/


//Sort List using merge Sort


/*
You know how to merge to sorted list Using 2 pointers
So just call find Mid and call mergesort on left and right 
then merge 

*/


class Solution {
public:
    ListNode* midelement(ListNode* temp) {
        ListNode* slow = temp;
        ListNode* fast = temp;
        while (fast->next != NULL) {
            fast = fast->next;
            if (fast->next != NULL) {
                fast = fast->next;
                slow = slow->next;
            }
        }
        return slow;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if (list1 == NULL && list2 == NULL) {
            return list1;
        }
        if (list1 == NULL) {
            return list2;
        }
        if (list2 == NULL) {
            return list1;
        }

        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* head3 = NULL;
        ListNode* prev = NULL;

        if (temp1->val > temp2->val) {
            prev = temp2;
            head3 = prev;
            temp2 = temp2->next;
        } else {
            prev = temp1;
            head3 = prev;
            temp1 = temp1->next;
        }
        while (temp1 != NULL && temp2 != NULL) {

            if (temp1->val > temp2->val) {

                prev->next = temp2;
                prev = prev->next;

                temp2 = temp2->next;
            } else {
                prev->next = temp1;
                prev = prev->next;

                temp1 = temp1->next;
            }
        }
        if (temp1 == NULL && temp2 == NULL) {
            return head3;
        }
        if (temp1 == NULL) {
            while (temp2 != NULL) {
                prev->next = temp2;
                prev = prev->next;
                temp2 = temp2->next;
            }
        }
        if (temp2 == NULL) {
            while (temp1 != NULL) {
                prev->next = temp1;
                prev = prev->next;
                temp1 = temp1->next;
            }
        }
        return head3;
    }

    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* mid = midelement(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL;

        left = sortList(left);
        right = sortList(right);

        ListNode* merge = mergeTwoLists(left, right);
        return merge;
    }
};
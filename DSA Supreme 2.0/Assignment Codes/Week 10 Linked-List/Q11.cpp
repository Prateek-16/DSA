//https://leetcode.com/problems/odd-even-linked-list/

//Odd Even linked list

/*
Toh odd and even index w=node sko seperarte karna hai
simple hai code dekh kar samj lo
*/
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* h1 = head;
        ListNode* h2 = head->next;
        ListNode* even_head = h2;

        while (h2 && h2->next) {
            h1->next = h2->next;
            h2->next = h2->next->next;
            h1 = h1->next;
            h2 = h2->next;
        }
        h1->next = even_head;
        return head;
    }
};
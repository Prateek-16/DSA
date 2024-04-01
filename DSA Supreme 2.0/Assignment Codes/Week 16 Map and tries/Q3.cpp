// https://www.geeksforgeeks.org/problems/intersection-of-two-linked-list/1


// intersection of two linked lists


/*
Pehele Bhi kara hai single map mai entries dalo LL2 ki
then LL1 par itrate karo and agar koi value match akrete toh use new Linked list IntersectionList ka part bana lo
*/


class Solution
{
public:
    Node *findIntersection(Node *head1, Node *head2)
    {
        unordered_map<int, int> mp;
        Node *temp = head2;
        while (temp)
        {
            mp[temp->data]++;
            temp = temp->next;
        }
        Node *IL = NULL;
        temp = head1;
        Node *curr = NULL;
        while (temp)
        {
            if (mp.find(temp->data) == mp.end())
            {
                temp = temp->next;
            }
            else
            {
                if (!IL)
                {
                    IL = temp;
                    temp = temp->next;
                    curr = IL;
                }
                else
                {
                    curr->next = temp;
                    curr = curr->next;
                    temp = temp->next;
                }
            }
        }
        curr->next = NULL;
        return IL;
    }
};
// https://leetcode.com/problems/copy-list-with-random-pointer/description/

// Copy List with Random Pointer

/*
Interesting Question - So approach will be to Make new Nodes and attach them Jsut next to the Original Node
Then we know at even indexes we have original Nodes and at odd indexes we have new Nodes

so Now originalNode -> next (newNode) -> random = originalNode->random( original Node)->next(copy of the random of original node )*/
/*

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *deepcopy(Node *head)
    {
        if (!head)
        {
            return head;
        }
        Node *temp = head;

        while (temp)
        {
            Node *newnode = new Node(temp->val);
            newnode->next = temp->next;
            temp->next = newnode;
            temp = temp->next->next;
        }
        temp = head;
        while (temp)
        {
            // Node*clonedNode=temp->next;
            temp->next->random = temp->random ? temp->random->next : NULL;
            temp = temp->next->next;
        }

        temp = head;
        Node *clonedHead = temp->next;
        while (temp)
        {
            Node *clonedNode = temp->next;
            temp->next = temp->next->next;
            if (clonedNode->next)
            {
                clonedNode->next = clonedNode->next->next;
            }
            temp = temp->next;
        }
        return clonedHead;
    }
    Node *copyRandomList(Node *head)
    {
        return deepcopy(head);
    }
};
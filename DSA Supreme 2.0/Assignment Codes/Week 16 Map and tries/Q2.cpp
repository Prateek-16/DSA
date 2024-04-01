//https://www.geeksforgeeks.org/problems/union-of-two-linked-list/1


//Union of two linked lists


/*
Simply sorted format mai union return karna hai aur distict elements nahi a sakte
Toh ek map bana lia and map mai dalte gae elements dono Linked list ke
map automatically sorted format mai sort kar lega

fir ek new mode banalenge unionLink nam ki and temp pointer for iteration
if unionlink null ho toh head attach karenge and temp se ireate karte hue baki linkes lagate rahenge
*/
class Solution
{
    public:
    struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {
        // code here
        map<int,Node*>mp;
        Node* temp1 = head1;
        while(temp1){
            mp[temp1->data] = temp1;
            temp1=temp1->next;
        }
        temp1 = head2;
        while(temp1){
            mp[temp1->data] = temp1;
            temp1 = temp1->next;
        }
        Node*UL = NULL;
        temp1 = nullptr;
        for( auto i = mp.begin() ; i!=mp.end() ; i++ ){
            if(!UL){
                UL = i->second;
                temp1= UL;
            }
            else{
                temp1->next = i->second;
                temp1=temp1->next;
            }
        }
        temp1->next = NULL;
        return UL;
    }
};
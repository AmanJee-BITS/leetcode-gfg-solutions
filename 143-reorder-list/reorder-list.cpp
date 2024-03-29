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
    void reorderList(ListNode* head) {
        vector<int> v;
        
        ListNode* temp = head;
        
        while(temp!=NULL){
            v.push_back(temp->val);
            temp=temp->next;
        }
        
        temp=head;
        int i=0, j=v.size()-1;
        
        while(i <= j or i<v.size()/2){
            temp->val = v[i++];
            temp = temp->next;
            
            if(temp!=NULL){
                temp->val = v[j--];
                if(temp->next!=NULL)
                    temp = temp->next;
            }
        }
        
        head = temp;
    }
};
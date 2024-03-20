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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* prev=NULL;
        ListNode* temp=list1;
        
        int i=0;
        while(i<a){
            prev=temp;
            temp=temp->next;
            i++;
        }
        
        prev->next=list2;
        
        while(prev->next!=NULL){
            prev=prev->next;
        }
        
        while(i<b){
            temp=temp->next;
            i++;
        }
        
        prev->next=temp->next;
        
        return list1;
    }
};
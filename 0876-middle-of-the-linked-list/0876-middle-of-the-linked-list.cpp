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
    ListNode* middleNode(ListNode* head) {
        ListNode *p = head;
        int cnt = 1;
        vector<int> v;
        
        while(p->next != NULL){
            v.push_back(p->val);
            p = p->next;
            cnt++;
        }
        
        v.push_back(p->val);
        p = head; 
        int k = 0;
        
        while(k != cnt/2){
            p = p->next;
            k++;
        }
        return p;
    }
};
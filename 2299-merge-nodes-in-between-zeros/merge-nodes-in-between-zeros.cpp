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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = NULL, *ans = NULL;
        int sum = 0;
        
        while(head!=NULL){
            if(head->val == 0 and sum!=0){
                if(temp == NULL){
                    temp = new ListNode(sum);
                    ans = temp;
                }
                else{
                    temp->next = new ListNode(sum);
                    temp = temp->next;
                }
                sum = 0;
            }
            else{
                sum += head->val;
            }
            head = head->next;
        }
        
        return ans;
    }
};
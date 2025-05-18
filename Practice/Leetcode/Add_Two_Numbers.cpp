// Leetcode - 2

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL;
        ListNode *tail = NULL;
        int carry = 0;
        
        while(l1 != NULL || l2 != NULL){
            int sum = carry;
            if(l1 != NULL){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                sum += l2->val;
                l2 = l2->next;
            }
            int digit = sum % 10;
            carry = sum / 10;
            
            ListNode *ptr = new ListNode(digit);
            if(head == NULL){
                head = ptr;
                tail = ptr;
            } 
            else{
                tail->next = ptr;
                tail = ptr;
            }
        }
        
        if(carry > 0){
            ListNode *ptr = new ListNode(carry);
            tail->next = ptr;
            tail = ptr;
        }
        
        return head;
    }
};

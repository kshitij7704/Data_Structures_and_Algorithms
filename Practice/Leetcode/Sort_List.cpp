// Leetcode - 148

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
private:
    ListNode* findMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* newH = nullptr;
        ListNode* tail = newH;
        while(l1 && l2){
            if(l1->val < l2->val){
                if(!newH){
                    newH = l1;
                    tail = newH;
                }
                else{
                    tail->next = l1;
                    tail = l1;
                }
                l1 = l1->next;
            }
            else{
                if(!newH){
                    newH = l2;
                    tail = newH;
                }
                else{
                    tail->next = l2;
                    tail = l2;
                }
                l2 = l2->next;
            }
        }
        while(l1){
            if(!newH){
                newH = l1;
                tail = newH;
            }
            else{
                tail->next = l1;
                tail = l1;
            }
            l1 = l1->next;
        }
        while(l2){
            if(!newH){
                newH = l2;
                tail = newH;
            }
            else{
                tail->next = l2;
                tail = l2;
            }
            l2 = l2->next;
        }
        return newH;
    }

public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode* mid = findMid(head);
        ListNode* right = mid->next;
        mid->next = nullptr;
        ListNode* left = head;
        left = sortList(left);
        right = sortList(right);
        return merge(left, right); 
    }
};

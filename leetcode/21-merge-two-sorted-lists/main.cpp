/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-999);
        ListNode* cur = head;
        
        while (l1 && l2) {
            int v1 = l1->val;
            int v2 = l2->val;
            
            if (v1 < v2) {
                cur->next = l1;
                cur = cur->next;
                l1 = l1->next;      
            }
            else {
                cur->next = l2;
                cur = cur->next;
                l2 = l2->next; 
            }
        }
        
        if (l1)
            cur->next = l1;
        else if (l2)
            cur->next = l2;
        
        return head->next;
    }
};

int main() {
    return 0;
}
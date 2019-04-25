class Solution {
public:
    bool hasCycle(ListNode *head) {
        //use double pointer;
        if (head == NULL) return false;
        auto slow = head;
        auto fast = head->next;
        while(fast!=slow){
            if(fast == NULL || fast->next==NULL){
                return false;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
        return true;
    }
};
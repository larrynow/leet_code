#include<iostream>
#include<set>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        queue<ListNode*> q;
        auto pre = new ListNode(0);
        pre->next = head;
        auto curr = head;
        while(curr){
            q.push(curr);
            curr = curr->next;
            if(q.size()>n){
                pre = q.front();
                q.pop();
            }
        }
        if(pre->next==head) return head->next;
        pre->next = q.front()->next;

        return head;
    }
};
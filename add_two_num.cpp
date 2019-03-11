#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>

using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int carry = 0;
		ListNode pre(0);
		ListNode* l = &pre;
		//if l1 or l2 is NULL, we could add 0; besides must consider carry is not 0 after loop (loop until carry is 0);
		while (l1 || l2 || carry) {
			int val = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
			if (val >= 10) {
				val = val - 10;
				carry = 1;
			}
			else {
				carry = 0;
			}
			l->next = new ListNode(val);
			l = l->next;
			l1 = l1 ? l1->next : l1;//if not NULL next, or keep NULL;
			l2 = l2 ? l2->next : l2;
		}

		return pre.next;
	}
};
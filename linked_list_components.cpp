#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_set>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
	int numComponents(ListNode* head, vector<int>& G) {
		unordered_set<int> set_G(G.begin(), G.end());//use unordered_set.count() to judge if G contains a value;
		int count = 0;
		while (head) {
			if ((set_G.count(head->val)) && (head->next==NULL||!set_G.count(head->next->val))) {//if one value in G but G don't contains it's child, means a break;
				count++;
			}
			head = head->next;
		}

		return count;
	}
};
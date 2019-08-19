/*
 * @lc app=leetcode id=147 lang=cpp
 *
 * [147] Insertion Sort List
 *
 * https://leetcode.com/problems/insertion-sort-list/description/
 *
 * algorithms
 * Medium (38.05%)
 * Likes:    397
 * Dislikes: 446
 * Total Accepted:    156.7K
 * Total Submissions: 411.5K
 * Testcase Example:  '[4,2,1,3]'
 *
 * Sort a linked list using insertion sort.
 * 
 * 
 * 
 * 
 * 
 * A graphical example of insertion sort. The partial sorted list (black)
 * initially contains only the first element in the list.
 * With each iteration one element (red) is removed from the input data and
 * inserted in-place into the sorted list
 * 
 * 
 * 
 * 
 * 
 * Algorithm of Insertion Sort:
 * 
 * 
 * Insertion sort iterates, consuming one input element each repetition, and
 * growing a sorted output list.
 * At each iteration, insertion sort removes one element from the input data,
 * finds the location it belongs within the sorted list, and inserts it
 * there.
 * It repeats until no input elements remain.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 4->2->1->3
 * Output: 1->2->3->4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -1->5->3->4->0
 * Output: -1->0->3->4->5
 * 
 * 
 */
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* current = head;

        while(current)
        {
            if((current->next) && (current->next->val < current->val))
            {
                while((pre->next) && (current->next->val > pre->next->val))
                {
                    pre = pre->next;
                }
                auto pre_next_temp = pre->next;
                pre->next = current->next;// current->next is the node to insert.
                current->next = current->next->next;// connect with rest.
                pre->next->next = pre_next_temp;// connect insert node in prev.
                pre = dummy;
            }
            else
            {
                current = current->next;
            }
        }
        return dummy->next;

    }
};


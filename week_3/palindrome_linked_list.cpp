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
    ListNode* curr;
    bool recurr(ListNode* head)
    {
        // base case
        if (head == nullptr)
        {
            return true;
        }

        bool answer = recurr(head->next);

        if(head->val != curr->val)
        {
            return false;
        }
        curr = curr->next;
        return answer;
    }
public:
     
    bool isPalindrome(ListNode* head) {
        curr = head;
        return recurr(head);
    }
};
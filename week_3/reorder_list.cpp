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

    void recurr(ListNode* head)
    {
        if (head == nullptr)
        {
            return;
        }
        recurr(head->next);
        ListNode* temp = curr->next;

        if (curr->next == nullptr)
        {
            return;
        }
        else if (head == curr)
        {
            head->next = nullptr;
            return;
        }
        curr->next = head;
        head->next = (temp == head) ? nullptr : temp;

        curr = temp; 
    }

public:
    void reorderList(ListNode* head) {
        curr = head;
        recurr(head);
    }
};
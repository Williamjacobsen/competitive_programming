#include <iostream>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head->next == nullptr) {
            return nullptr;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* fp = dummy;
        ListNode* sp = dummy;

        while (fp != nullptr && fp->next != nullptr) {
            if (n != 0) {
                --n;
                fp = fp->next;
            }
            else {
                sp = sp->next;
                fp = fp->next;    
            }
        }

        sp->next = sp->next->next;
        sp = sp->next;

        ListNode* newHead = dummy->next;
        delete dummy;
        
        return newHead;
    }
};

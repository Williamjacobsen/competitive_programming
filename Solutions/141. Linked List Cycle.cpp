#include <cstddef>
#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        
        return false;
    }
};

int main()
{
    ListNode* node1 = new ListNode(3);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(0);
    ListNode* node4 = new ListNode(-4);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    node4->next = node2;

    Solution s;

    bool result = s.hasCycle(node1);
    std::cout << result << "\n";

    return 0;
}

//
// Created by villi on 11/4/2024.
//

#include <stdio.h>
#include <stdlib.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode
{
    int val;
    struct ListNode *next;
};

int pairSum(struct ListNode* head)
{
    struct ListNode *fast = head;

    struct ListNode *prev = NULL;
    struct ListNode *slow = head;
    struct ListNode *temp;
    struct ListNode *reverse = head;

    while (fast && fast->next)
    {
        fast = fast->next->next;

        temp = slow->next;
        slow->next = prev;
        prev = slow;
        reverse = slow;
        slow = temp;
    }

    int sum = 0;
    while (slow)
    {
        if (sum < slow->val + reverse->val)
        {
            sum = slow->val + reverse->val;
        }
        slow = slow->next;
        reverse = reverse->next;
    }

    return sum;
}

int main(void)
{
    struct ListNode* a = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* b = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* c = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* d = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* e = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* f = (struct ListNode*)malloc(sizeof(struct ListNode));

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    f->next = NULL;

    a->val = 5;
    b->val = 4;
    c->val = 3;
    d->val = 2;
    e->val = 3;
    f->val = 1;

    pairSum(a);

    return 0;
}

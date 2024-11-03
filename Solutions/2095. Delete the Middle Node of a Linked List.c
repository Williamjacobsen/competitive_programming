//
// Created by villi on 11/3/2024.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* deleteMiddle(struct ListNode* head) {
    if (!head || !head->next)
        return NULL;

    int i = 0;

    struct ListNode* start = head;
    struct ListNode* temp = head;
    struct ListNode* prev = head;

    while (head != NULL)
    {
        if (i%2)
        {
            prev = temp;
            temp = temp->next;
        }
        i++;
        head = head->next;
    }

    prev->next = prev->next->next;

    return start;
}

int main(void)
{
    struct ListNode* a = (struct ListNode*)malloc(sizeof(struct ListNode)); a->val = 1; a->next = NULL;
    /*struct ListNode* b = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* c = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* d = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* e = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* f = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* g = (struct ListNode*)malloc(sizeof(struct ListNode));

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    f->next = g;
    g->next = NULL;

    a->val = 1;
    b->val = 3;
    c->val = 4;
    d->val = 7;
    e->val = 1;
    f->val = 2;
    g->val = 6;*/

    deleteMiddle(a);

    return 0;
}
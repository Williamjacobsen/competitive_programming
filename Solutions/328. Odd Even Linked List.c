//
// Created by villi on 11/1/2024.
//


#include <stddef.h>
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

struct ListNode* oddEvenList(struct ListNode* head)
{
    if (head == NULL)
    {
        return NULL;
    }

    struct ListNode* oddHead = head;
    struct ListNode* evenHead = oddHead->next;
    struct ListNode* evenBeginning = evenHead;

    while (evenHead != NULL && evenHead->next != NULL)
    {
        oddHead->next = oddHead->next->next;
        evenHead->next = evenHead->next->next;
        oddHead = oddHead->next;
        evenHead = evenHead->next;
    }
    oddHead->next = evenBeginning;

    /*while (head != NULL)
    {
        printf("%d\n", head->val);
        head = head->next;
    }*/

    return head;
}

int main(void)
{
    struct ListNode* a = malloc(sizeof(struct ListNode));
    struct ListNode* b = malloc(sizeof(struct ListNode));
    struct ListNode* c = malloc(sizeof(struct ListNode));
    struct ListNode* d = malloc(sizeof(struct ListNode));
    struct ListNode* e = malloc(sizeof(struct ListNode));
    struct ListNode* f = malloc(sizeof(struct ListNode));
    struct ListNode* g = malloc(sizeof(struct ListNode));

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    f->next = g;
    g->next = NULL;
    a->val = 2;
    b->val = 1;
    c->val = 3;
    d->val = 5;
    e->val = 6;
    f->val = 4;
    g->val = 7;

    struct ListNode* head = oddEvenList(a);

    while (a != NULL)
    {
        struct ListNode* temp = a;
        a = a->next;
        free(temp);
    }

    return 0;
}
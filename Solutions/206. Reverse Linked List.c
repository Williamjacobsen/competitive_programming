//
// Created by villi on 11/1/2024.
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

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;

    struct ListNode* temp;
    while (curr != NULL)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    return prev;
}

int main(void)
{
    struct ListNode* head = malloc(sizeof(struct ListNode));
    head->val = 1;

    struct ListNode* second = malloc(sizeof(struct ListNode));
    head->next = second;
    second->val = 2;

    struct ListNode* third = malloc(sizeof(struct ListNode));
    second->next = third;
    third->next = NULL;
    third->val = 3;

    struct ListNode* result = reverseList(head);

    while (result != NULL)
    {
        printf("%d\n", result->val);
        result = result->next;
    }

    free(head);
    free(second);
    free(third);

    return 0;
}
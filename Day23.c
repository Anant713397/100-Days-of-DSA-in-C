// Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers (first list)
// - Third line: integer m
// - Fourth line: m space-separated integers (second list)

// Output:
// - Print the merged linked list elements, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 4
// 15 25 35 45

// Output:
// 10 15 20 25 30 35 40 45 50

// Explanation:
// Compare nodes of both lists, append smaller to result, continue until all nodes are merged.

#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node* next;
};


struct Node* createNode(int value) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}


struct Node* insertEnd(struct Node* head, int value) 
{
    struct Node* newNode = createNode(value);

    if (head == NULL) {
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}


struct Node* mergeLists(struct Node* head1, struct Node* head2) 
{
    struct Node* mergedHead = NULL;
    struct Node* temp = NULL;

    while (head1 != NULL && head2 != NULL) {
        int value;

        if (head1->data <= head2->data) {
            value = head1->data;
            head1 = head1->next;
        } else {
            value = head2->data;
            head2 = head2->next;
        }

        if (mergedHead == NULL) {
            mergedHead = createNode(value);
            temp = mergedHead;
        } else {
            temp->next = createNode(value);
            temp = temp->next;
        }
    }

   
    while (head1 != NULL) 
    {
        temp->next = createNode(head1->data);
        temp = temp->next;
        head1 = head1->next;
    }

    while (head2 != NULL) {
        temp->next = createNode(head2->data);
        temp = temp->next;
        head2 = head2->next;
    }

    return mergedHead;
}


void printList(struct Node* head) 
{
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, m, value;
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head1 = insertEnd(head1, value);
    }

 
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &value);
        head2 = insertEnd(head2, value);
    }

   
    struct Node* mergedHead = mergeLists(head1, head2);
    printList(mergedHead);

    return 0;
}
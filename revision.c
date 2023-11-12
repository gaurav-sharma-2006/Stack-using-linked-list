#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void traversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}
struct node *insert_at_beggen(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}
struct node *delete_at_first(struct node *head)
{
    struct node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}
int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *first = (struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node));
    struct node *third = (struct node *)malloc(sizeof(struct node));

    // link head and first
    head->data = 45;
    head->next = first;

    // link first and second
    first->data = 78;
    first->next = second;

    // link second and third
    second->data = 86;
    second->next = third;

    // link third and fourth
    third->data = 89;
    third->next = NULL;

    printf("Before deletionin a linked list\n");
    head = insert_at_beggen(head, 100);
    traversal(head);

    printf("\n\n");

    printf("Before deletion in linked list\n");
    head = delete_at_first(head);
    traversal(head);
}
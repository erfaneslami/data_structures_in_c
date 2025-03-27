#include <stdio.h>


struct linkedlist_node
{
    int value;
    struct linkedlist_node* next;
};

typedef struct linkedlist_node linkedlist_node_t;


void print_linkedlist(linkedlist_node_t *head) {
    linkedlist_node_t *current_node = head;

    while (current_node != NULL)
    {
        printf("%d - ", current_node->value);
        current_node = current_node->next;
    }
    printf("\n");
     
}

int main(void)
{

    linkedlist_node_t n1, n2, n3 ;
    linkedlist_node_t *head;

    n1.value = 20;
    n2.value = 30;
    n3.value = 40;


    head = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = NULL;


    print_linkedlist(head);


    return 0;  
}



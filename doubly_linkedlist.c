#include <stdio.h>
#include <stdlib.h>


struct node
{
    int value;
    struct node* next;
    struct node* prev;
};

typedef struct node node_t;



node_t *create_new_node(int value) {
    node_t *result = malloc(sizeof(node_t));
    result->value = value;
    result->next = NULL;
    result->prev = NULL;
    return result;  
}


node_t *add_new_node(node_t *pre_node,int value) {
    node_t *new_node = create_new_node(value);
    new_node->prev = pre_node;
    if (pre_node->next != NULL) {
        new_node->next = pre_node->next;
    }
    pre_node->next = new_node;
    return new_node;
}


node_t *find_node_by_value(int value,node_t *head) {
    node_t *temp = head;
    while (temp->next != NULL)
    {
        if (temp->value == value) return temp;
        temp = temp->next;
    }
    return NULL;
    
}


void delete_node(node_t **head, int value) {
    node_t *node_to_remove = find_node_by_value(value,*head);

    if (node_to_remove == *head) {
        *head = node_to_remove->next;
        if (node_to_remove->next != NULL) {
            node_to_remove->next->prev = NULL;
        }
        free(node_to_remove);
    
    } 
    else  {
        node_to_remove->prev->next = node_to_remove->next;
        free(node_to_remove);
    }
    
}



void print_linkedlist(node_t *head) {
    node_t *current_node = head;

    while (current_node != NULL)
    {
        printf("%d - ", current_node->value);
        current_node = current_node->next;
    }
    printf("\n");
}


int main(void)
{   

    node_t *head = create_new_node(0);
    node_t *temp = head;



    for (int i = 1; i < 50; i++)
    {
        temp = add_new_node(temp,i);
    }
    
    node_t *test_find_one = find_node_by_value(45,head);

    
    printf("test_find_one:  %d \n",test_find_one->value);

    print_linkedlist(head);

    delete_node(&head,0);
    delete_node(&head,1);
    delete_node(&head,2);
    delete_node(&head,5);

    print_linkedlist(head);



    return 0;  
}



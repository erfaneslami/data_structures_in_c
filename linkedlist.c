#include <stdio.h>
#include <stdlib.h>


struct node
{
    int value;
    struct node* next;
};

typedef struct node node_t;



node_t *create_new_node(int value) {
    node_t *result = malloc(sizeof(node_t));
    result->value = value;
    result->next = NULL;
    return result;  
}


node_t *add_new_node(node_t *pre_node,int value) {
    node_t *new_node = create_new_node(value);
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
    node_t *founded_node = find_node_by_value(value,*head);

    if (founded_node == *head) {
        *head = founded_node->next;
        free(founded_node);
    
    } 
    else  {
        node_t *temp = *head;
        node_t *prev;
        while (temp != NULL && temp->value != value)
        {
            prev = temp;
            temp = temp->next;
            /* code */
        }
        prev->next = founded_node->next;
        free(founded_node);
        

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



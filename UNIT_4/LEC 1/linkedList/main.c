#include <stdio.h>
#include <stdlib.h>

node* head;

int main()
{
    insert_node_at_end(&head,11);
    insert_node_at_end(&head,22);
    insert_node_at_end(&head,33);
    insert_node_at_end(&head,44);
    insert_node_at_end(&head,55);
    insert_node_after(&head,66,5);
    insert_node_after(&head,77,6);
    insert_node_after(&head,88,7);
    delete_node_at_pos(&head,3);
    display_node(head);
        return 0;
}

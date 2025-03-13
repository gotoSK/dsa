#include <stdio.h>
#include <stdlib.h>

typedef struct Stack_LL{
    int data;
    struct Stack_LL* next;
} Node;

int node_no=0;

void push(Node** top){
    Node* node=(Node*)malloc(sizeof(Node));
    if(node==NULL){
        printf("Stack Overflow!");
        return;
    }
    printf("Enter data in this node to push in stack: ");
    scanf("%d", &node->data);
    if(*top==NULL){
        *top=node;
        node->next=NULL;
    }
    else{
        node->next=*top;
        *top=node;
    }
    node_no++;
}
void pop(Node** top){
    if(*top==NULL)
        printf("Stack Underflow!");
    else{
        Node* temp=*top;
        *top=(*top)->next;
        printf("data '%d' popped!\n", temp->data);
        free(temp);
        node_no--;
    }
}
void display(Node** top){
    if(*top==NULL)
        printf("Stack Underflow!\n");
    else{
        Node* ptr=*top;
        int pcount=node_no;
        while(ptr!=NULL){
            printf("node-%d data: %d\n", pcount--, ptr->data);
            ptr=ptr->next;
        }
    }
}

int main(){
    Node* top=NULL;
    int choice;
    while(1){
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("\n? ");
        scanf("%d", &choice);
        switch (choice){
        case 1:
            push(&top);
            break;
        case 2:
            pop(&top);
            break;
        case 3:
            display(&top);
            break;
        case 4:
            return 0;
        default:
            printf("(wrong choice)\n");
            break;
        }
    }
    return 0;
}
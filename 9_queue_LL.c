#include <stdio.h>
#include <stdlib.h>

typedef struct Queue_LL{
    int data;
    struct Queue_LL* next;
} Node;

void enqueue(Node** front, Node** rare){
    Node* node=(Node*)malloc(sizeof(Node));
    if(node==NULL){
        printf("Memory is full, can't create a new node for the queue!");
        return;
    }
    printf("Enter data to enqueue: ");
    scanf("%d", &node->data);
    node->next=NULL;
    if(*front==NULL){
        *front=node;
        *rare=node;
    }
    else{
        (*rare)->next=node;
        *rare=node;
    }
}
void dequeue(Node** front, Node** rare){
    if(*front==NULL)
        printf("Queue is empty!\n");
    else{
        Node* temp=*front;
        *front=(*front)->next;
        if(*front==NULL)
            *rare=NULL;
        printf("data '%d' popped!\n", temp->data);
        free(temp);
    }
}
void display(Node** front, Node** rare){
    if(*front==NULL)
        printf("Queue is empty!\n");
    else{
        Node* ptr=*front;
        int count=0;
        while(ptr!=NULL){
            printf("node-%d data: %d\n", ++count, ptr->data);
            ptr=ptr->next;
        }
    }
}

int main(){
    Node* front=NULL, * rare=NULL;
    int choice;
    while(1){
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("\n? ");
        scanf("%d", &choice);
        switch (choice){
        case 1:
            enqueue(&front, &rare);
            break;
        case 2:
            dequeue(&front, &rare);
            break;
        case 3:
            display(&front, &rare);
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
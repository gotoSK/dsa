#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct sLinkedList{
    int data;
    struct sLinkedList* next;
} Node;

Node* create(){
    Node* node=(Node*)malloc(sizeof(Node));
    printf("Enter (int) data to store: ");
    scanf("%d", &node->data);
    return(node);
}
void addBeg(Node** head){
    Node* node=create();
    if(*head==NULL){
        *head=node;
        node->next=NULL;
    }
    else{
        node->next=*head;
        *head=node;
    }
}
void addEnd(Node** head){
    Node* node=create();
    if(*head==NULL)
        *head=node;
    else{
        Node* ptr=*head;
        while (ptr->next!=NULL)
            ptr=ptr->next; 
        ptr->next=node;
    }
    node->next=NULL;
}
void addPos(Node** head){
    Node* node=create();
    if(*head==NULL){
        *head=node;
        node->next=NULL;
        printf("(Linked list was empty, new node created at pos: 1)\n");
    }
    else{
        int count=0, pos;
        Node* ptr=*head;
        while(ptr!=NULL){
            count++;
            ptr=ptr->next;
        }    
        again:
        printf("Enter positon (1-%d) to create new node: ", count+1);
        scanf("%d", &pos);
        if(pos<1 || pos>count+1){
            printf("Wrong entry!\n");
            goto again;
        }
        if(pos==1){
            node->next=*head;
            *head=node;
        }
        else{
            ptr=*head;
            for (int i=1; i<pos; i++){
                if(i==1)
                    continue;
                else
                    ptr=ptr->next;
            }
            if(pos==count+1){
                ptr->next=node;
                node->next=NULL;
            }
            else{
                node->next=ptr->next;
                ptr->next=node;
            }
        }
    }
}
void delBeg(Node** head){
    if(*head==NULL){
        printf("Linked list is empty!\n"); 
        return;
    }
    Node* temp=*head;
    *head=(*head)->next;
    free(temp);
}
void delEnd(Node** head){
    if(*head==NULL)
        printf("Linked list is empty!\n");
    else if ((*head)->next==NULL){
        free(*head);
        *head=NULL;
    }
    else{
        Node * ptr1=*head, * ptr2=*head;
        while(ptr2->next!=NULL){
            ptr1=ptr2;
            ptr2=ptr2->next;
        }
        free(ptr2);
        ptr1->next=NULL;
    }
}
void delPos(Node** head){
    if(*head==NULL)
        printf("Linked list is empty!\n");
    else{
        Node * ptr1=*head, * ptr2=*head;
        int count=0, pos;
        while(ptr2!=NULL){
            count++;
            ptr2=ptr2->next;
        }ptr2=*head;
        again:
        printf("Enter the positon (1-%d) of node: ", count);
        scanf("%d", &pos);
        if(pos<1 || pos>count){
            printf("Wrong entry!\n");
            goto again;
        }
        if(pos==1){
            *head=(*head)->next;
            free(ptr2);
        }
        else{
            for(int i=1; i<pos; i++){
                ptr1=ptr2;
                ptr2=ptr2->next;
            }
            ptr1->next=ptr2->next;
            free(ptr2);
        }
    }
}
void display(Node** head){
    if(*head==NULL){
        printf("Linked list is empty!\n"); 
        return;
    }
    Node* ptr=*head;
    int count=0;
    while(ptr!=NULL){
        printf("node-%d data: %d\n", ++count, ptr->data);
        ptr=ptr->next;
    }
}

int main(){
    Node* head=NULL;
    int choice;
    while (1){
        printf("\n1. Add to begining\n2. Add to End\n3. Add at any position\n");
        printf("4. Delete from begining\n5. Delete from End\n6. Delete from any position");
        printf("\n7. Display\n8. Exit");
        printf("\n\n? ");
        scanf("%d", &choice);
        switch (choice){
        case 1:
            addBeg(&head);
            break;
        case 2:
            addEnd(&head);
            break;
        case 3:
            addPos(&head);
            break;
        case 4:
            delBeg(&head);
            break;
        case 5:
            delEnd(&head);
            break;
        case 6:
            delPos(&head);
            break;
        case 7:
            display(&head);
            break;
        case 8:
            return 0;
        default:
            printf("(wrong choice)\n");
            break;
        }
    }
    getch();
    return 0;
}
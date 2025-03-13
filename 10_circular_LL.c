#include <stdio.h>
#include <stdlib.h>

typedef struct cLinkedList{
    int data;
    struct cLinkedList* next;
} Node;

Node* create(){
    Node* node=(Node*)malloc(sizeof(Node));
    printf("Enter (int) data to store: ");
    scanf("%d", &node->data);
    return(node);
}
void addBeg(Node** head, Node** tail){
    Node* node=create();
    if(*head==NULL){
        *head=node;
        *tail=node;
        node->next=node;
    }
    else{
        node->next=*head;
        *head=node;
        (*tail)->next=*head;
    }
}
void addEnd(Node** head, Node** tail){
    Node* node=create();
    if(*head==NULL){
        *head=node;
        *tail=node;
    }
    else{
        (*tail)->next=node;
        *tail=node;
    }
    node->next=*head;
}
void addPos(Node** head, Node** tail){
    Node* node=create();
    if(*head==NULL){
        *head=node;
        *tail=node;
        node->next=*head;
        printf("(Linked list was empty, new node created at pos: 1)\n");
    }
    else{
        int count=0, pos;
        Node* ptr=*head;
        do{
            count++;
            ptr=ptr->next;
        } while (ptr!=*head);
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
            *tail=node;
        }
        else if(pos==count+1){
            (*tail)->next=node;
            *tail=node;
            node->next=*head;
        }
        else{
            ptr=*head;
            for (int i=1; i<pos; i++){
                if(i==1)
                    ptr=ptr;
                else
                    ptr=ptr->next;
            }
            node->next=ptr->next;
            ptr->next=node;
        }
    }
}
void delBeg(Node** head, Node** tail){
    if(*head==NULL){
        printf("Linked list is empty!\n"); 
        return;
    }
    Node* temp=*head;
    *head=(*head)->next;
    (*tail)->next=*head;
    if(*head==temp){
        *head=NULL;
        *tail=NULL;
    }
    free(temp);
}
void delEnd(Node** head, Node** tail){
    if(*head==NULL)
        printf("Linked list is empty!\n");
    else if ((*head)->next==*head){
        free(*head);
        *head=NULL;
        *tail=NULL;
    }
    else{
        Node * ptr1=*head, * ptr2=*head;
        do{
            ptr1=ptr2;
            ptr2=ptr2->next;
        } while (ptr2->next!=*head);
        free(ptr2);
        ptr1->next=*head;
        *tail=ptr1;
    }
}
void delPos(Node** head, Node** tail){
    if(*head==NULL)
        printf("Linked list is empty!\n");
    else{
        Node * ptr1=*head, * ptr2=*head;
        int count=0, pos;
        do{
            count++;
            ptr2=ptr2->next;
        } while (ptr2!=*head);
        ptr2=*head;
        again:
        printf("Enter the positon (1-%d) of node: ", count);
        scanf("%d", &pos);
        if(pos<1 || pos>count){
            printf("pos '%d' doesn't exit!\n",pos);
            goto again;
        }
        if(pos==1){
            free(*head);
            *head=NULL;
            *tail=NULL;
        }
        else{
            for(int i=1; i<pos; i++){
                ptr1=ptr2;
                ptr2=ptr2->next;
            }
            ptr1->next=ptr2->next;
            if(ptr1->next==*head)
                *tail=ptr1;
            free(ptr2);
        }
    }
}
void display(Node* head){
    if(head==NULL){
        printf("Linked list is empty!\n"); 
        return;
    }
    Node* ptr=head;
    int count=0;
    do{
        printf("node-%d data: %d\n", ++count, ptr->data);
        ptr=ptr->next;
    } while (ptr!=head);
}

int main(){
    Node* head=NULL, * tail=NULL;
    int choice;
    while (1){
        printf("\n1. Add to begining\n2. Add to End\n3. Add at any position\n");
        printf("4. Delete from begining\n5. Delete from End\n6. Delete from any position");
        printf("\n7. Display\n8. Exit");
        printf("\n\n? ");
        scanf("%d", &choice);
        switch (choice){
        case 1:
            addBeg(&head, &tail);
            break;
        case 2:
            addEnd(&head, &tail);
            break;
        case 3:
            addPos(&head, &tail);
            break;
        case 4:
            delBeg(&head, &tail);
            break;
        case 5:
            delEnd(&head, &tail);
            break;
        case 6:
            delPos(&head, &tail);
            break;
        case 7:
            display(head);
            break;
        case 8:
            return 0;
        default:
            printf("(wrong choice)\n");
            break;
        }
    }
    return 0;
}
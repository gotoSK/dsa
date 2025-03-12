#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 5

struct CQueue
{
    int rear, front, data[SIZE];
};

void enqueue(struct CQueue *cq){
    if((cq->rear+1)%SIZE == cq->front)
        printf("Overflow!");
    else{
        if(cq->front==-1)
            cq->front++;
        int el;
        printf("Element to insert: ");
        scanf("%d", &el);
        cq->rear = (cq->rear+1)%SIZE;
        cq->data[cq->rear]=el;
    }
}

void dequeue(struct CQueue *cq){
    if(cq->front==-1)
        printf("Underflow!");
    else{
        if(cq->front==cq->rear){
            printf("Dequeued element '%d'", cq->data[cq->front]);
            cq->front=-1;
            cq->rear=-1;
        }
        else{
            printf("Dequeued element '%d'", cq->data[cq->front]);
            cq->front = (cq->front+1)%SIZE;
        }
    }
}

void display(struct CQueue *cq){
    if(cq->front==-1)
        printf("Underflow!");
    else{
        int i;
        for(i=cq->front; i!=cq->rear; i=(i+1)%SIZE)
            printf("%d\t", cq->data[i]);
        printf("%d\t", cq->data[i]);
    }
}

int main(){
    system("cls");

    struct CQueue cq;
    cq.rear=-1;
    cq.front=-1;
    
    while (1)
    {
        int choice;
        printf("Menu:\n1)Enqueue\n2)Dequeue\n3)Display\nchoice = ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue(&cq);
            printf("\n\n");
            break;
        case 2:
            dequeue(&cq);
            printf("\n\n");
            break;
        case 3:
            display(&cq);
            printf("\n\n");
            break;
        default:
            break;
        }
    }

    getch();
    return 0;
}

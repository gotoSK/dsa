#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 4

struct Queue
{
    int rear, front, item[SIZE];
};

void enqueue(struct Queue *q){
    if(q->rear==SIZE-1)
        printf("Overflow!");
    else{
        int el;
        printf("Element to insert: ");
        scanf("%d", &el);
        q->rear++;
        q->item[q->rear]=el;
    }
}

void dequeue(struct Queue *q){
    if(q->rear<q->front)
        printf("Underflow!");
    else{
        printf("Dequeued element '%d'", q->item[q->front]);
        q->front++;
    }
}

void display(struct Queue *q){
    if(q->rear<q->front)
        printf("Underflow!");
    else{
        for(int i=q->front; i<=q->rear; i++)
            printf("%d\t", q->item[i]);
    }
}

int main(){
    system("cls");

    struct Queue q;
    q.rear=-1;
    q.front=0;
    
    while (1)
    {
        int choice;
        printf("Menu:\n1)Enqueue\n2)Dequeue\n3)Display\nchoice = ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue(&q);
            printf("\n\n");
            break;
        case 2:
            dequeue(&q);
            printf("\n\n");
            break;
        case 3:
            display(&q);
            printf("\n\n");
            break;
        default:
            break;
        }
    }
    

    getch();
    return 0;
}

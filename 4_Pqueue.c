#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<limits.h>

struct PQueue
{
    int value, priority;
};
struct PQueue pq[5];
int size=-1;

void enqueue(){
    if(size==4)
        printf("Overflow!");
    else{
        size++;
        printf("Element to insert: ");
        scanf("%d", &pq[size].value);
        printf("Priority: ");
        scanf("%d", &pq[size].priority);
    }
}

int peek(){
    int hPri=INT_MIN, ind=-1;
    for(int i=0; i<=size; i++){
        if(hPri < pq[i].priority){
            hPri=pq[i].priority;
            ind=i;
        }
        else if(hPri==pq[i].priority && ind>-1 && pq[i].value>pq[ind].value){
            hPri=pq[i].priority;
            ind=i;            
        }
    }
    if(ind==-1){
        printf("Underflow!");
        return ind;
    }
    printf("Peeked element '%d'", pq[ind].value);
    return ind;
}

void dequeue(){
    int ind=peek();
    if(ind==-1)
        printf("Underflow!");
    else{
        printf(" has been dequeed.");
        for(int i=ind; i<size; i++){
            pq[i]=pq[i+1];
            size--;
        }
    }
}

void display(){
    if(size==-1)
        printf("Underflow!");
    else{
        printf("size\tvalue\tpriority\n");
        for(int i=0; i<=size; i++){
            printf("%d\t%d\t%d\n", i, pq[i].value, pq[i].priority);
        }
    }
}

int main(){
    system("cls");

    while (1)
    {
        int choice;
        printf("1)Enqueue\n2)Dequeue\n3)Peek\n4)Display\nchoice = ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            printf("\n\n");
            break;
        case 2:
            dequeue();
            printf("\n\n");
            break;
        case 3:
            peek();
            printf("\n\n");
            break;
        case 4:
            display();
            printf("\n\n");
            break;
        default:
            printf("Invalid choice!");
            printf("\n\n");
            break;
        }
    }

    getch();
    return 0;
}
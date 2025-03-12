#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define SIZE 5

struct Stack
{
    int top;
    int item[SIZE];
};

void push(struct Stack *s){
    if(s->top==SIZE-1)
        printf("Overflow!");
    else{
        int entry;
        printf("Enter integer to be pushed: ");
        scanf("%d", &entry);
        s->top++;
        s->item[s->top]=entry;
    }
}

void pop(struct Stack *s){
    if(s->top==-1)
        printf("Underflow!");
    else{
        printf("Popped element '%d'", s->item[s->top]);
        s->top--;
    }
}

void display(struct Stack *s){
    if(s->top==-1)
        printf("Underflow!");
    else{
        for(int i=s->top; i>=0; i--)
            printf("%d\t", s->item[i]);
    }
}

int main(){
    system("cls");

    struct Stack s;
    s.top=-1;

    while (1)
    {
        int choice;
        printf("Menu:\n1) Display\n2) PUSH\n3) POP\nchoice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            display(&s);
            printf("\n\n");
            break;
        case 2:
            push(&s);
            printf("\n\n");
            break;
        case 3:
            pop(&s);
            printf("\n\n");
            break;
        default:
            printf("Invalid choice!");
            break;
        }
    }
    
    getch();
    return 0;
}
#include <stdio.h>
#include <conio.h>

int gcd(int n1, int n2){
    if(n2!=0)
        return gcd(n2, n1%n2);
    else
        return n1;
}

int fact(int n){
    if(n==0)
        return 1;
    else
        return (n*fact(n-1));
}

int fibo(int n){
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    else
        return (fibo(n-1)+fibo(n-2));
}

void TOH(char S, char T, char A, int n){
    if(n==1)
        printf("Disc-%d %c to %c", n, S, T);
    else{
        TOH(S, A, T, n-1);
        printf("\nDisc-%d %c to %c\n", n, S, T);
        TOH(A, T, S, n-1);
    }
}

int main(){
    int choice;
    while (1){
        printf("1. GCD\n2. Factorial\n3. Fibonacci\n4. TOH\n5. Exit");
        printf("\n? ");
        scanf("%d", &choice);
        switch (choice){
        case 1:
            int n1, n2;
            printf("\nEnter 2 numbers: ");
            scanf("%d %d", &n1, &n2);
            printf("GCD = %d\n\n", gcd(n1, n2));
            break;
        case 2:
            int n;
            printf("\nEnter a number: ");
            scanf("%d", &n);
            printf("Facrorial = %d\n\n", fact(n));
            break;
        case 3:
            printf("\nEnter length of series: ");
            scanf("%d", &n);
            for (int i=0; i<n; i++)
                printf("i=%d\t%d\n", i, fibo(i));
            printf("\n");
            break;
        case 4:
            printf("\nEnter number of discs: ");
            scanf("%d", &n);
            TOH('S','T','A',n);
            printf("\n\n");
            break;
        case 5:
            break;
        default:
            printf("(Invalid Choice)\n\n");
            break;
        }
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#define SIZE 6

void input(int a[]){
    for(int i=0; i<SIZE; i++){
        printf("[%d]=", i);
        scanf("%d", &a[i]);
    }
}
void copy(int a[], int temp[]){
    for(int i=0; i<SIZE; i++)
        temp[i]=a[i];
}
void menu(){
    printf("1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Shell Sort\n");
    printf("5. Merge Sort\n6. Quick Sort\n7. Heap Sort\n8. Exit\n");
}
void display(int a[]){
    for(int i=0; i<SIZE; i++){
        printf("%d\t", a[i]);
    }
}
void swap(int* a, int* b){
    int temp=*b;
    *b=*a;
    *a=temp;
}


void bubble_sort(int a[]){
    printf("Your initial order: \n");
    display(a);
    for(int i=0; i<SIZE-1; i++){
        for(int j=0; j<SIZE-i-1; j++){
            if(a[j]>a[j+1])
                swap(&a[j], &a[j+1]);
        }
    }
    printf("\nSorted order: \n");
    display(a);
}
void selection_sort(int a[]){
    printf("Your initial order: \n");
    display(a);
    for(int i=0; i<SIZE-1; i++){
        int min_idx=i;
        for(int j=i+1; j<SIZE; j++){
            if(a[j]<a[min_idx])
                min_idx=j;
        }
        if(min_idx!=i)
            swap(&a[i], &a[min_idx]);
    }
    printf("\nSorted order: \n");
    display(a);
}
void insertion_sort(int a[]){
    printf("Your initial order: \n");
    display(a);
    for(int i=1; i<SIZE; i++){
        int j, temp=a[i];
        for(j=i-1; j>=0 && a[j]>temp; j--)
            a[j+1]=a[j];
        a[j+1]=temp;
    }
    printf("\nSorted order: \n");
    display(a);
}
void shell_sort(int a[]){
    printf("Your initial order: \n");
    display(a);
    int gap=SIZE/2;
    while(gap>0){
        for(int i=0; (i+gap)<SIZE; i++){
            if(a[i]>a[i+gap]){
                swap(&a[i], &a[i+gap]);
                if(i>=gap){
                    if(a[i-gap]>a[i])
                        swap(&a[i-gap], &a[i]);
                }
            }
        }
        gap/=2;
    }
    printf("\nSorted order: \n");
    display(a);
}
void merge(int a[], int l, int m, int h){
    int i=l, j=m+1, k=l, temp[h+1];
    while(i<=m && j<=h){
        if(a[i]<a[j])
            temp[k++]=a[i++];
        if(a[i]>a[j])
            temp[k++]=a[j++];
    }
    while(i<=m)
        temp[k++]=a[i++];
    while(j<=h)
        temp[k++]=a[j++];
    for(i=l; i<=h; i++)
        a[i]=temp[i];
}
void merge_sort(int a[], int l, int h){
    if(l<h){
        int m=(l+h)/2;
        merge_sort(a, l, m);
        merge_sort(a, m+1, h);
        merge(a, l, m, h);
    }
}
int partition(int a[], int low, int high){
    int s=low, g=high;
    while(g>s){
        while(a[s]<=a[low])  s++;
        while(a[g]>a[low])  g--;
        if(g>s)
            swap(&a[s], &a[g]);
    }
    swap(&a[low], &a[g]);
    return g;
}
void quick_sort(int a[], int l, int h){
    if(l<h){
        int pos=partition(a, l, h);
        quick_sort(a, l, pos-1);
        quick_sort(a, pos+1, h);
    }
}
void heapify(int a[], int n, int i){
    int large=i;
    if(2*i+1<n && a[2*i+1]>a[large])
        large=2*i+1;
    if(2*i+2<n && a[2*i+2]>a[large])
        large=2*i+2;
    if(i!=large){
        swap(&a[i], &a[large]);
        heapify(a, n, large);
    }
}
void build_heap(int a[]){
    for(int i=(SIZE/2)-1; i>=0; i--)
        heapify(a, SIZE, i);
}
void heap_sort(int a[]){
    printf("Your initial order: \n");
    display(a);
    build_heap(a);
    for(int i=SIZE-1; i>0; i--){
        swap(&a[0], &a[i]);
        heapify(a, i, 0);
    }
    printf("\nSorted order: \n");
    display(a);
}

int main(){
    system("cls");
    int array[SIZE];
    printf("Enter your array (size=%d): \n", SIZE);
    input(array);

    int ini_ar[SIZE];
    copy(array, ini_ar);

    system("cls");
    int choice=0;
    while(1){
        printf("\n-----------------------------------------------\n");
        if(choice!=0){
            printf("1. Use previous array\n2. Create a new array\n? ");
            scanf("%d", &choice);
            if(choice==1)
                copy(ini_ar, array);
            else{
                input(array);
                copy(array, ini_ar);
            }
            printf("\n");
        }
        menu();
        printf("\nchoice=");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("(Bubble Sort)\n\n");
                bubble_sort(array);
                printf("\n");
                break;
            case 2:
                printf("(Selection Sort)\n\n");
                selection_sort(array);
                printf("\n");
                break;
            case 3:
                printf("(Insertion Sort)\n\n");
                insertion_sort(array);
                printf("\n");
                break;
            case 4:
                printf("(Shell Sort)\n\n");
                shell_sort(array);
                printf("\n");
                break;
            case 5:
                printf("(Merge Sort)\n\n");
                printf("Your initial order: \n");
                display(array);
                merge_sort(array, 0, SIZE-1);
                printf("\nSorted order: \n");
                display(array);
                printf("\n");
                break;
            case 6:
                printf("(Quick Sort)\n\n");
                printf("Your initial order: \n");
                display(array);
                quick_sort(array, 0, SIZE-1);
                printf("\nSorted order: \n");
                display(array);
                printf("\n");
                break;
            case 7:
                printf("(Heap Sort)\n\n");
                heap_sort(array);
                printf("\n");
                break;
            case 8:
                return 0;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}
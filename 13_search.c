#include <stdio.h>

int arr[6]={10,20,30,40,50,60}, n=sizeof(arr)/sizeof(arr[0]);
void display(){
    for(int i=0; i<n; i++)
        printf("%d\t", arr[i]);
    printf("\n");
    for(int i=0; i<n; i++)
        printf("[%d]\t", i);
    printf("\n");
}

int linear_srch(int key){
    for(int i=0; i<n; i++){
        if(arr[i]==key)
            return i;
    }
    return -1;
}
int bin_srch(int key, int low, int high){
    if(low>high)
        return -1;
    else{
        int mid=(low+high)/2;
        if(key==arr[mid])
            return mid;
        else if(key>arr[mid])
            return bin_srch(key, mid+1, high);
        else
            return bin_srch(key, low, mid-1);
    }
}
int bin_srch_itt(int key){
    int low=0, high=n-1;
    for(int i=(low+high)/2; low<=high; i=(low+high)/2){
        if(key==arr[i])
            return i;
        else if(key<arr[i])
            high=i-1;
        else
            low=i+1;
    }
    return -1;
}

int main(){
    int choice, key, ind;
    while(1){
        printf("1. Linear Search\n2. Binary Search\n3. Binary Search (Itterative)\n4. Exit\n");
        printf("choice=");
        scanf("%d", &choice);
        display();
        switch(choice){
            case 1:
                printf("Item to search? ");
                scanf("%d", &key);
                ind=linear_srch(key);
                if(ind==-1)
                    printf("'%d' not found!\n\n", key);
                else
                    printf("'%d' found at [%d]\n\n", key, ind);
                break;
            case 2:
                printf("Item to search? ");
                scanf("%d", &key);
                ind=bin_srch(key, 0, n-1);
                if(ind==-1)
                    printf("'%d' not found!\n\n", key);
                else
                    printf("'%d' found at [%d]\n\n", key, ind);
                break;
            case 3:
                printf("Item to search? ");
                scanf("%d", &key);
                ind=bin_srch_itt(key);
                if(ind==-1)
                    printf("'%d' not found!\n\n", key);
                else
                    printf("'%d' found at [%d]\n\n", key, ind);
                break;
            case 4:
                return 0;
            default:
                break;
        }
    }
    return 0;
}

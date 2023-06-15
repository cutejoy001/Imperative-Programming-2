#include<stdio.h>
#include <stdlib.h>  
#include <time.h>

struct Max{
    int max;
    int index;
};
/*
int calculateSum(int arr[], int size){
    int sum = 0;
    for(int i=0;i<size;i++){
        sum += arr[i];
    }
    return sum;
}
*/

int calculateSum(int arr[], int size){
    int sum = 0;
    int *pos = arr;
    int *end = arr + size - 1;

    while (pos <= end){
        sum += *pos;
        pos++;
    }
    return sum;
}

/*
//Without using pointers
struct Max findMaximum(int arr[], int size){
    struct Max max;
    max.max = arr[0],max.index = 0;
    for(int i=1;i<size;i++){
        if(arr[i] > max.max){
            max.max = arr[i];
            max.index = i;
        }
    }
    return max;
}
*/

//Using pointers
struct Max findMaximum(int arr[], int size){
    struct Max max;
    int *pos = arr;
    int *end = arr + size - 1;
    max.max = *pos;
    while (pos < end){
        if(*pos > max.max){
            max.max = *pos;
            max.index = pos - arr;
        }
        pos++;
    }
    return max;
}

void reverseArray(int *arr, int size){
    int *pos = arr;
    int *end = arr + size - 1;
    while (pos < end){
        int temp = *pos;
        *pos = *end;
        *end = temp;
        pos++;
        end--;
    }
}



int main(){
    srand(time(0));
    
    int arr[10];
    for(int i=0;i<10;i++){
        int num = rand() % 100 + 1;
        arr[i] = num;
    }

    printf("Original Array: ");
    for(int i=0;i<10;i++){
        printf("%d ",arr[i]);
    }

    printf("\nSum of all elements: %d",calculateSum(arr,10));
    printf("\nMaximum element: %d, Index: %d",findMaximum(arr,10).max, findMaximum(arr,10).index);

    
    reverseArray(arr,10);
    printf("\nReversed array : ");
    for(int i=0;i<10;i++){
        printf("%d ",arr[i]);
    }


    
    return 0;
}
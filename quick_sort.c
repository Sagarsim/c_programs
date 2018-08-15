#include <stdio.h>
void swap(int* x, int* y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void quicksort(int arr[10], int first, int last){
    int i, j, pivot;
    
   if(first<last){
        i = first;
        j = last;
        pivot = first;
        while(i<j){
            while(arr[i] <= arr[pivot] && i < last) {
                    i++;
                    }
            while(arr[j] > arr[pivot]) {
                    j--;
                    }
            if(i<j){
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[j], &arr[pivot]);
        quicksort(arr, first, j - 1);
        quicksort(arr, j + 1, last);
    }

}
int main(){
    int data[10],i,count;
    printf("Enter no, of elements: ");
    scanf("%d", &count);
    for(i = 0;i < count;i++){
        printf("Enter no:");
        scanf("%d", &data[i]);
    }
    quicksort(data, 0, count - 1);
    printf("After sorting:\n");
    for(i = 0;i < count;i++){
        printf("%d ", data[i]);
    }
return 0;
}
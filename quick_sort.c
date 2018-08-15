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
}#include <stdio.h>
int partition(int a[], int low, int high){
	int left, right, pivot_item=a[low],temp;
	left=low;
	right=high;

	while(left<right){
		while(a[left]<=pivot_item){
			left++;
		}
		while(a[right]>pivot_item){
			right--;
		}
		if(left<right){
			temp=a[left];
			a[left]=a[right];
			a[right]=temp;

		}

	}
a[low]=a[right];
a[right]=pivot_item;
return right;
}

void quick(int a[],int low,int high){
	int pivot;
	if (high>low)
	{
		pivot=partition(a, low, high);
		quick(a, low, pivot-1);
		quick(a, pivot+1, high);
	}
}

int main(){
	int a[]={66,22,11,44,55};
	int low, high, i;
	low=0;
	high=4;
	quick(a,low,high);
for(i = 0; i<5;i++){
	printf("%d ",a[i] );
}
return 0;
}
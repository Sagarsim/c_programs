#include <stdio.h>
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
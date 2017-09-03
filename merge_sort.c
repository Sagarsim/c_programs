#include <stdio.h>

void Merge(int a[], int temp[], int left, int mid, int right){
int i, left_end, temp_pos, size;
left_end=mid-1;
temp_pos=left;
size=right-left+1;

while ((left <= left_end) && (mid <= right)){
	if(a[left]<=a[mid]){
		temp[temp_pos]=a[left];
		
		left=left+1;
	}else{
		temp[temp_pos]=a[mid];
		
		mid=mid+1;
	}
	temp_pos=temp_pos+1;
}
while(left <= left_end){
		temp[temp_pos]=a[left];
		temp_pos=temp_pos+1;
		left=left+1;
}
while(mid <= right){
		temp[temp_pos]=a[mid];
		temp_pos=temp_pos+1;
		mid=mid+1;
}
for (i = 0; i <= size; i++)
{
	a[right]=temp[right];
	right=right-1;
}
}


void Mergesort(int a[], int temp[], int left, int right){
	int mid;
	if(right > left){
		mid=(left+right)/2;
		Mergesort(a, temp, left, mid);
		Mergesort(a, temp, mid+1, right);
		Merge(a, temp, left, mid+1, right);
	}
}

int main(){
	int a[]={2,3,8,5,4,6,7,1};
	int left,right,temp[8];
	int z;
	left=0;
	right=7;
	Mergesort(a, temp, left, right);
for(z = 0; z <=7; z++)
{
	printf("%d ",a[z]);

}
return 0;

}
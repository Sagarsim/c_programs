#include <stdio.h>
#include <stdbool.h>

int main(){

int a[5],i,j,temp;
bool flag=false;
	printf("Enter five nos:");
for (i = 0; i < 5; ++i)
{
	scanf("%d", &a[i]);	
}
for (i = 0; i < 5; ++i)
{
	for (j = i+1; j < 5; ++j)
	{
		if (a[i]>a[j])
		{
			temp=a[j];
			a[j]=a[i];
			a[i]=temp;
			flag = true;
		}
	}
	if(flag == true){
		break;
	}
}
printf("Sorted List:-\n");
for (i = 0; i < 5; ++i)
{
	printf("%d ", a[i]);
}
return 0;
} 
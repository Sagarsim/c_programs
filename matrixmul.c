#include<stdio.h>
#include<conio.h>
void main()
{
    int a[3][4],b[3][3],c[3][3],i,j,k,sum;
    for(i=0;i<3;i++)
    {
    for(j=0;j<3;j++)
    {
        printf("Enter values for a:");
        scanf("%d",&a[i][j]);
    }
    }
    printf("\n\n==CONTENTS OF MATRIX a ARE==\n\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",a[i][j]);
        }printf("\n");
    }
       for(i=0;i<3;i++)
    {
    for(j=0;j<3;j++)
    {
        printf("Enter values for b:");
        scanf("%d",&b[i][j]);
    }
    }
    printf("\n\n==CONTENTS OF MATRIX b ARE==\n\n");
      for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",b[i][j]);
        }printf("\n");
    }

    for(i=0;i<3;i++)
    {
    for(j=0;j<3;j++)
    {sum=0;
      for(k=0;k<3;k++)
      {
          sum=sum+(a[i][k]*b[k][j]);
          c[i][j]=sum;
      }
    }
    }
      printf("\n\n==MULTIPLICATION OF a & b IS==\n\n");
     for(i=0;i<3;i++)
    {
    for(j=0;j<3;j++)
    {
      printf("%d ",c[i][j]);
    }printf("\n");
    }
    getch();
}


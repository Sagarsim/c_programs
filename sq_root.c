#include <stdio.h>
#include <conio.h>
#include <time.h>
int main(){
   int mid,a, x, end, start, ans;
   double diff;
   clock_t st,et;
   printf("Enter No:\n");
   scanf("%d", &x);
   
   start=1;
   end = x;
   st=clock();
   while(start <= end){
             mid = (start+end)/2;
             a=mid*mid;
             if(a == x)
             {
              ans=mid;
              printf("Ans=%d",ans); 
              et= clock();
              return 0;
              }  
        else if(a < x)
        {
                       start=mid+1;
                       ans = mid;
                 }
                 else{
                      end=mid-1;
                     }
   }
   
     printf("Ans=%d\n",ans); 
     et = clock();
     diff=et-st;
     printf("Time=%f",diff);
     getch();
     return 0;
     }
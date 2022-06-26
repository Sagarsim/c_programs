#include <stdio.h>
#include <string.h>

int main(){

    char msg[] = "hello";
    char matrix[5][5];
    int i,j,x;
    char letters[] = "abcdefghiklmnopqrstuvwxyz", final[25];
    int count[25], counter=0;
    
    for(i = 0; i < 25; i++){
        count[i] = 0;
    }
    for(i = 0; i < 5; i++){
        for(j = 0; j < 25; j++){
            if(msg[i] == letters[j]){
                count[j]++;
                if(count[j] == 1){
                    final[counter] = msg[i]; 
                    printf("%c\n", final[counter]);
                    counter++;
                } 
                
            }

        }
    }

counter = 4;
for(i = 0; i<25;i++){
    if(count[i] == 0){
        final[counter] = letters[i];
        counter++;
    }
}

    for(i=0;i<25;i++){
    printf("%d ", count[i]);
    }
          
              printf("\n%s\n", final);
           
    counter = 0;

    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            matrix[i][j] = final[counter];
            counter++;
        }
    }
printf("\n\nMatrix:-\n\n");
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
   return 0;
}
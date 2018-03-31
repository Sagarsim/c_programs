#include <stdio.h>
#include <stdbool.h>
int main(){
    int x,i,j,key = 3;

    char plaintext[10] = "helloworld";
    int msg_length = 10;
    char ciphertext[msg_length];
    char matrix[key][msg_length];
    
    bool flag=false;
    for(i=0;i<key;i++){
        for(j=0;j<msg_length;j++){
            matrix[i][j] = 0;
        }
    }
    x = 0;
    i = 0;
    j = 0;
    
    while(x!=msg_length){
        
        
        if(i == 0 || i == key-1){
            flag = !flag;
        }
        matrix[i][j] = plaintext[x];
        j++;
        x++;
        if(flag){
            i++;
        }
        else{
            i--;
        }
        
    }
    for(i=0;i<key;i++){
        for(j=0;j<msg_length;j++){
            printf("%c  ", matrix[i][j]);
        }printf("\n");
    }
    x=-1;
    for(i=0;i<key;i++){
        for(j=0;j<msg_length;j++){
            if(matrix[i][j] != 0){
                x++;
           ciphertext[x] = matrix[i][j];
           
            }
        }
    }

printf("\n%s",ciphertext);
        return 0;
}
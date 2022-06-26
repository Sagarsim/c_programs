#include <stdio.h>
int main() {
    int s;
    scanf("%d", &s);
    int k, l, m, n, x, i, j, p , z;
    
    k=l=0;
    x=p=1;
    
    
    int w[s][s];
    m = n = s;
    while (k < m && l < n) {
      for (i = l; i < n; ++i) {
        w[k][i] = x;
        x++;
      }
      k++;

      for (i = k; i < m; ++i) {

        w[i][n - 1] = x;
        x++;
      }
      n--;

      if (k < m) {
        for (i = n - 1; i >= l; --i) {

          w[m - 1][i] = x;
          x++;
        }
        m--;
      }

      if (l < n) {
        for (i = m - 1; i >= k; --i) {

          w[i][l] = x;
          x++;
        }
        l++;
      }
    }
   
    
    
    for (i = 0; i < s; i++) {
      for (j = 0; j < s; j++) {
        printf("%d\t", w[i][j]);
        if (w[i][j] % 11 == 0) {
          p++;
        }

      }
      printf("\n");
    }
    printf("Total Power points : %d\n", p);
    printf("(0,0)\n");
     for (z = 1; z < s; z++) {
      for (i = 0; i < s; i++) {
        for (j = 0; j < s; j++) {

          if (z * 11 == w[i][j]) {
            printf("(%d,%d)\n", i, j);

          }

        }
      }
    }
   
    return 0;
  }
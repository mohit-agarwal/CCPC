#include<stdio.h>
#include "../../../src/io/BufferedIO/BufferedInput.h"

int main() {
    struct BufferedInputStream * bis = bufferedInputStream(786432ull/20);
    int n,m,k;
    long double d;
    n = bufferedReadInt(bis);
    m=n;
    printf("%d\n", n);
    while(m--) {
      k = bufferedReadInt(bis);
      printf("%d\n", k);
    }
    m=n;
    while(m--) {
      d = bufferedReadLongDouble(bis);
      printf("%.6LF\n", d);
    }
    m=n;
    while(m--) {
      k = bufferedReadInt(bis);
      d = bufferedReadLongDouble(bis);
      printf("%d\n", k);
      printf("%.6LF\n", d);
    }    
    return 0;
}

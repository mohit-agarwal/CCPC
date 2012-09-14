#include<stdio.h>
#include "BufferedInput.h"

int main() {
    struct BufferedInputStream * bis = bufferedInputStream();
    int n;
    long double d;
    n = bufferedReadInt(bis);
    printf("%d\n", n);
    while(n--) {
      d = bufferedReadLongDouble(bis);
      printf("%.6LF\n", d);
    }
    return 0;
}

#include<stdio.h>
#include "BufferedInput.h"

int main() {
    struct BufferedInputStream * bis = bufferedInputStream();
    int d, n;
    n = bufferedReadInt(bis);
    printf("%d\n", n);
    while(n--) {
      d = bufferedReadInt(bis);
      printf("%d\n", d);
    }
    return 0;
}

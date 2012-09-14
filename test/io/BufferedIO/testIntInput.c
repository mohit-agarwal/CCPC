#include<stdio.h>
#include "BufferedInput.h"

int main() {
    struct BufferedInputStream * bis = bufferedInputStream(786432ull/20);
    int d, n;
    n = bufferedReadInt(bis);
    printf("%d\n", n);
    while(n--) {
      d = bufferedReadInt(bis);
      printf("%d\n", d);
    }
    return 0;
}


#include <stdio.h>


void test(int * n) {
  (*n)++;
}

int main(void) {

  int n  = 0;

  test(&n);

  printf("%d", n);
  return 0;

}

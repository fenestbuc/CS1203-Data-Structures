// Stress-test for loops
// Play around with the decimal points of for loop to see when they break down
#include <stdio.h>

int main() {
  double i;
  for (i = 0.1; i <= 1.0; i += 0.1) {
    if (i + 0.1 == i) {
      printf("Loop broke down at i = %.1f\n", i);
      break;
    }
  }
  return 0;
}

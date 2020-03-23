#include <iostream>
#include <cstdlib>
#include <cassert>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd_fast(int a, int b) {
  if(a == 0)
    return b;
  return gcd_fast(b%a, a);
}

int test() {
  while(1) {
    int a = rand()%1000000000;
    int b = rand()%1000000000;
    if(gcd_naive(a, b) != gcd_fast(a, b)) {
      std::cout << "Wrong Answer!\n";
      std::cout << "a = " << a << " b = " << b << "\n";
      break;
    }
    else
      std::cout << "Correct answer\n";
  }
}

int main() {
  //test();
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_naive(a, b) << std::endl;
  return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;



int main(void) {
  int array[] = {3, 4, 5, 6, 7, 8, 9};
  int x = 7;
  int n = sizeof(array) / sizeof(array[0]);
  
  if (binary_search(array, array + n, x))
    printf("found");
  else
    printf("no");
}

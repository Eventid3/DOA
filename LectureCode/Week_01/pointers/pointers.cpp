#include <cassert>

int main()
{
  int a[5] = {0, 1, 2, 3, 4};
  int * p = a;
  assert(*p == a[0]);
  assert(*p+1 == a[1]);
  assert(*(p+3) == a[3]);
  p++;
  assert(*p != a[0]);
  assert(*p == a[1]);
}

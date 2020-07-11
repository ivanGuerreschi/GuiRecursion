#include "recursion.h"

int
perimeter (int n)
{
  if (n == 1)
    return 4;
  return 4 * n + perimeter (n - 1);
}

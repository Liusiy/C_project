#include <stdio.h>

int main()
{
  int *p;
  int q = 1;
  *p = 1;
  printf("p %x\n", p);
  printf("q %d\n", q);
  printf("*p %x\n", *p);
  if (p)
	printf("p %x \n", p);

  if (p != NULL)
	printf("p != NULL\n");
  
  return 0;
}

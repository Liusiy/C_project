#include <stdio.h>

int main()
{
  char *p = "hello world!";
  char *q = "BDCOM";
#ifdef BDCOM
  printf("%s \n", q);
#endif
  
#ifdef HELLO
  printf("%s \n", p);
#endif
  
  printf("Nothing\n");
  return 0;
}

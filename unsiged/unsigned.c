#include <stdio.h>

typedef unsigned char u_char;

int main()
{
  u_char unsigned_num = 0;
  if (unsigned_num > -1)
	printf("> -1\n");
  else
	printf("error !");

  return 0;
}

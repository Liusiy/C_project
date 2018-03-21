#include <stdio.h>

#define CACL_PROC_NOT_EXIST -1

#define SYS_OK 0
#define SYS_ERROR -1

typedef int (*funcP)(const int, const int);

/*define function*/
int add(const int arg1, const int arg2)
{
  return arg1 + arg2;
}

int sub(const int arg1, const int arg2)
{
  return arg1 - arg2;
}

int mul(const int arg1, const int arg2)
{
  return arg1 * arg2;
}

int div(const int arg1, const int arg2)
{
  return arg1 / arg2;
}

funcP cacl_func(const char symbol)
{
  switch(symbol)
	{
	case '+':
	  return add;
	case '-':
	  return sub;
	case '*':
	  return mul;
	case '/':
	  return div;
	default:
	  return NULL;
	}
}

funcP cacl_processor(const char symbol)
{
  funcP func_p;
  
  func_p = cacl_func(symbol);
  if (!func_p)
	return NULL;

  return func_p;
}

#define PRINT_OUTPUT \
  printf("%d %c %d = %d\n", arg1, symbol, arg2,arg_final )

int main()
{
  int arg1, arg2, arg_final;
  char symbol;
  funcP processor;
  printf("Please input arg1: ");
  scanf("%d", &arg1);
  printf("Please input arg2: ");
  scanf("%d", &arg2);
  printf("Please input symbol: ");
  scanf(" %c", &symbol); 
  /*scanf()采集字符，%c前面不加空格时，*/
  /*其作为输入的值始终为(int)10,即换行键*/
  /*
  scanf("%c", &symbol);
  printf(" %d\n", symbol);
  */
  processor = cacl_processor(symbol);
  if (NULL == processor)
	return CACL_PROC_NOT_EXIST;

  arg_final = processor(arg1, arg2);
  PRINT_OUTPUT;

  return SYS_OK;
}

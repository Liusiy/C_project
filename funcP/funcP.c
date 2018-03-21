#include <stdio.h>

#define CACL_NOT_EXIST -1

#define SYS_OK 0
#define SYS_ERROR -1

typedef int (*funcP)(int, int);

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

int cacl_processor_one(const int arg1, const int arg2, const char symbol)
{
  int arg_final;
  funcP func_p;
  
  func_p = cacl_func(symbol);
  if (!func_p)
	return CACL_NOT_EXIST;
  
  arg_final = cacl_func(symbol)(arg1, arg2);
  return arg_final;
}
int cacl_processor_two(const int arg1, const int arg2, const char symbol)
{
  int arg_final;
  funcP func_p;

  func_p = cacl_func(symbol);
  if (NULL == func_p)
	return CACL_NOT_EXIST;
  
  arg_final = func_p(arg1, arg2);
  return arg_final;
}

#define PRINT_OUTPUT \
  printf("%d %c %d = %d\n", arg1, symbol, arg2,arg_final )

int main()
{
  int arg1, arg2, arg_final;
  char symbol;
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
  
  arg_final = cacl_processor_one(arg1, arg2, symbol);
  PRINT_OUTPUT;
  arg_final = cacl_processor_two(arg1, arg2, symbol);
  PRINT_OUTPUT;

  return SYS_OK;
}

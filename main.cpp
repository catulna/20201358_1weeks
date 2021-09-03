#include <stdio.h>

int main(int argc, char* args[])
{
  int a = 0, b = 0;

  printf("두 개의 정수를 입력하세요. \n");
  scanf("%d %d", &a, &b);

  printf("두 수의 합: %d", a+b);
 
  return 0;
}